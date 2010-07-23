/*
 * Header.cpp
 *
 *  Created on: 2010-6-16
 *      Author: thor
 */

#include "header.h"
#include "code.h"

namespace tmail
{

Header::~Header()
{
}
const std::string Header::get_format_name() const
{
	std::string name = tlib::wstring_to_locale(_name);
	const char* scan = name.c_str();
	const char* scan_end = scan + name.length();
	int state = 0;
	std::string result;
	while (scan < scan_end)
	{
		if (state == 0)
		{
			if (*scan == '-')
			{
				result.push_back('-');
			}
			else
			{
				result.push_back(toupper(*scan));
				state = 1;
			}
		}
		else
		{
			if (*scan == '-')
			{
				result.push_back('-');
				state = 0;
			}
			else
			{
				result.push_back(*scan);
			}
		}
		scan++;
	}
	return result;
}



void TextHeader::parse_value(const std::string& value)
{
	parse_value(decode_header_field(value));
}
void TextHeader::parse_value(const std::wstring& value)
{
	if (_structured)
	{
		std::wstring tmp;
		int state = 0;
		const wchar_t* scan = value.c_str();
		const wchar_t* scan_end = scan + value.length();
		while (scan < scan_end)
		{
			if (state == 0)
			{
				if (tlib::_isspace(*scan))
				{					
				}
				else
				{
					tmp.push_back(*scan);
					state = 1;
				}
			}
			else if (state == 1)
			{
				if (tlib::_isspace(*scan))
				{
					tmp.push_back(' ');
					state = 0;
				}
				else
				{
					tmp.push_back(*scan);
				}
			}
			scan++;
		}
		_value = tlib::trim_right_copy(tmp);
	}
	else
	{
		_value = value;
		tlib::trim(_value);
	}
}


const std::string TextHeader::to_strnig() const
{
	std::string result;
	result = get_format_name() + ": ";
	size_t column = result.length();
	if (is_ascii_printable_string(_value))
	{
		std::wstring tmp;
		const wchar_t* scan = _value.c_str();
		const wchar_t* scan_end = scan + _value.length();
		while (scan < scan_end)
		{
			if (column >= 70 && *scan == ' ')
			{
				result.push_back('\r');
				result.push_back('\n');
				if (_structured)
				{
					result += "        ";
					column = 8;
				}
				else
				{
					result.push_back(' ');
					column = 1;
				}
			}
			else
			{
				if (_structured && (wcsncmp(scan, L"; ", 2) == 0) && column > 30)
				{
					result.push_back((char)*scan);
					result.push_back('\r');
					result.push_back('\n');
					result += "        ";
					column = 8;
					scan++;
				}
				else
				{
					result.push_back((char)*scan);
					column++;
				}
			}
			scan++;
		}
	}
	else
	{
		size_t part = 0;
		const wchar_t* scan = _value.c_str();
		const wchar_t* scan_end = scan + _value.length();
		while (scan < scan_end)
		{
			if (part > 0)
			{
				result += "\r\n ";
				column = 1;
			}

			size_t utf8_len = 0;
			const wchar_t* size_scan = scan;
			while (size_scan < scan_end)
			{
				utf8_len += get_wchar_utf8_length(*size_scan);
				if (get_utf8_base64_length(utf8_len) + column < 76)
					size_scan++;
				else
					break;
			}

			result += encode_base64(std::wstring(scan, size_scan - scan));
			scan = size_scan;
			part++;
		}
	}
	return result;
}
const std::wstring TextHeader::get_value() const
{
	return _value;
}
Header::HeaderType TextHeader::get_header_type() const
{
	return Header::string;
}


void IdHeader::parse_value(const std::string& value)
{
	parse_value(decode_header_field(value));
}
void IdHeader::parse_value(const std::wstring& value)
{
	std::wstring tmp(value);
	tlib::trim(tmp);
	if (!tmp.empty())
	{
		if (*tmp.begin() == '<')
			tmp.erase(tmp.begin());
		if (!tmp.empty())
		{
			if (*(tmp.end() - 1) == '>')
				tmp.erase(tmp.end() - 1);
			_id = tlib::trim(tmp);
		}
		else
			_id.clear();
	}
	else
		_id.clear();
}
const std::string IdHeader::to_strnig() const
{
	std::string result;
	result = get_format_name() + ": ";
	result.push_back('<');
	result += tlib::wstring_to_locale(_id);
	result.push_back('>');
	return result;
}
const std::wstring IdHeader::get_value() const
{
	return _id;
}
Header::HeaderType IdHeader::get_header_type() const
{
	return Header::id;
}
void IdHeader::generate_id(const std::wstring& domain)
{
	static size_t count = 1;
	wchar_t buf[300];
	tlib::Time t;
	srand((unsigned int)t._tm);
	swprintf(buf, 300, L"%04X.%06X.%08X@%ls",
		count++,
		0x100000 + rand() % 0xFFFFFF,
		t._tm,
		domain.c_str()
		);
	_id = buf;
}




void AddressHeader::parse_value(const std::string& value)
{
	parse_value(decode_header_field(value));
}
void AddressHeader::parse_value(const std::wstring& value)
{
	_addresses.parse(value);
}
const std::string AddressHeader::to_strnig() const
{
	std::string result;
	result = get_format_name() + ": ";
	size_t column = result.length();
	for (Addresses::const_iterator it = _addresses.begin(); it != _addresses.end(); it++)
	{
		std::string tmp = it->to_string();
		if (it != _addresses.begin() && !tmp.empty())
		{
			result.push_back(',');
			column++;
			if (column + tmp.length() > 74)
			{
				result += "\r\n        ";
				column = 8;
			}
			else
			{
				result.push_back(' ');
				column++;
			}
		}
		result += tmp;
		column += tmp.length();
	}
	return result;
}
const std::wstring AddressHeader::get_value() const
{
	return _addresses.to_wstring();
}
Header::HeaderType AddressHeader::get_header_type() const
{
	return Header::address;
}






void DatetimeHeader::parse_value(const std::string& value)
{
	_time.parse(value, _time.format_mail);
}
void DatetimeHeader::parse_value(const std::wstring& value)
{
	parse_value(tlib::wstring_to_locale(value));
}
const std::string DatetimeHeader::to_strnig() const
{
	return get_format_name() + ": " + _time.to_string(_time.format_mail);
}
const std::wstring DatetimeHeader::get_value() const
{
	return tlib::locale_to_wstring(_time.to_string(_time.format_mail));
}
Header::HeaderType DatetimeHeader::get_header_type() const
{
	return Header::datetime;
}







const std::string Parameter::to_string() const
{
	std::string result;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]) && !isalnum(name[i]) && name[i] != L'-' && name[i] != L'_')
			return "";
	}
	tlib::wstring_to_locale(name, result);
	result += "=\"";
	if (!is_ascii_printable_string(value))
		result += encode_base64(value);
	else
		result += tlib::wstring_to_utf8(tlib::replace_copy(value, L"\"", L"\\\""));
	result.push_back('"');
	return result;
}
const std::wstring Parameter::to_wstring() const
{
	std::wstring result;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]) && !isalnum(name[i]) && name[i] != L'-' && name[i] != L'_')
			return L"";
	}
	result = name;
	result += L"=\"";
	result += tlib::replace_copy(value, L"\"", L"\\\"");
	result.push_back(L'"');
	return result;
}

