/*
 * pop3.h
 *
 *  Created on: 2010-7-14
 *      Author: thor
 */

#ifndef POP3_H_
#define POP3_H_

#include "config.h"
#include "protocol.h"
#include "mail.h"

namespace tmail
{

#define POP3_ERR			(0x3000)

class Pop3Request: public Request
{
public:
	inline Pop3Request(int id, const std::string& request);
};
inline Pop3Request::Pop3Request(int id, const std::string& request)
: Request(id, request + "\r\n")
{
}

// POP3 server normal reply message.
// +OK ...
// -ERR ...
class Pop3Response: public Response
{
public:
	inline Pop3Response(int id);
	virtual bool extract_from(tlib::BinaryData& data);
	inline operator bool() const;
	inline const std::string& get_info() const;
protected:
	bool _ok;
	std::string _info;
};
inline Pop3Response::Pop3Response(int id)
: Response(id), _ok(false)
{
}
inline Pop3Response::operator bool() const
{
	return _ok;
}
inline const std::string& Pop3Response::get_info() const
{
	return _info;
}

// Because the Pop3ContentResponse object extract data use a series of sequential state code.
// So, the Pop3ContentResponse object must not be reuse to extract server response.
// Except the latest call to the object 'extract_from' method returned 'true',
// That means the state of the object has been reset by the call.
class Pop3ContentResponse: public Pop3Response
{
public:
	inline Pop3ContentResponse(int id);
	virtual bool extract_from(tlib::BinaryData& data);
	inline const std::string get_content() const;
protected:
	int _extract_state;
	size_t _content_begin;
	size_t _content_end;
};
inline Pop3ContentResponse::Pop3ContentResponse(int id)
: Pop3Response(id), _extract_state(0), _content_begin(0), _content_end(0)
{
}
inline const std::string Pop3ContentResponse::get_content() const
{
	return std::string(begin() + _content_begin, begin() + _content_end);
}

class Pop3: public TcpConnection
{
public:
	typedef enum _pop3_command
	{
		_POP3_CMD_INIT = 0x200,
		_POP3_CMD_STAT,
		_POP3_CMD_LIST,
		_POP3_CMD_RETR,
		_POP3_CMD_DELE,
		_POP3_CMD_RSET,
		_POP3_CMD_CAPA,
		_POP3_CMD_APOP,
		_POP3_CMD_TOP,
		_POP3_CMD_UIDL,
		_POP3_CMD_AUTH_PLAIN,
		_POP3_CMD_AUTH_LOGIN,
		_POP3_CMD_AUTH_LOGIN_USERNAME,
		_POP3_CMD_AUTH_LOGIN_PASSWORD,
		_POP3_CMD_AUTH_CRAM_MD5,
		_POP3_CMD_AUTH_CRAM_MD5_DATA,
		_POP3_CMD_USER,
		_POP3_CMD_PASS,
		_POP3_CMD_STLS,
		_POP3_CMD_NOOP,
		_POP3_CMD_QUIT
	} Pop3CommandID;

	static const Pop3CommandID cmd_init = _POP3_CMD_INIT;
	static const Pop3CommandID cmd_stat = _POP3_CMD_STAT;
	static const Pop3CommandID cmd_list = _POP3_CMD_LIST;
	static const Pop3CommandID cmd_retr = _POP3_CMD_RETR;
	static const Pop3CommandID cmd_dele = _POP3_CMD_DELE;
	static const Pop3CommandID cmd_rset = _POP3_CMD_RSET;
	static const Pop3CommandID cmd_capa = _POP3_CMD_CAPA;
	static const Pop3CommandID cmd_apop = _POP3_CMD_APOP;
	static const Pop3CommandID cmd_top = _POP3_CMD_TOP;
	static const Pop3CommandID cmd_uidl = _POP3_CMD_UIDL;
	static const Pop3CommandID cmd_auth_plain = _POP3_CMD_AUTH_PLAIN;
	static const Pop3CommandID cmd_auth_login = _POP3_CMD_AUTH_LOGIN;
	static const Pop3CommandID cmd_auth_login_user = _POP3_CMD_AUTH_LOGIN_USERNAME;
	static const Pop3CommandID cmd_auth_login_pass = _POP3_CMD_AUTH_LOGIN_PASSWORD;
	static const Pop3CommandID cmd_auth_cram_md5 = _POP3_CMD_AUTH_CRAM_MD5;
	static const Pop3CommandID cmd_auth_cram_md5_data = _POP3_CMD_AUTH_CRAM_MD5_DATA;
	static const Pop3CommandID cmd_user = _POP3_CMD_USER;
	static const Pop3CommandID cmd_pass = _POP3_CMD_PASS;
	static const Pop3CommandID cmd_stls = _POP3_CMD_STLS;
	static const Pop3CommandID cmd_noop = _POP3_CMD_NOOP;
	static const Pop3CommandID cmd_quit = _POP3_CMD_QUIT;


	inline Pop3();

	inline bool connect(const std::string& host);
	bool connect(const std::string& host, unsigned short port, bool with_ssl = false);
	bool starttls();
	bool stat(int& mail_count, size_t& total_size);
	typedef std::vector<std::pair<int, size_t> > MailIndex;
	bool list(MailIndex& index);
	typedef std::vector<std::pair<int, std::string> > UidIndex;
	bool uidl(UidIndex& index);
	bool return_mail_header(int id, Mail& mail);
	bool return_mail(int id, Mail& mail);
	bool delete_mail(int id);
	bool capability();
	bool apop(const std::string& username, const std::string& password);
	bool user(const std::string& username);
	bool pass(const std::string& password);
	bool auth_login(const std::string& username, const std::string& password);
	bool auth_plain(const std::string& username, const std::string& password);
	bool auth_cram_md5(const std::string& username, const std::string& password);
	bool reset();
	bool noop();
	bool quit();

	inline bool is_enable_apop();
	inline bool is_enable_auth_login();
	inline bool is_enable_auth_plain();
	inline bool is_enable_auth_cram_md5();
	inline bool is_enable_user();
	inline bool is_enable_starttls();
private:
	std::string _apop_id;
	bool _auth_login;
	bool _auth_plain;
	bool _auth_cram_md5;
	bool _starttls;
	bool _user;
};

inline Pop3::Pop3()
: _auth_login(false), _auth_plain(false),
  _auth_cram_md5(false), _starttls(false)
{
}
inline bool Pop3::connect(const std::string& host)
{
	return connect(host, 110, false);
}
inline bool Pop3::is_enable_apop()
{
	return !_apop_id.empty();
}
inline bool Pop3::is_enable_auth_login()
{
	return _auth_login;
}
inline bool Pop3::is_enable_auth_plain()
{
	return _auth_plain;
}
inline bool Pop3::is_enable_auth_cram_md5()
{
	return _auth_cram_md5;
}
inline bool Pop3::is_enable_starttls()
{
	return _starttls;
}
inline bool Pop3::is_enable_user()
{
	return _user;
}


} // End of namespace

#endif /* POP3_H_ */
