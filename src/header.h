/*
 * Header.h
 *
 *  Created on: 2010-6-16
 *      Author: thor
 */

#ifndef HEADER_H_
#define HEADER_H_

#include "config.h"

#include "tlib/tlib.h"
#include "address.h"

namespace tmail
{


class Header : public tlib::Object
{
public:
	inline Header(const std::wstring& name);
	virtual ~Header() = 0;
	typedef enum _header_type
	{
		header_string,
		header_address,
		header_datetime,
		header_content,
		header_id
	} HeaderType;
	static const HeaderType string = header_string;
	static const HeaderType address = header_address;
	static const HeaderType datetime = header_datetime;
	static const HeaderType content = header_content;
	static const HeaderType id = header_id;
public:
	inline const std::wstring& get_name() const;
	inline const bool get_structured() const;
	const std::string get_format_name() const;

	virtual const std::string to_strnig() const = 0;
	virtual HeaderType get_header_type() const = 0;
	virtual void parse_value(const std::string& value) = 0;
	virtual void parse_value(const std::wstring& value) = 0;
	virtual const std::wstring get_value() const = 0;
protected:
	inline void set_name(const std::wstring& name);
	std::wstring _name;
	bool _structured;
};
typedef tlib::RefPtr<Header> HeaderPtr;
typedef std::vector<HeaderPtr> Headers;

inline Header::Header(const std::wstring& name)
: _structured(false)
{
	set_name(name);
}
inline const std::wstring& Header::get_name() const
{
	return _name;
}
inline void Header::set_name(const std::wstring& name)
{
	 _name = name;
	 tlib::trim(_name);
	 tlib::to_lower(_name);
}
inline const bool Header::get_structured() const
{
	return _structured;
}







class TextHeader : public Header
{
public:
	inline TextHeader(const std::wstring& name);
	inline TextHeader(const std::wstring& name, const std::wstring& value);

	virtual void parse_value(const std::string& value);
	virtual void parse_value(const std::wstring& value);
	virtual const std::string to_strnig() const;
	virtual const std::wstring get_value() const;
	virtual HeaderType get_header_type() const;

	inline void set_value(const std::wstring& value);
	inline void set_structured(bool is_structured);
private:
	std::wstring _value;
};
typedef tlib::RefPtr<TextHeader> TextHeaderPtr;



inline TextHeader::TextHeader(const std::wstring& name)
: Header(name)
{
}

inline TextHeader::TextHeader(const std::wstring& name, const std::wstring& value)
: Header(name), _value(value)
{
}
inline void TextHeader::set_value(const std::wstring& value)
{
	_value = value;
}
inline void TextHeader::set_structured(bool is_structured)
{
	_structured = is_structured;
}



class IdHeader : public Header
{
public:
	inline IdHeader(const std::wstring& name);

	virtual void parse_value(const std::string& value);
	virtual void parse_value(const std::wstring& value);
	virtual const std::string to_strnig() const;
	virtual const std::wstring get_value() const;
	virtual HeaderType get_header_type() const;

	inline const std::wstring& get_id() const;
	void generate_id(const std::wstring& domain);
private:
	std::wstring _id;
};
typedef tlib::RefPtr<IdHeader> IdHeaderPtr;

inline IdHeader::IdHeader(const std::wstring& name)
: Header(name)
{
	_structured = true;
}
inline const std::wstring& IdHeader::get_id() const
{
	return _id;
}





class AddressHeader: public Header
{
public:
	inline AddressHeader(const std::wstring& name);

	virtual void parse_value(const std::string& value);
	virtual void parse_value(const std::wstring& value);
	virtual const std::string to_strnig() const;
	virtual const std::wstring get_value() const;
	virtual HeaderType get_header_type() const;

	inline Addresses& get_addresses();
	inline const Addresses& get_addresses() const;
private:
	Addresses _addresses;
};
typedef tlib::RefPtr<AddressHeader> AddressHeaderPtr;

inline AddressHeader::AddressHeader(const std::wstring& name)
: Header(name)
{
	_structured = true;
}
inline Addresses& AddressHeader::get_addresses()
{
	return _addresses;
}
inline const Addresses& AddressHeader::get_addresses() const
{
	return _addresses;
}





class DatetimeHeader: public Header
{
public:
	inline DatetimeHeader(const std::wstring& name);
	inline DatetimeHeader(const std::wstring& name, const tlib::Time& time);

