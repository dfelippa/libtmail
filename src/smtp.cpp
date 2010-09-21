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

#include "smtp.h"

namespace tmail
{

typedef enum _smtp_extract_state
{
	SMTP_BEGIN,
	SMTP_REPLY_CODE,
	SMTP_REPLY_LAST_LINE,
	SMTP_REPLY_MIDDLE_LINE,
	SMTP_REPLY_MIDDLE_LINE_END,
	SMTP_REPLY_END,
	SMTP_BAD_DATA,
	SMTP_BAD_DATA_END
} SmtpExtractState;

bool SmtpResponse::extract_from(tlib::BinaryData& data)
{
	const char* scan_begin = data.c_str();
	const char* start = scan_begin;
	const char* scan = start;
	const char* scan_end = scan + data.size();

	_code = 500;
	clear();
	_lines.clear();

	SmtpExtractState state = SMTP_BEGIN;
	std::string code;
	int ret_code = 0;
	std::string param;
	std::vector<std::string> params;
	while (scan < scan_end)
	{
		if (state == SMTP_BEGIN)
		{
			param.clear();
			code.clear();
			if (tlib::_isdigit(*scan))
			{
				state = SMTP_REPLY_CODE;
				code.push_back(*scan);
			}
			else if (tlib::_isspace(*scan))
			{
			}
			else
				state = SMTP_BAD_DATA;
		}
		else if (state == SMTP_REPLY_CODE)
		{
			if (tlib::_isdigit(*scan))
			{
				code.push_back(*scan);
				if (code.length() > 3)
				{
					code.clear();
					state = SMTP_BAD_DATA;
				}
			}
			else if (*scan == ' ' || *scan == '\t' || *scan == '\r')
			{
				ret_code = tlib::strto<int>(code);
				state = SMTP_REPLY_LAST_LINE;
			}
			else if (*scan == '-')
				state = SMTP_REPLY_MIDDLE_LINE;
			else if (*scan == '\n')
			{
				ret_code = tlib::strto<int>(code);
				state = SMTP_REPLY_END;
			}
			else
				state = SMTP_BAD_DATA;
		}
		else if (state == SMTP_REPLY_LAST_LINE)
		{
			 if (*scan == '\n')
			 {
				 params.push_back(param);
				 param.clear();
				 state = SMTP_REPLY_END;
			 }
			 else
				 param.push_back(*scan);
		}
		else if (state == SMTP_REPLY_MIDDLE_LINE)
		{
			 if (*scan == '\n')
			 {
				 params.push_back(param);
				 param.clear();
				 state = SMTP_REPLY_MIDDLE_LINE_END;
			 }
			 else
				 param.push_back(*scan);
		}
		else if (state == SMTP_REPLY_MIDDLE_LINE_END)
		{
			if (*scan == '\r' || *scan == '\n')
			{
			}
			else
			{
				state = SMTP_BEGIN;
				continue;
			}
		}
		else if (state == SMTP_REPLY_END)
		{
			if (*scan == '\r' || *scan == '\n')
			{
			}
			else
			{
				break;
			}
		}
		else if (state == SMTP_BAD_DATA)
		{
			if (*scan == '\r' || *scan == '\n')
				state = SMTP_BAD_DATA_END;
		}
		else if (state == SMTP_BAD_DATA_END)
		{
			if (*scan == '\r' || *scan == '\n')
			{
			}
			else
			{
				data.pop_front(scan - start);
				start = data.c_str();
				scan = start;
				scan_end = scan + data.size();
				state = SMTP_BEGIN;
				continue;
			}
		}
		scan++;
	}
	if (state == SMTP_REPLY_END)
	{
		tlib::BinaryData reply;
		data.pop_front(reply, scan - start);
		_code = ret_code;
		for (size_t i = 0; i < params.size(); i++)
		{
			_lines.push_back(tlib::trim(params[i]));
		}
		assign(reply);
		return true;
	}
	else
		return false;
}
SmtpResponse::operator bool() const
{
	return _code >= 200 && _code < 300;
}

#define DIALOG(x, y) if (!dialog((x), (y))) \
	return false

bool Smtp::connect(const std::string& host, unsigned short port, bool with_ssl)
{
	_error_id = 0;
	_error_message.clear();
	_starttls = false;
	_pipelining = false;
	_8bitmime = false;
	_max_size = 0;
	_auth_type.clear();

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

	SmtpResponse response(cmd_init);
	if (!receive_response(response))
	{
		disconnect();
		return false;
	}

	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		disconnect();
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}


bool Smtp::hello()
{
	SmtpResponse response(cmd_ehlo);
	DIALOG(SmtpRequest(cmd_ehlo, "EHLO " + tlib::get_host_name()), response);
	if (!response)
	{
		response.id = cmd_helo;
		DIALOG(SmtpRequest(cmd_helo, "HELO " + tlib::get_host_name()), response);
		if (!response)
		{
			_error_id = SMTP_ERR;
			_error_message = response;
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
		else
			return true;
	}
	else // ESMTP
	{
		// fetch the server information.
		_pipelining = false;
		_starttls = false;
		_8bitmime = false;
		_max_size = 0;
		_auth_type.clear();
		for (std::vector<std::string>::const_iterator it = response.get_lines().begin();
				it != response.get_lines().end(); it++)
		{
			std::vector<std::string> v = tlib::split<char>(*it, " ");
			for (std::vector<std::string>::iterator vit = v.begin();
					vit != v.end(); vit++)
			{
				tlib::to_upper(tlib::trim(*vit));
			}

			// Fetch the support authentication types.
			if (v[0] == "AUTH" && v.size() > 1)
			{
				_auth_type.insert(_auth_type.end(), v.begin() + 1, v.end());
			}
			else if (v[0].substr(0, 5) == "AUTH=")
			{
				if (v[0].length() > 5)
					_auth_type.push_back(v[0].substr(5, v[0].length() - 5));
				if (v.size() > 1)
					_auth_type.insert(_auth_type.end(), v.begin() + 1, v.end());
			}
			// Is there support STARTTLS.
			else if (v[0] == "STARTTLS")
			{
				_starttls = true;
			}
			else if (v[0] == "SIZE")
			{
				if (v.size() > 1)
					_max_size = tlib::strto<size_t>(v[1]);
			}
			else if (v[0] == "8BITMIME")
			{
				_8bitmime = true;
			}
			else if (v[0] == "PIPELINING")
			{
				_pipelining = true;
			}
		}
		return true;
	}
}

bool Smtp::verify(const std::string& name, Address& address)
{
	SmtpResponse response(cmd_vrfy);
	DIALOG(SmtpRequest(cmd_vrfy, "VRFY " + name), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	address = parse_address(response.get_lines()[0]);
	return true;
}

bool Smtp::expand(const std::string& mailing_list, Addresses& addresses)
{
	SmtpResponse response(cmd_expn);
	DIALOG(SmtpRequest(cmd_expn, "EXPN " + mailing_list), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	addresses.parse(tlib::join<char>(response.get_lines(), ","));
	return true;
}

bool Smtp::starttls()
{
	SmtpResponse response(cmd_starttls);
	DIALOG(SmtpRequest(cmd_starttls, "STARTTLS"), response);
	if (response)
	{
		return ssl_handshake(TLSv1);
	}
	else
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
}

bool Smtp::auth_login(const std::string& username, const std::string& password)
{
	SmtpResponse response(cmd_auth_login);
	DIALOG(SmtpRequest(cmd_auth_login, "AUTH LOGIN"), response);
	if (response.get_code() != 334)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	response.id = cmd_auth_login_username;
	DIALOG(SmtpRequest(cmd_auth_login_username, tlib::base64::encode(username)), response);
	if (response.get_code() != 334)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	response.id = cmd_auth_login_password;
	DIALOG(SmtpRequest(cmd_auth_login_password, tlib::base64::encode(password)), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}

bool Smtp::auth_plain(const std::string& username, const std::string& password)
{
	SmtpResponse response(cmd_auth_plain);
	std::string plain;
	plain.push_back('\0');
	plain.append(username);
	plain.push_back('\0');
	plain.append(password);
	DIALOG(SmtpRequest(cmd_auth_plain, "AUTH PLAIN " + tlib::base64::encode(plain)), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}

bool Smtp::auth_cram_md5(const std::string& username, const std::string& password)
{
	SmtpResponse response(cmd_auth_cram_md5);
	DIALOG(SmtpRequest(cmd_auth_cram_md5, "AUTH CRAM-MD5"), response);
	if (response.get_code() != 334)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	// Get the server auth-id.
	tlib::BinaryData authid;
	tlib::base64::decode(response.get_lines()[0], authid);

	// Make auth message as: username+<SPACE>+hmac_md5(auth-id, password)
	tlib::BinaryData digest = tlib::hash::hmac_md5(authid, password);
	std::string authmsg = username + " " + digest.hex_str(tlib::BinaryData::lower_case);

	// Send with base64 format.
	response.id = cmd_auth_cram_md5_data;
	DIALOG(SmtpRequest(cmd_auth_cram_md5_data, tlib::base64::encode(authmsg)), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Smtp::mail_from(const Address& address)
{
	SmtpResponse response(cmd_mail_from);
	DIALOG(SmtpRequest(cmd_mail_from, "MAIL FROM: " + address.get_mailbox().to_quoted_mailbox()),
			response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Smtp::rcpt_to(const Address& address)
{
	SmtpResponse response(cmd_rcpt_to);
	DIALOG(SmtpRequest(cmd_rcpt_to, "RCPT TO: " + address.get_mailbox().to_quoted_mailbox()),
			response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}

#define MAIL_FROM(x) if (!mail_from(x)) return false
#define RCPT_TO(x) if (!rcpt_to(x)) return false

bool Smtp::send_addresses_by_mail(const Mail& mail)
{
	// Send MAIL FROM.
	AddressHeaderPtr from_header = mail.get_from();
	AddressHeaderPtr sender_header = mail.get_sender();
	if (!from_header || from_header->get_addresses().size() == 0)
	{
		if (!sender_header || sender_header->get_addresses().size() == 0)
		{
			MAIL_FROM(parse_address(L""));
		}
		else
		{
			MAIL_FROM(sender_header->get_addresses()[0]);
		}
	}
	else if (from_header->get_addresses().size() == 1)
	{
		MAIL_FROM(from_header->get_addresses()[0]);
	}
	else // from_header->get_addresses().size() > 1
	{
		if (!sender_header || sender_header->get_addresses().size() == 0)
		{
			MAIL_FROM(from_header->get_addresses()[0]);
		}
		else
		{
			MAIL_FROM(sender_header->get_addresses()[0]);
		}
	}
	// Send RCPT TO.
	AddressHeaderPtr to_header = mail.get_to();
	if (to_header)
	{
		for (size_t i = 0; i < to_header->get_addresses().size(); i++)
			RCPT_TO(to_header->get_addresses()[i]);
	}
	AddressHeaderPtr cc_header = mail.get_cc();
	if (cc_header)
	{
		for (size_t i = 0; i < cc_header->get_addresses().size(); i++)
			RCPT_TO(cc_header->get_addresses()[i]);
	}
	AddressHeaderPtr bcc_header = mail.get_bcc();
	if (bcc_header)
	{
		for (size_t i = 0; i < bcc_header->get_addresses().size(); i++)
			RCPT_TO(bcc_header->get_addresses()[i]);
	}
	return true;
}

bool Smtp::send_mail(const Mail& mail)
{
	SmtpResponse response(cmd_data);
	DIALOG(SmtpRequest(cmd_data, "DATA"), response);
	if (response.get_code() != 354)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	response.id = cmd_data_content;
	std::string mail_data = mail.to_string(_8bitmime);
	tlib::replace<char>(mail_data, "\r\n.", "\r\n..");
	size_t data_size = mail_data.length();
	if (data_size >= 2)
	{
		if (mail_data[data_size - 2] == '\r' && mail_data[data_size - 1] == '\n')
		{
			mail_data += ".";
		}
		else
		{
			mail_data += "\r\n.";
		}
	}
	else
	{
		mail_data += "\r\n.";
	}

	DIALOG(SmtpRequest(cmd_data_content, mail_data),
			response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Smtp::reset()
{
	SmtpResponse response(cmd_rset);
	DIALOG(SmtpRequest(cmd_rset, "RSET"), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}
bool Smtp::quit()
{
	SmtpResponse response(cmd_quit);
	if (dialog(SmtpRequest(cmd_quit, "QUIT"), response))
	{
		if (!response)
		{
			_error_id = SMTP_ERR;
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
		return false;
	}
}

bool Smtp::noop()
{
	SmtpResponse response(cmd_noop);
	DIALOG(SmtpRequest(cmd_noop, "NOOP"), response);
	if (!response)
	{
		_error_id = SMTP_ERR;
		_error_message = response;
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}

}
