#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include "config.h"

#include <string>
#include <ostream>
#include <vector>

#include "tlib/tlib.h"


namespace tmail
{

class Mailbox
{
public:
	inline Mailbox();
	inline Mailbox(const std::wstring& local, const std::wstring& domain);
	inline Mailbox(const Mailbox& mailbox);
	inline void set_local(const std::wstring& local);
	inline void set_domain(const std::wstring& domain);
	inline const std::wstring& get_local() const;
	inline const std::wstring& get_domain() const;
	const std::string to_string() const;
	const std::wstring to_wstring() const;
	const std::string to_quoted_mailbox() const;
	const std::wstring to_wquoted_mailbox() const;
	inline bool empty() const;
	inline void clear();
private:
	std::wstring _local;
	std::wstring _domain;
};

inline Mailbox::Mailbox()
{
}
inline Mailbox::Mailbox(const std::wstring& local, const std::wstring& domain)
: _local(local), _domain(domain)
{
}
inline Mailbox::Mailbox(const Mailbox& mailbox)
: _local(mailbox._local), _domain(mailbox._domain)
{
}
inline void Mailbox::set_local(const std::wstring& local)
{
	_local = local;
}
inline void Mailbox::set_domain(const std::wstring& domain)
{
	_domain = domain;
}
inline const std::wstring& Mailbox::get_local() const
{
	return _local;
}
inline const std::wstring& Mailbox::get_domain() const
{
	return _domain;
}
inline bool Mailbox::empty() const
{
	return _local.empty() || _domain.empty();
}
inline void Mailbox::clear()
{
	_local.clear();
	_domain.clear();
}


class Address
{
public:
	inline Address();
	inline Address(const Address& address);
	inline Address(const std::wstring& name, const Mailbox& mailbox);
public:
	inline const Mailbox& get_mailbox() const;
	inline void set_mailbox(const Mailbox& mailbox);

	inline const std::wstring& get_name() const;
	inline void set_name(const std::wstring& name);
	inline bool empty() const;

	const std::string to_string() const;
	const std::wstring to_wstring() const;
private:
	Mailbox _mailbox;
	std::wstring _name;
};

inline
Address::Address()
{
}
inline Address::Address(const Address& address)
: _mailbox(address._mailbox), _name(address._name)
{
}
inline
Address::Address(const std::wstring& name, const Mailbox& mailbox)
: _mailbox(mailbox), _name(name)
{
}


inline
const Mailbox& Address::get_mailbox() const
{
	return _mailbox;
}

inline 
void Address::set_mailbox(const Mailbox& mailbox)
{
	_mailbox = mailbox;
}

inline
const std::wstring& Address::get_name() const
{
	return _name;
}

inline
void Address::set_name(const std::wstring& name)
{
	_name = name;
}
inline
bool Address::empty() const
{
	return _name.empty() && _mailbox.empty();
}


class Addresses: public std::vector<Address>
{
public:
	void parse(const std::string& str);
	void parse(const std::wstring& str);
	const std::string to_string() const;
	const std::wstring to_wstring() const;
};

inline const Addresses parse_addresses(const std::string& mail_addr)
{
	Addresses addresses;
	addresses.parse(mail_addr);
	return addresses;
}

inline const Addresses parse_addresses(const std::wstring& mail_addr)
{
	Addresses addresses;
	addresses.parse(mail_addr);
	return addresses;
}

inline const Address parse_address(const std::string& mail_addr)
{
	Addresses addresses;
	addresses.parse(mail_addr);
	if (addresses.size() > 0)
		return addresses[0];
	else
		return Address();
}

inline const Address parse_address(const std::wstring& mail_addr)
{
	Addresses addresses;
	addresses.parse(mail_addr);
	if (addresses.size() > 0)
		return addresses[0];
	else
		return Address();
}

} // namespace


#endif
