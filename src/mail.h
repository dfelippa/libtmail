/*
 * mail.h
 *
 *  Created on: 2010-6-26
 *      Author: thor
 */

#ifndef MAIL_H_
#define MAIL_H_

#include "config.h"
#include "content.h"

namespace tmail
{

class Mail: public Content
{
public:
	const IdHeaderPtr get_message_id() const;
	const AddressHeaderPtr get_from() const;
	const AddressHeaderPtr get_sender() const;
	const AddressHeaderPtr get_to() const;
	const AddressHeaderPtr get_cc() const;
	const AddressHeaderPtr get_bcc() const;
	const DatetimeHeaderPtr get_date() const;
	const TextHeaderPtr get_subject() const;

	void set_from(const std::wstring& addrs);
	void set_sender(const std::wstring& addr);
	void set_to(const std::wstring& addrs);
	void set_cc(const std::wstring& addrs);
	void set_bcc(const std::wstring& addrs);
	void set_date(const tlib::Time& time);
	void set_subject(const std::wstring& subject);

};

typedef tlib::RefPtr<Mail> MailPtr;




} // End of namespace



#endif /* MAIL_H_ */
