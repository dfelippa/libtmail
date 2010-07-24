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

#include "protocol.h"
#ifdef WIN32
#include <winsock2.h>
#elif defined __linux
#include <sys/socket.h>
#endif

#ifdef TCP_DEBUG
#include <iostream>
#endif

namespace tmail
{

Request::~Request()
{
}

Response::~Response()
{
}

TcpConnection::TcpConnection()
: _timeout(CLIENT_TRANSMIT_TIMEOUT), _error_id(0), _bio(0), _ctx(0), _ssl(0)
{
	SSL_library_init();
	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();
}
TcpConnection::~TcpConnection()
{
	disconnect();
}



bool TcpConnection::connect(const std::string& host, unsigned short port)
{
	if (_bio)
		disconnect();

	std::string remote = host + ":" + tlib::strfrom<unsigned short>(port);
	_bio = BIO_new(BIO_s_connect());
	if (!_bio)
	{
		_error_id = CLIENT_ERR_CONNECT;
		_error_message = "Connect error: ";
		if (ERR_get_error())
			_error_message += ERR_reason_error_string(ERR_get_error());
		else
			_error_message += "BIO_s_connect() failed.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	BIO_set_conn_hostname(_bio, remote.c_str());
	// Using non-blocking IO..
	BIO_set_nbio(_bio, 1);
	while (BIO_do_connect(_bio) <= 0)
	{
		if (BIO_should_retry(_bio))
		{
			int fd = 0;
			BIO_get_fd(_bio, &fd);
			timeval tm;
			tm.tv_usec = 0;
#ifdef WIN32
			tm.tv_sec = (long)30;
#else
			tm.tv_sec = _timeout;
#endif
			fd_set	writefds;
			FD_ZERO(&writefds);
			FD_SET(fd, &writefds);

			fd_set errfds;
			FD_ZERO(&errfds);
			FD_SET(fd, &errfds);

			int ret = select(fd + 1, 0, &writefds, &errfds, &tm);
			if (ret <= 0)
			{
				_error_id = CLIENT_ERR_CONNECT;
				_error_message = "Connect error: can not connect to server.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else if (FD_ISSET(fd, &errfds))
			{
				_error_id = CLIENT_ERR_CONNECT;
				_error_message = "Connect error: can not connect to server.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
		}
		else
		{
			_error_id = CLIENT_ERR_CONNECT;
			_error_message = "Connect error: ";
			if (ERR_get_error())
				_error_message += ERR_reason_error_string(ERR_get_error());
			else
				_error_message += "BIO_do_connect() failed.";
			disconnect();
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
	}

	int fd = 0;
	BIO_get_fd(_bio, &fd);
	// Enable linger option.
	struct linger linger;
	linger.l_onoff = 1;
	linger.l_linger = 10;
#ifdef WIN32
	setsockopt(fd, SOL_SOCKET, SO_LINGER, (const char*)&linger, sizeof(linger));
#else
	setsockopt(fd, SOL_SOCKET, SO_LINGER, &linger, sizeof(linger));
#endif

	// Enable keep alive.
	int val = 1;
#ifdef WIN32
	setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (const char*)&val, sizeof(int));
#else
	setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(int));
#endif

	return true;
}
bool TcpConnection::ssl_handshake(SSLCipher cipher)
{
	if (!_bio)
	{
		_error_id = CLIENT_ERR_DISCONNECTED;
		_error_message = "Handshake error: should do tcp connect first.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	int fd = 0;
	BIO_get_fd(_bio, &fd);

	if (_ssl)
	{
		_error_id = CLIENT_ERR_SSL_RECONNECT;
		_error_message = "Handshake error: SSL connection already established.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}

	// Chose what method to use.
	if (cipher == SSLv23)
		_ctx = SSL_CTX_new(SSLv23_client_method());
	else if (cipher == TLSv1)
		_ctx = SSL_CTX_new(TLSv1_method());
	else
	{
		_error_id = CLIENT_ERR_INVALID_PARAMETERS;
		_error_message = "Handshake error: unknown SSL cipher type.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}

	if (!_ctx)
	{
		_error_id = CLIENT_ERR_SSL_CONNECT;
		_error_message = "Handshake error: ";
		if (ERR_reason_error_string(ERR_get_error()))
			_error_message += ERR_reason_error_string(ERR_get_error());
		else
			_error_message += "SSL_CTX_new() failed.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	SSL_CTX_set_mode(_ctx, SSL_MODE_ENABLE_PARTIAL_WRITE |
			SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER);
	_ssl = SSL_new(_ctx);
	if (!_ssl)
	{
		_error_id = CLIENT_ERR_SSL_CONNECT;
		_error_message = "Handshake error: ";
		if (ERR_reason_error_string(ERR_get_error()))
			_error_message += ERR_reason_error_string(ERR_get_error());
		else
			_error_message += "SSL_new() failed.";
		disconnect();
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	SSL_set_bio(_ssl, _bio, _bio);
	SSL_set_mode(_ssl, SSL_MODE_AUTO_RETRY);
	int ret = 0;
retry_ssl_connect:
	if ((ret = SSL_connect(_ssl)) != 1)
	{
		ret = SSL_get_error(_ssl, ret);
		if (ret == SSL_ERROR_WANT_READ)
		{
			timeval tm;
			tm.tv_usec = 0;
#ifdef WIN32
			tm.tv_sec = (long)_timeout;
#else
			tm.tv_sec = _timeout;
#endif

			fd_set	readfds;
			FD_ZERO(&readfds);
			FD_SET(fd, &readfds);

			int ret = select(fd + 1, &readfds, 0, 0, &tm);
			if (ret < 0 )
			{
				// error
				_error_id = CLIENT_ERR_DISCONNECTED;
				_error_message = "Handshake error: connection closed.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else if (ret == 0)
			{
				_error_id = CLIENT_ERR_TIMEOUT;
				_error_message = "Handshake error: timeout.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else
			{
				goto retry_ssl_connect;
			}
		}
		else if (ret == SSL_ERROR_WANT_WRITE)
		{
			timeval tm;
			tm.tv_usec = 0;
#ifdef WIN32
			tm.tv_sec = (long)_timeout;
#else
			tm.tv_sec = _timeout;
#endif
			fd_set	writefds;
			FD_ZERO(&writefds);
			FD_SET(fd, &writefds);

			int ret = select(fd + 1, 0, &writefds, 0, &tm);
			if (ret < 0 )
			{
				// error
				_error_id = CLIENT_ERR_DISCONNECTED;
				_error_message = "Handshake error: connection closed.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else if (ret == 0)
			{
				_error_id = CLIENT_ERR_TIMEOUT;
				_error_message = "Handshake error: timeout.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else
			{
				goto retry_ssl_connect;
			}
		}
		_error_id = CLIENT_ERR_SSL_CONNECT;
		_error_message = "Handshake error: " + tlib::strfrom<int>(ret);
		disconnect();
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	return true;
}

void TcpConnection::disconnect()
{
	if (_ssl)
	{
		SSL_shutdown(_ssl);
		SSL_free(_ssl);
		_ssl = 0;
		_bio = 0;
		if (_ctx)
		{
			SSL_CTX_free(_ctx);
			_ctx = 0;
		}
	}
	else if (_bio)
	{
		BIO_free_all(_bio);
		_bio = 0;
	}
}

bool TcpConnection::send_request(const Request& request)
{
	int fd = 0;
	if (!_bio)
	{
		_error_id = CLIENT_ERR_DISCONNECTED;
		_error_message = "Send error: should connect first.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	BIO_get_fd(_bio, &fd);
//	request.push_back_to(_send_data);
	size_t sent_size = 0;
	while (request.size() - sent_size > 0)
	{
		timeval tm;
		tm.tv_usec = 0;
#ifdef WIN32
		tm.tv_sec = (long)_timeout;
#else
		tm.tv_sec = _timeout;
#endif
		fd_set	writefds;
		FD_ZERO(&writefds);
		FD_SET(fd, &writefds);

		int ret = select(fd + 1, 0, &writefds, 0, &tm);
		if (ret < 0 )
		{
			// error
			_error_id = CLIENT_ERR_DISCONNECTED;
			_error_message = "Send error: connection closed.";
			disconnect();
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
		else if (ret == 0)
		{
			_error_id = CLIENT_ERR_TIMEOUT;
			_error_message = "Send error: send data timeout.";
			disconnect();
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
		else
		{
			// if (FD_ISSET(fd, writefds))
			if (_ssl)
			{
				ret = SSL_write(_ssl, request.c_str() + sent_size,
						(int)(request.size() - sent_size));
			}
			else
			{
				ret = BIO_write(_bio, request.c_str() + sent_size,
						(int)(request.size() - sent_size));
			}
			if (ret < 0)
			{
				if (_ssl)
				{
					if (SSL_get_error(_ssl, ret) == SSL_ERROR_WANT_WRITE ||
						SSL_get_error(_ssl, ret) == SSL_ERROR_WANT_READ)
						continue;
					else
					{
						_error_id = CLIENT_ERR_DISCONNECTED;
						_error_message = "Send error: SSL connection closed(" +
								tlib::strfrom(SSL_get_error(_ssl, ret)) + ").";
						disconnect();
						_signal_error.emit(_error_id, _error_message);
						return false;
					}
				}
				else
				{
					_error_id = CLIENT_ERR_DISCONNECTED;
					_error_message = "Send error: ";
					if (ERR_reason_error_string(ERR_get_error()))
						_error_message += ERR_reason_error_string(ERR_get_error());
					else
						_error_message += "BIO_write() failed.";
					disconnect();
					_signal_error.emit(_error_id, _error_message);
					return false;
				}
			}
			else if (ret == 0)
			{
				_error_id = CLIENT_ERR_DISCONNECTED;
				_error_message = "Send error: connection closed.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else
			{
				sent_size += ret;
//				_send_data.pop_front(ret);
				bool cancel_and_quit = false;
				_signal_sending_report.emit(sent_size, request, cancel_and_quit);
				if (cancel_and_quit)
				{
					_error_id = CLIENT_ERR_DISCONNECTED;
					_error_message = "Send error: transmission is cancelled.";
					disconnect();
					_signal_error.emit(_error_id, _error_message);
					return false;
				}
			}
		}
	}
	_signal_sent.emit(request);
	return true;
}

bool TcpConnection::receive_response(Response& response)
{
	int fd = 0;
	if (!_bio)
	{
		_error_id = CLIENT_ERR_DISCONNECTED;
		_error_message = "Receive error: should connect first.";
		_signal_error.emit(_error_id, _error_message);
		return false;
	}
	BIO_get_fd(_bio, &fd);
	while (!response.extract_from(_receive_data))
	{
		timeval tm;
		tm.tv_usec = 0;
#ifdef WIN32
		tm.tv_sec = (long)_timeout;
#else
		tm.tv_sec = _timeout;
#endif
		fd_set	readfds;
		FD_ZERO(&readfds);
		FD_SET(fd, &readfds);

		int ret = select(fd + 1, &readfds, 0, 0, &tm);
		if (ret < 0 )
		{
			_error_id = CLIENT_ERR_DISCONNECTED;
			_error_message = "Receive error: connection closed.";
			disconnect();
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
		else if (ret == 0)
		{
			_error_id = CLIENT_ERR_TIMEOUT;
			_error_message = "Receive error: receive data timeout.";
			disconnect();
			_signal_error.emit(_error_id, _error_message);
			return false;
		}
		else
		{
			char buffer[4096];
			if (_ssl)
				ret = SSL_read(_ssl, &(buffer[0]), 4096);
			else
				ret = BIO_read(_bio, &(buffer[0]), 4096);
			if (ret < 0)
			{
				if (_ssl)
				{
					if (SSL_get_error(_ssl, ret) == SSL_ERROR_WANT_WRITE ||
						SSL_get_error(_ssl, ret) == SSL_ERROR_WANT_READ)
						continue;
					else
					{
						_error_id = CLIENT_ERR_DISCONNECTED;
						_error_message = "Receive error: SSL connection closed(" +
								tlib::strfrom(SSL_get_error(_ssl, ret)) + ").";
						disconnect();
						_signal_error.emit(_error_id, _error_message);
						return false;
					}
				}
				else
				{
					_error_id = CLIENT_ERR_DISCONNECTED;
					_error_message = "Receive error: ";
					if (ERR_reason_error_string(ERR_get_error()))
						_error_message += ERR_reason_error_string(ERR_get_error());
					else
						_error_message += "BIO_read() failed.";
					disconnect();
					_signal_error.emit(_error_id, _error_message);
					return false;
				}
			}
			else if (ret == 0)
			{
				_error_id = CLIENT_ERR_DISCONNECTED;
				_error_message = "Receive error: connection closed.";
				disconnect();
				_signal_error.emit(_error_id, _error_message);
				return false;
			}
			else
			{
				_receive_data.append(&(buffer[0]), &(buffer[0]) + ret);
				bool cancel_and_quit = false;
				_signal_receiving_report.emit(_receive_data.size(), response, cancel_and_quit);
				if (cancel_and_quit)
				{
					_error_id = CLIENT_ERR_DISCONNECTED;
					_error_message = "Receive error: transmission is cancelled.";
					disconnect();
					_signal_error.emit(_error_id, _error_message);
					return false;
				}
			}
		}
	}
	_signal_received.emit(response);
	return true;
}

bool TcpConnection::dialog(const Request& request, Response& response)
{
	if (!send_request(request))
		return false;
	return receive_response(response);
}





} // End of namespace.


