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

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "config.h"
#include "tlib/tlib.h"
#ifdef WIN32
#include <winsock2.h>
#endif
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sigc++/sigc++.h>

#define CLIENT_TRANSMIT_TIMEOUT 120

namespace tmail
{

#define CLIENT_ERR						(0x1000L)
#define CLIENT_ERR_CONNECT 				(CLIENT_ERR + 1)
#define CLIENT_ERR_SSL_CONNECT			(CLIENT_ERR + 2)
#define CLIENT_ERR_TIMEOUT				(CLIENT_ERR + 3)
#define CLIENT_ERR_DISCONNECTED			(CLIENT_ERR + 4)
#define CLIENT_ERR_INVALID_PARAMETERS	(CLIENT_ERR + 5)
#define CLIENT_ERR_SSL_RECONNECT		(CLIENT_ERR + 6)

class Request : public tlib::BinaryData
{
public:
	inline Request();
	inline Request(const tlib::BinaryData& data);
	inline Request(int inst_id, const tlib::BinaryData& data);
	virtual ~Request() = 0;
	int id;
};
inline Request::Request()
: id(0)
{
}
inline Request::Request(const tlib::BinaryData& data)
: tlib::BinaryData(data), id(0)
{
}
inline Request::Request(int inst_id, const tlib::BinaryData& data)
: tlib::BinaryData(data), id(inst_id)
{
}

class Response : public tlib::BinaryData
{
public:
	inline Response();
	inline Response(int inst_id);
	virtual ~Response() = 0;
	virtual bool extract_from(tlib::BinaryData& data) = 0;
	int id;
};
inline Response::Response()
: id(0)
{
}
inline Response::Response(int inst_id)
: id(inst_id)
{
}

class TcpConnection
{
public:
	typedef enum _ssl_connect_type
	{
		_S_SSLv23 = 0,
		_S_TLSv1
	} SSLCipher;
	static const SSLCipher SSLv23 = _S_SSLv23;
	static const SSLCipher TLSv1 = _S_TLSv1;
	TcpConnection();
	virtual ~TcpConnection();
	bool connect(const std::string& host, unsigned short port);
	bool ssl_handshake(SSLCipher cipher);
	void disconnect();
	inline bool is_connected() const;
	inline bool is_ssl_connected() const;
	inline long get_last_error() const;
	inline const std::string& get_last_error_message() const;
	inline void set_timeout(time_t timeout);
	bool send_request(const Request& request);
	bool receive_response(Response& response);
	bool dialog(const Request& request, Response& response);

	// Report transmit completeness.
	// void func(size_t size, bool& cancel_and_disconnect);
	//	   error_id: indicated whether a message is an error report.
	//     message: any type message may emit by client.
	typedef sigc::signal<void, size_t, const Request&, bool&> SendingReportSignal;
	typedef sigc::signal<void, size_t, const Response&, bool&> ReceivingReportSignal;

	// Report message.
	// void func(int error_id, const std::string& message);
	//	   error_id: indicated whether a message is an error report.
	//     message: any type message may emit by client.
	typedef sigc::signal<void, int, const std::string&> ErrorSignal;

	// Report data transmit.
	// void func(const Request& request);
	typedef sigc::signal<void, const Request&> DataSentSignal;

	// Report data transmit.
	// void func(const Response& response);
	typedef sigc::signal<void, const Response&> DataReceivedSignal;

	inline ErrorSignal& signal_error();
	inline SendingReportSignal& signal_sending_report();
	inline ReceivingReportSignal& signal_receiving_report();
	inline DataSentSignal& signal_sent();
	inline DataReceivedSignal& signal_received();

protected:
	time_t _timeout;
	long _error_id;
	std::string _error_message;
	ErrorSignal _signal_error;
	DataSentSignal _signal_sent;
	DataReceivedSignal _signal_received;
	SendingReportSignal _signal_sending_report;
	ReceivingReportSignal _signal_receiving_report;

private:
	BIO* _bio;
	SSL_CTX* _ctx;
	SSL* _ssl;
//	tlib::BinaryData _send_data;
	tlib::BinaryData _receive_data;
};

inline bool TcpConnection::is_connected() const
{
	return (_bio != 0);
}
inline bool TcpConnection::is_ssl_connected() const
{
	return (_ssl != 0);
}
inline long TcpConnection::get_last_error() const
{
	return _error_id;
}
inline const std::string& TcpConnection::get_last_error_message() const
{
	return _error_message;
}
inline TcpConnection::ErrorSignal& TcpConnection::signal_error()
{
	return _signal_error;
}
inline TcpConnection::SendingReportSignal& TcpConnection::signal_sending_report()
{
	return _signal_sending_report;
}
inline TcpConnection::ReceivingReportSignal& TcpConnection::signal_receiving_report()
{
	return _signal_receiving_report;
}
inline TcpConnection::DataSentSignal& TcpConnection::signal_sent()
{
	return _signal_sent;
}
inline TcpConnection::DataReceivedSignal& TcpConnection::signal_received()
{
	return _signal_received;
}
inline void TcpConnection::set_timeout(time_t timeout)
{
	_timeout = timeout;
}


} // End name space


#endif /* PROTOCOL_H_ */