const std::string Parameters::to_string() const
{
	std::string result;
	size_t column = 1;
	for (size_t i = 0; i < _parameters.size(); i++)
	{
		std::string tmp = _parameters[i].to_string();
		if (!result.empty() && !tmp.empty())
		{
			result.push_back(';');
			column++;
			if (column + tmp.length() > 74)
			{
				result += "\r\n        ";
				column = 1;
			}
			else
			{
				result.push_back(' ');
				column++;
			}

		}
		result += tmp;
		column += tmp.length();
	}
	return result;
}

const std::wstring Parameters::to_wstring() const
{
	std::wstring result;
	for (size_t i = 0; i < _parameters.size(); i++)
	{
		std::wstring tmp = _parameters[i].to_wstring();
		if (!result.empty() && !tmp.empty())
		{
			result.push_back(';');
		}
		result += tmp;
	}
	return result;
}




void ContentHeader::parse_value(const std::string& value)
{
	parse_value(decode_header_field(value));
}
void ContentHeader::parse_value(const std::wstring& value)
{
	const wchar_t* scan = value.c_str();
	const wchar_t* scan_end = scan + value.length();
	int state = 0;
	std::wstring para_name;
	std::wstring para_value;
	_major_value.clear();
	_parameters.clear();
	int quote = 0;
	while (scan < scan_end)
	{
		if (state == 0)
		{
			if (tlib::_isspace(*scan))
			{
			}
			else if (*scan == ';')
			{
				state = 3;
			}
			else if (tlib::_isgraph(*scan))
			{
				_major_value.push_back(*scan);
				state = 1;
			}
			else
				break;
		}
		else if (state == 1)
		{
			if (tlib::_isspace(*scan))
			{
				state = 2;
			}
			else if (*scan == ';')
			{
				state = 3;
			}
			else if (tlib::_isgraph(*scan))
			{
				_major_value.push_back(*scan);
			}
			else
			{
				break;
			}
		}
		else if (state == 2)
		{
			if (tlib::_isspace(*scan))
			{
			}
			else if (*scan == ';')
			{
				state = 3;
			}
			else
			{
				break;
			}
		}
		else if (state == 3) // Parse parameter name
		{
			if (tlib::_isspace(*scan) || *scan == ';')
			{
			}
			else if (tlib::_isalnum(*scan) || *scan == '_')
			{
				para_name.push_back(*scan);
				state = 4;
			}
			else
			{
				break;
			}
		}
		else if (state == 4) // Parameter name
		{
			if (tlib::_isspace(*scan))
			{
				state = 5;
			}
			else if (*scan == '=')
			{
				state = 6;
			}
			else if (tlib::_isalnum(*scan) || *scan == '_' || *scan == '.' || *scan == '-')
			{
				para_name.push_back(*scan);
			}
			else
			{
				break;
			}
		}
		else if (state == 5) // Parameter name end
		{
			if (tlib::_isspace(*scan))
			{
			}
			else if (*scan == '=')
			{
				state = 6;
			}
			else
			{
				break;
			}
		}
		else if (state == 6) // Parameter value
		{
			if (tlib::_isspace(*scan))
			{
			}
			else if (*scan == '"') // Quoted string
			{
				quote = 2;
				state = 7;
			}
			else if (*scan == '\'')
			{
				quote = 1;
				state = 7;
			}
			else
			{
				para_value.push_back(*scan);
				quote = 0;
				state = 7;
			}
		}
		else if (state == 7)
		{
			if ((*scan == '"' && quote == 2) || (*scan == '\'' && quote == 1))
			{
				_parameters.add(para_name, para_value);
				para_name.clear();
				para_value.clear();
				state = 3;
			}
			else if (*scan == ';' && quote == 0)
			{
				_parameters.add(para_name, para_value);
				para_name.clear();
				para_value.clear();
				state = 3;
			}
			else if (*scan == '\\' && quote != 0)
			{
				state = 8;
			}
			else
			{
				para_value.push_back(*scan);
			}
		}
		else if (state == 8)
		{
			para_value.push_back(*scan);
			state = 7;
		}
		scan++;
	}
	if (state == 6 || state == 7 || state == 8)
	{
		_parameters.add(para_name, para_value);
		para_name.clear();
		para_value.clear();
	}
}
const std::string ContentHeader::to_strnig() const
{
	std::string result = get_format_name() + ": ";
	std::string param = _parameters.to_string();
	result += tlib::wstring_to_locale(_major_value);
	if (!param.empty())
	{
		result += ";\r\n        ";
		result += param;
	}
	return result;
}
const std::wstring ContentHeader::get_value() const
{
	std::wstring result;
	std::wstring param = _parameters.to_wstring();
	result = _major_value;
	if (!param.empty())
	{
		result += L";";
		result += param;
	}
	return result;
}
Header::HeaderType ContentHeader::get_header_type() const
{
	return Header::content;
}
const std::wstring ContentHeader::get_parameter(const std::wstring& name) const
{
	for (size_t i = 0; i < _parameters.count(); i++)
	{
		if (_parameters[i].name == name)
			return _parameters[i].value;
	}
	return L"";
}
void ContentHeader::set_parameter(const std::wstring& name, const std::wstring& value)
{
	for (size_t i = 0; i < _parameters.count(); i++)
	{
		if (_parameters[i].name == name)
		{
			_parameters[i].value = value;
			return;
		}
	}
	_parameters.add(name, value);
}



} // End of namespace..