	virtual void parse_value(const std::string& value);
	virtual void parse_value(const std::wstring& value);
	virtual const std::string to_strnig() const;
	virtual const std::wstring get_value() const;
	virtual HeaderType get_header_type() const;

	inline void set_time(const tlib::Time& tm);
	inline const tlib::Time& get_time() const;
private:
	tlib::Time _time;
};
typedef tlib::RefPtr<DatetimeHeader> DatetimeHeaderPtr;

inline DatetimeHeader::DatetimeHeader(const std::wstring& name)
: Header(name)
{
	_structured = true;
}
inline DatetimeHeader::DatetimeHeader(const std::wstring& name, const tlib::Time& time)
: Header(name), _time(time)
{
	_structured = true;
}
inline void DatetimeHeader::set_time(const tlib::Time& tm)
{
	_time = tm;
}
inline const tlib::Time& DatetimeHeader::get_time() const
{
	return _time;
}






class Parameter
{
public:
	inline Parameter(const std::wstring& n, const std::wstring& v);
	const std::string to_string() const;
	const std::wstring to_wstring() const;
	std::wstring name;
	std::wstring value;
};
inline Parameter::Parameter(const std::wstring& n, const std::wstring& v)
: name(n), value(v)
{
	tlib::trim(name);
	tlib::to_lower(name);
}




class Parameters
{
public:
	inline void add(const std::wstring& name, const std::wstring& value);
	inline size_t count() const;
	inline void erase(size_t n);
	inline Parameter& operator [] (size_t n);
	inline const Parameter& operator [] (size_t n) const;
	inline void clear();
	const std::string to_string() const;
	const std::wstring to_wstring() const;
private:
	std::vector<Parameter> _parameters;
};

inline void Parameters::add(const std::wstring& name, const std::wstring& value)
{
	if (name.empty())
		return;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]) && !isalnum(name[i]) && name[i] != '-' && name[i] != '_')
			return;
	}
	_parameters.push_back(Parameter(name, value));
}
inline size_t Parameters::count() const
{
	return _parameters.size();
}
inline void Parameters::erase(size_t n)
{
	_parameters.erase(_parameters.begin() + n);
}
inline Parameter& Parameters::operator [] (size_t n)
{
	return _parameters.at(n);
}
inline const Parameter& Parameters::operator [] (size_t n) const
{
	return _parameters.at(n);
}
inline void Parameters::clear()
{
	_parameters.clear();
}




class ContentHeader: public Header
{
public:
	inline ContentHeader(const std::wstring& name);

	virtual void parse_value(const std::string& value);
	virtual void parse_value(const std::wstring& value);
	virtual const std::string to_strnig() const;
	virtual const std::wstring get_value() const;
	virtual HeaderType get_header_type() const;

	inline void set_major(const std::wstring& type);
	inline const std::wstring& get_major() const;
	inline Parameters& get_parameters();
	inline const Parameters& get_parameters() const;

	const std::wstring get_parameter(const std::wstring& name) const;
	void set_parameter(const std::wstring& name, const std::wstring& value);
private:
	std::wstring _major_value;
	Parameters _parameters;
};

typedef tlib::RefPtr<ContentHeader> ContentHeaderPtr;


inline ContentHeader::ContentHeader(const std::wstring& name)
: Header(name)
{
	_structured = true;
}
inline void ContentHeader::set_major(const std::wstring& value)
{
	_major_value = value;
	tlib::trim(_major_value);
	tlib::to_lower(_major_value);
}
inline const std::wstring& ContentHeader::get_major() const
{
	return _major_value;
}
inline Parameters& ContentHeader::get_parameters()
{
	return _parameters;
}
inline const Parameters& ContentHeader::get_parameters() const
{
	return _parameters;
}

} // End namespace..

#endif /* HEADER_H_ */
