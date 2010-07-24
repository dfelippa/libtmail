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

#ifndef SMTP_H_
#define SMTP_H_

#include "config.h"
#include "protocol.h"
#include "mail.h"

namespace tmail
{

#define SMTP_ERR			(0x2000)

class SmtpRequest: public Request
{
public:
	inline SmtpRequest(int id, const std::string& request);
};
inline SmtpRequest::SmtpRequest(int id, const std::string& request)
: Request(id, request + "\r\n")
{
}


// SMTP server reply message.
class SmtpResponse: public Response
{
public:
	inline SmtpResponse(int id);
	virtual bool extract_from(tlib::BinaryData& data);
	operator bool() const;
	inline int get_code() const;
	inline const std::vector<std::string>& get_lines() const;
private:
	int _code;
	std::vector<std::string> _lines;
};

inline SmtpResponse::SmtpResponse(int id)
: Response(id), _code(500)
{
}
inline int SmtpResponse::get_code() const
{
	return _code;
}
inline const std::vector<std::string>& SmtpResponse::get_lines() const
{
	return _lines;
}


class Smtp: public TcpConnection
{
public:
	typedef enum _smtp_command
	{
		_SMTP_CMD_INIT = 0x100,
		_SMTP_CMD_HELO,
		_SMTP_CMD_EHLO,
		_SMTP_CMD_RSET,
		_SMTP_CMD_AUTH_LOGIN,
		_SMTP_CMD_AUTH_LOGIN_USERNAME,
		_SMTP_CMD_AUTH_LOGIN_PASSWORD,
		_SMTP_CMD_AUTH_PLAIN,
		_SMTP_CMD_AUTH_CRAM_MD5,
		_SMTP_CMD_AUTH_CRAM_MD5_DATA,
		_SMTP_CMD_VRFY,
		_SMTP_CMD_EXPN,
		_SMTP_CMD_STARTTLS,
		_SMTP_CMD_MAIL_FROM,
		_SMTP_CMD_RCPT_TO,
		_SMTP_CMD_DATA,
		_SMTP_CMD_DATA_CONTENT,
		_SMTP_CMD_NOOP,
		_SMTP_CMD_QUIT
	} SmtpCommandID;

	static const SmtpCommandID cmd_init = _SMTP_CMD_INIT;
	static const SmtpCommandID cmd_helo = _SMTP_CMD_HELO;
	static const SmtpCommandID cmd_ehlo = _SMTP_CMD_EHLO;
	static const SmtpCommandID cmd_rset = _SMTP_CMD_RSET;
	static const SmtpCommandID cmd_auth_login = _SMTP_CMD_AUTH_LOGIN;
	static const SmtpCommandID cmd_auth_login_username = _SMTP_CMD_AUTH_LOGIN_USERNAME;
	static const SmtpCommandID cmd_auth_login_password = _SMTP_CMD_AUTH_LOGIN_PASSWORD;
	static const SmtpCommandID cmd_auth_plain = _SMTP_CMD_AUTH_PLAIN;
	static const SmtpCommandID cmd_auth_cram_md5 = _SMTP_CMD_AUTH_CRAM_MD5;
	static const SmtpCommandID cmd_auth_cram_md5_data = _SMTP_CMD_AUTH_CRAM_MD5_DATA;
	static const SmtpCommandID cmd_vrfy = _SMTP_CMD_VRFY;
	static const SmtpCommandID cmd_expn = _SMTP_CMD_EXPN;
	static const SmtpCommandID cmd_starttls = _SMTP_CMD_STARTTLS;
	static const SmtpCommandID cmd_mail_from = _SMTP_CMD_MAIL_FROM;
	static const SmtpCommandID cmd_rcpt_to = _SMTP_CMD_RCPT_TO;
	static const SmtpCommandID cmd_data = _SMTP_CMD_DATA;
	static const SmtpCommandID cmd_data_content = _SMTP_CMD_DATA_CONTENT;
	static const SmtpCommandID cmd_noop = _SMTP_CMD_NOOP;
	static const SmtpCommandID cmd_quit = _SMTP_CMD_QUIT;

	inline Smtp();

	inline bool connect(const std::string& host);
	bool connect(const std::string& host, unsigned short port, bool with_ssl = false);
	bool hello();
	bool verify(const std::string& name, Address& address);
	bool expand(const std::string& mailing_list, Addresses& addresses);
	bool starttls();
	bool auth_login(const std::string& username, const std::string& password);
	bool auth_plain(const std::string& username, const std::string& password);
	bool auth_cram_md5(const std::string& username, const std::string& password);
	bool mail_from(const Address& address);
	bool rcpt_to(const Address& address);
	bool send_addresses_by_mail(const Mail& mail);
	bool send_mail(const Mail& mail);
	bool reset();
	bool noop();
	bool quit();

	inline const std::vector<std::string>& get_auth_type() const;
	inline bool is_enable_starttls() const;
	inline bool is_enable_pipelining() const;
	inline bool is_enable_8bitmime() const;
	inline size_t get_max_mail_size() const;
private:
	std::vector<std::string>  _auth_type;
	bool _starttls;
	bool _pipelining;
	bool _8bitmime;
	size_t _max_size;
};

inline Smtp::Smtp()
: _starttls(false), _pipelining(false), _8bitmime(false), _max_size(0)
{
}
inline bool Smtp::connect(const std::string& host)
{
	return connect(host, 25, false);
}
inline bool Smtp::is_enable_starttls() const
{
	return _starttls;
}
inline bool Smtp::is_enable_pipelining() const
{
	return _pipelining;
}
inline bool Smtp::is_enable_8bitmime() const
{
	return _8bitmime;
}
inline const std::vector<std::string>& Smtp::get_auth_type() const
{
	return _auth_type;
}
inline size_t Smtp::get_max_mail_size() const
{
	return _max_size;
}

}

#endif /* SMTP_H_ */
