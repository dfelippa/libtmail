/************************************************************************
*
*  LibTMail
*  Copyright (C) 2010  Thor Qin
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* Author: Thor Qin
* Bug Report: thor.qin@gmail.com
*
**************************************************************************/

#include "pop3.h"

#include <iostream>

namespace tmail
{


bool Pop3Response::extract_from(tlib::BinaryData& data)
{
	size_t end_pos = data.find("\r\n", 0);
	if (end_pos != data.npos)
	{
		data.pop_front(*this, end_pos + 2);
		if (tlib::to_upper_copy(substr(0, 3)) == "+OK")
		{
			_info = substr(3, end_pos - 3);
			tlib::trim(_info);
			_ok = true;
			return true;
		}
		else if (*begin() == '+')
		{
			_info = substr(1, end_pos - 1);
			tlib::trim(_info);
			_ok = true;
			return true;
		}
		else if (tlib::to_upper_copy(substr(0, 4)) == "-ERR")
		{
			_info = substr(4, end_pos - 4);
			tlib::trim(_info);
			_ok = false;
			return true;
		}
		else
		{
			_info.clear();
			clear();
			return false;
		}
	}
	else
		return false;
}
bool Pop3ContentResponse::extract_from(tlib::BinaryData& data)
{
	if (_extract_state == 0)
	{
		if (!Pop3Response::extract_from(data))
			return false;
		if (!_ok)
		{
			_extract_state = 0;
			return true;
		}
		else
		{
			_content_begin = size();
			_content_end = _content_begin;
			_extract_state = 3;
		}
	}

	const char* start = data.c_str();
	const char* scan = start;
	const char* scan_end = scan + data.length();
	while (scan < scan_end)
	{
		if (_extract_state == 1)
		{
			if (*scan == '\r')
				_extract_state = 2;
		}
		else if (_extract_state == 2)
		{
			if (*scan == '\n')
				_extract_state = 3;
			else if (*scan == '\r')
				_extract_state = 2;
			else
				_extract_state = 1;
		}
		else if (_extract_state == 3)
		{
			if (*scan == '.')
				_extract_state = 4;
			else if (*scan == '\r')
				_extract_state = 2;
			else
				_extract_state = 1;
		}
		else if (_extract_state == 4)
		{
			if (*scan == '\r')
				_extract_state = 5;
			else if (*scan == '\r')
				_extract_state = 2;
			else
				_extract_state = 1;
		}
		else if (_extract_state == 5)
		{
			if (*scan == '\n')
				_extract_state = 6;
			else if (*scan == '\r')
				_extract_state = 2;
			else
				_extract_state = 1;
		}
		else
		{
			break;
		}
		scan++;
	}

	if (_extract_state == 6)
	{
		_content_end += (scan_end - start) - 3;
		append(data.begin(), data.begin() + (scan_end - start));
		data.pop_front(scan_end - start);
		_extract_state = 0;
		return true;
	}
	else
	{
		_content_end += data.size();
		append(data.begin(), data.end());
		data.pop_front(data.size());
		return false;
	}
}

void get_apop_id(const std::string& msg, std::string& apop_id)
{
	const char* scan = msg.c_str();
	const char* scan_end = scan + msg.length();
	int state = 0;
	while (scan < scan_end)
	{
		if (state == 0)
		{
			if (*scan == '<')
			{
				apop_id.push_back(*scan);
				state = 1;
			}
		}
		else if (state == 1)
		{
			if (*scan == '>')
			{
				state = 2;
			}
			apop_id.push_back(*scan);
		}
		scan++;
	}
	if (state != 2)
	{
		apop_id.clear();
	}
}

#define DIALOG(x, y) if (!dialog((x), (y))) \
	return false

bool Pop3::connect(const std::string& host, unsigned short port, bool with_ssl)
{
	_error_id = 0;
	_error_message.clear();
	_starttls = false;
	_apop_id.clear();
	_auth_login = false;
	_auth_plain = false;
	_auth_cram_md5 = false;
	_user = false;
	if (!TcpConnection::connect(host, port))
		return false;

	if (with_ssl)
	{
		if (!ssl_handshake(SSLv23))
		{
			disconnect();
			return false;
		}
	}

	Pop3Response response(cmd_init);
	if (!receive_response(response))
	{
		disconnect();
		return false;
	}

	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		disconnect();
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	// Is that enable APOP ?
	get_apop_id(_error_message, _apop_id);
	return true;
}

bool Pop3::starttls()
{
	Pop3Response response(cmd_stls);
	DIALOG(Pop3Request(cmd_stls, "STLS"), response);
	if (response)
	{
		return ssl_handshake(TLSv1);
	}
	else
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
}

bool Pop3::stat(int& mail_count, size_t& total_size)
{
	Pop3Response response(cmd_stat);
	DIALOG(Pop3Request(cmd_stat, "STAT"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	std::vector<std::string> v = tlib::split<char>(response.get_info(), " ");
	if (v.size() != 2)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	mail_count = tlib::strto<int>(v[0]);
	total_size = tlib::strto<size_t>(v[1]);
	return true;
}

bool Pop3::list(MailIndex& index)
{
	Pop3ContentResponse response(cmd_list);
	DIALOG(Pop3Request(cmd_list, "LIST"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	index.clear();
	std::vector<std::string> v = tlib::split<char>(response.get_content(), "\n");
	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::vector<std::string> item = tlib::split<char>(*it, " ");
		int id = tlib::strto<int>(item[0]);
		size_t size = tlib::strto<size_t>(item[1]);
		index.push_back(std::pair<int, size_t>(id, size));
	}
	return true;
}

bool Pop3::uidl(UidIndex& index)
{
	Pop3ContentResponse response(cmd_uidl);
	DIALOG(Pop3Request(cmd_uidl, "UIDL"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	index.clear();
	std::vector<std::string> v = tlib::split<char>(response.get_content(), "\n");
	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::vector<std::string> item = tlib::split<char>(*it, " ");
		int id = tlib::strto<int>(item[0]);
		std::string uid = tlib::trim(item[1]);
		index.push_back(std::pair<int, std::string>(id, uid));
	}
	return true;
}

bool Pop3::return_mail_header(int id, Mail& mail)
{
	Pop3ContentResponse response(cmd_top);
	DIALOG(Pop3Request(cmd_top, "TOP " + tlib::strfrom<int>(id) + " 0"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	std::string content = response.get_content();
	mail.parse(content.c_str(), content.length(), true);
	return true;
}

bool Pop3::return_mail(int id, Mail& mail)
{
	Pop3ContentResponse response(cmd_retr);
	DIALOG(Pop3Request(cmd_retr, "RETR " + tlib::strfrom<int>(id)), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	std::string content = response.get_content();
	tlib::replace<char>(content, "\r\n.", "\r\n");
	mail.parse(content.c_str(), content.length());
	return true;
}

bool Pop3::delete_mail(int id)
{
	Pop3Response response(cmd_dele);
	DIALOG(Pop3Request(cmd_dele, "DELE " + tlib::strfrom<int>(id)), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::capability()
{
	Pop3ContentResponse response(cmd_capa);
	DIALOG(Pop3Request(cmd_capa, "CAPA"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	std::vector<std::string> v = tlib::split<char>(response.get_content(), "\n");
	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::vector<std::string> item = tlib::split<char>(*it, " ");
		for (size_t i = 0; i < item.size(); i++)
		{
			tlib::to_upper(tlib::trim(item[i]));
			if (item[i] == "STLS")
				_starttls = true;
			else if (item[i] == "LOGIN")
				_auth_login = true;
			else if (item[i] == "PLAIN")
				_auth_plain = true;
			else if (item[i] == "CRAM-MD5")
				_auth_cram_md5 = true;
			else if (item[i] == "USER")
				_user = true;
		}
	}
	return true;
}
bool Pop3::apop(const std::string& username, const std::string& password)
{
	Pop3Response response(cmd_apop);
	DIALOG(Pop3Request(cmd_apop, "APOP " + username + " " +
			tlib::hash::md5(_apop_id + password).hex_str(tlib::BinaryData::lower_case)),
			response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::user(const std::string& username)
{
	Pop3Response response(cmd_user);
	DIALOG(Pop3Request(cmd_user, "USER " + username), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;

}
bool Pop3::pass(const std::string& password)
{
	Pop3Response response(cmd_pass);
	DIALOG(Pop3Request(cmd_pass, "PASS " + password), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::auth_login(const std::string& username, const std::string& password)
{
	Pop3Response response(cmd_auth_login);
	DIALOG(Pop3Request(cmd_auth_login, "AUTH LOGIN"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	response.id = cmd_auth_login_user;
	DIALOG(Pop3Request(cmd_auth_login_user, tlib::base64::encode(username)), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	response.id = cmd_auth_login_pass;
	DIALOG(Pop3Request(cmd_auth_login_pass, tlib::base64::encode(password)), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::auth_plain(const std::string& username, const std::string& password)
{
	Pop3Response response(cmd_auth_plain);
	std::string plain;
	plain.push_back('\0');
	plain.append(username);
	plain.push_back('\0');
	plain.append(password);
	DIALOG(Pop3Request(cmd_auth_plain, "AUTH PLAIN " + tlib::base64::encode(plain)), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::auth_cram_md5(const std::string& username, const std::string& password)
{
	Pop3Response response(cmd_auth_cram_md5);
	DIALOG(Pop3Request(cmd_auth_cram_md5, "AUTH CRAM-MD5"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	// Get the server auth-id.
	tlib::BinaryData authid;
	tlib::base64::decode(response.get_info(), authid);

	// Make auth message as: username+<SPACE>+hmac_md5(auth-id, password)
	tlib::BinaryData digest = tlib::hash::hmac_md5(authid, password);
	std::string authmsg = username + " " + digest.hex_str(tlib::BinaryData::lower_case);

	// Send with base64 format.
	response.id = cmd_auth_cram_md5_data;
	DIALOG(Pop3Request(cmd_auth_cram_md5_data, tlib::base64::encode(authmsg)), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::reset()
{
	Pop3Response response(cmd_rset);
	DIALOG(Pop3Request(cmd_rset, "RSET"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::noop()
{
	Pop3Response response(cmd_noop);
	DIALOG(Pop3Request(cmd_noop, "NOOP"), response);
	if (!response)
	{
		_error_id = POP3_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Pop3::quit()
{
	Pop3Response response(cmd_quit);
	if (dialog(Pop3Request(cmd_quit, "QUIT"), response))
	{
		if (!response)
		{
			_error_id = POP3_ERR;
			_error_message = response;
			disconnect();
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
		else
		{
			disconnect();
			return true;
		}
	}
	else
	{
		disconnect();
		return true;
	}
}


} // End of namespace
