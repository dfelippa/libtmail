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

#include "mail.h"
#include "code.h"

namespace tmail
{

const IdHeaderPtr Mail::get_message_id() const
{
	HeaderPtr hd = headers.get_header(L"message-id");
	if (hd)
		return IdHeaderPtr::cast_dynamic(hd);
	else
		return IdHeaderPtr(0);

}
const AddressHeaderPtr Mail::get_from() const
{
	HeaderPtr hd = headers.get_header(L"from");
	if (hd)
		return AddressHeaderPtr::cast_dynamic(hd);
	else
		return AddressHeaderPtr(0);
}
const AddressHeaderPtr Mail::get_sender() const
{
	HeaderPtr hd = headers.get_header(L"sender");
	if (hd)
		return AddressHeaderPtr::cast_dynamic(hd);
	else
		return AddressHeaderPtr(0);
}
const AddressHeaderPtr Mail::get_to() const
{
	HeaderPtr hd = headers.get_header(L"to");
	if (hd)
		return AddressHeaderPtr::cast_dynamic(hd);
	else
		return AddressHeaderPtr(0);
}
const AddressHeaderPtr Mail::get_cc() const
{
	HeaderPtr hd = headers.get_header(L"cc");
	if (hd)
		return AddressHeaderPtr::cast_dynamic(hd);
	else
		return AddressHeaderPtr(0);
}
const AddressHeaderPtr Mail::get_bcc() const
{
	HeaderPtr hd = headers.get_header(L"bcc");
	if (hd)
		return AddressHeaderPtr::cast_dynamic(hd);
	else
		return AddressHeaderPtr(0);
}
const DatetimeHeaderPtr Mail::get_date() const
{
	HeaderPtr hd = headers.get_header(L"date");
	if (hd)
		return DatetimeHeaderPtr::cast_dynamic(hd);
	else
		return DatetimeHeaderPtr(0);
}
const TextHeaderPtr Mail::get_subject() const
{
	HeaderPtr hd = headers.get_header(L"subject");
	if (hd)
		return TextHeaderPtr::cast_dynamic(hd);
	else
		return TextHeaderPtr(0);
}
void Mail::set_from(const std::wstring& addrs)
{
	AddressHeaderPtr hd = get_from();
	if (!hd)
	{
		AddressHeaderPtr new_hd(new AddressHeader(L"from"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->parse_value(addrs);
}
void Mail::set_sender(const std::wstring& addr)
{
	AddressHeaderPtr hd = get_sender();
	if (!hd)
	{
		AddressHeaderPtr new_hd(new AddressHeader(L"sender"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->parse_value(addr);
	Addresses& addresses = hd->get_addresses();
	if (addresses.size() > 1)
		addresses.erase(addresses.begin() + 1, addresses.end());
}
void Mail::set_to(const std::wstring& addrs)
{
	AddressHeaderPtr hd = get_to();
	if (!hd)
	{
		AddressHeaderPtr new_hd(new AddressHeader(L"to"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->parse_value(addrs);
}
void Mail::set_cc(const std::wstring& addrs)
{
	AddressHeaderPtr hd = get_cc();
	if (!hd)
	{
		AddressHeaderPtr new_hd(new AddressHeader(L"cc"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->parse_value(addrs);
}
void Mail::set_bcc(const std::wstring& addrs)
{
	AddressHeaderPtr hd = get_bcc();
	if (!hd)
	{
		AddressHeaderPtr new_hd(new AddressHeader(L"bcc"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->parse_value(addrs);
}
void Mail::set_subject(const std::wstring& subject)
{
	TextHeaderPtr hd = get_subject();
	if (!hd)
	{
		TextHeaderPtr new_hd(new TextHeader(L"subject"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->parse_value(subject);
}
void Mail::set_date(const tlib::Time& time)
{
	DatetimeHeaderPtr hd = get_date();
	if (!hd)
	{
		DatetimeHeaderPtr new_hd(new DatetimeHeader(L"date"));
		headers.add(new_hd);
		hd = new_hd;
	}
	hd->set_time(time);
}


} // End of namespace

