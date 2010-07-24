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

#include "code.h"
#include "tlib/tlib.h"

namespace tmail
{

typedef enum _content_parse_state
{
	SM_BEGIN = 0,
	SM_EQ,
	SM_Q1,
	SM_CHARSET,
	SM_Q2,
	SM_ENCODE,
	SM_Q3,
	SM_CONTENT,
	SM_Q4,
	SM_END
}
ContentParseState;




size_t get_wchar_utf8_length(wchar_t ch)
{
	static size_t utf8_size_table[32] = {
		1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
		3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6
	};
	size_t bit = 0;
	while (ch > 0)
	{
		ch >>= 1;
		bit++;
	}
	return utf8_size_table[bit];
}

bool is_ascii_printable_string(const std::wstring& src)
{
	for (std::wstring::const_iterator cit = src.begin(); cit != src.end(); cit++)
	{
		if (!tlib::_isprint(*cit))
			return false;
	}
	return true;
}

bool is_ascii_printable_string(const std::string& src)
{
	for (std::string::const_iterator cit = src.begin(); cit != src.end(); cit++)
	{
		if (!tlib::_isprint(*cit))
			return false;
	}
	return true;
}


// `content` must already encoded with `charset`.
const std::string encode_base64(const char* content, size_t len, const std::string& charset, bool column_limited)
{
	std::string base64_field;
	tlib::base64::encode(content, len, base64_field, column_limited);
	return (std::string("=?") + charset + "?B?" + base64_field + "?=");
}

// `content` must already encoded with `charset`.
const std::string encode_qprint(const char* content, size_t len, const std::string& charset, bool column_limited)
{
	std::string qprint_field;
	tlib::qprint::encode(content, len, qprint_field, column_limited);
	return (std::string("=?") + charset + "?Q?" + qprint_field + "?=");
}


const std::wstring decode_base64(const char* content, size_t len, const std::string& charset)
{
	tlib::BinaryData bin;
	tlib::base64::decode(content, len, bin);

	unsigned int codepage = tlib::convert_charset_to_codepage(charset.c_str());
	if (codepage == 65001) // utf-8 encode.
	{
		return tlib::utf8_to_wstring(bin);
	}
#ifdef WIN32
	else if (codepage == 1200)
	{
		return std::wstring((wchar_t*)bin.c_str(), bin.size() / sizeof(wchar_t));
	}
#endif
	else
	{
		return tlib::charset_to_wstring(bin, charset);
	}
}

const std::wstring decode_qprint(const char* content, size_t len, const std::string& charset)
{
	tlib::BinaryData bin;
	tlib::qprint::decode(content, len, bin);

	unsigned int codepage = tlib::convert_charset_to_codepage(charset.c_str());
	if (codepage == 65001) // utf-8 encode.
	{
		return tlib::utf8_to_wstring(bin);
	}
#ifdef WIN32
	else if (codepage == 1200)
	{
		return std::wstring((wchar_t*)bin.c_str(), bin.size() / sizeof(wchar_t));
	}
#endif
	else
	{
		return tlib::charset_to_wstring(bin, charset);
	}
}

const std::wstring decode_header_field(const std::string& src)
{
	char encode = 0;
	std::string charset;
	const char* content_begin = 0;
	unsigned int content_len = 0;
	std::wstring result;

	ContentParseState state = SM_BEGIN;
	const char* scan = src.c_str();
	const char* begin = scan;
	bool last_content_is_encode = false;
	while (*scan != '\0')
	{
		if (state == SM_BEGIN)
		{
			if (*scan == '=')
			{
				if (scan > begin)
				{
					for (const char* tmp = begin; tmp != scan; tmp++)
					{
						if (!isspace(*tmp))
						{
							last_content_is_encode = false;
							break;
						}
					}
					result.append(tlib::locale_to_wstring(std::string(begin, scan - begin)));
					begin = scan;
				}
				state = SM_EQ;
			}
		}
		else if (state == SM_EQ)
		{
			if (*scan == '?')
			{
				state = SM_CHARSET;
				charset.clear();
			}
			else
			{
				state = SM_BEGIN;
			}
		}
		else if (state == SM_CHARSET)
		{
			if (*scan == '?')
			{
				state = SM_Q2;
			}
			else if (isgraph(*scan))
			{
				charset.push_back(*scan);
			}
			else
			{
				state = SM_BEGIN;
			}
		}
		else if (state == SM_Q2)
		{
			if (*scan == 'b' || *scan == 'B' || *scan == 'q' || *scan == 'Q')
			{
				encode = *scan;
				state = SM_ENCODE;
			}
			else
			{
				state = SM_BEGIN;
			}
		}
		else if (state == SM_ENCODE)
		{
			if (*scan == '?')
			{
				state = SM_CONTENT;
				content_begin = scan + 1;
				content_len = 0;
			}
			else
			{
				state = SM_BEGIN;
			}
		}
		else if (state == SM_CONTENT)
		{
			if (*scan == '?')
			{
				state = SM_Q4;
			}
			else
			{
				content_len++;
			}
		}
		else if (state == SM_Q4)
		{
			if (*scan == '=')
			{
				if (last_content_is_encode)
				{
					tlib::trim_right(result);
				}
				begin = scan + 1;
				state = SM_BEGIN;
				tlib::to_lower(tlib::trim(charset));
				if (encode == 'b' || encode == 'B')
				{
					result += decode_base64(content_begin, content_len, charset);
				}
				else
				{
					result += decode_qprint(content_begin, content_len, charset);
				}
				last_content_is_encode = true;

			}
			else
			{
				state = SM_BEGIN;
			}
		}
		scan++;
	}
	if (scan > begin)
	{
		result.append(tlib::locale_to_wstring(std::string(begin, scan - begin)));
	}
	return result;
}

} // namespace

