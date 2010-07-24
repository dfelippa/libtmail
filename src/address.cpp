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

#include "address.h"
#include "tlib/tlib.h"
#include "code.h"


namespace tmail
{

const std::string Mailbox::to_string() const
{
	static const wchar_t* spec_char = L" \t\v\r\n\f<>()[]\\/@,;:";
	if (_local.empty() || _domain.empty())
		return "";

	std::string result;

	if (!is_ascii_printable_string(_local))
	{
		result += encode_base64(_local);
	}
	else
	{
		if (tlib::char_exist(_local, spec_char))
		{
			std::wstring tmp(_local);
			tlib::replace(tmp, L"\"", L"\\\"");
			result += ("\"" + tlib::wstring_to_utf8(tmp) + "\"");
		}
		else
			result += tlib::wstring_to_utf8(_local);
	}
	result.push_back('@');
	if (!is_ascii_printable_string(_domain))
	{
		result += encode_base64(_domain);
	}
	else
	{
		if (tlib::char_exist(_domain, spec_char))
		{
			std::wstring tmp(_domain);
			tlib::replace(tmp, L"\"", L"\\\"");
			result += ("\"" + tlib::wstring_to_utf8(tmp) + "\"");
		}
		else
			result += tlib::wstring_to_utf8(_domain);
	}
	return result;
}
const std::wstring Mailbox::to_wstring() const
{
	static const wchar_t* spec_char = L" \t\v\r\n\f<>()[]\\/@,;:";
	if (_local.empty() || _domain.empty())
		return L"";

	std::wstring result;

	if (tlib::char_exist(_local, spec_char))
	{
		std::wstring tmp(_local);
		tlib::replace(tmp, L"\"", L"\\\"");
		result += (L"\"" + tmp + L"\"");
	}
	else
		result += _local;
	result.push_back('@');
	if (tlib::char_exist(_domain, spec_char))
	{
		std::wstring tmp(_domain);
		tlib::replace(tmp, L"\"", L"\\\"");
		result += (L"\"" + tmp + L"\"");
	}
	else
		result += _domain;
	return result;
}
const std::string Mailbox::to_quoted_mailbox() const
{
	return "<" + to_string() + ">";
}
const std::wstring Mailbox::to_wquoted_mailbox() const
{
	return L"<" + to_wstring() + L">";
}
const std::string Address::to_string() const
{
	std::string result;
	if (!_name.empty())
	{
		if (!is_ascii_printable_string(_name))
		{
			result = tmail::encode_base64(_name);
		}
		else
		{
			std::wstring name = _name;
			tlib::replace(name, L"\"", L"\\\"");
			name = L"\"" + name + L"\"";
			result = tlib::wstring_to_utf8(name);
		}

		if (!_mailbox.empty())
		{
			result += " ";
			result += _mailbox.to_quoted_mailbox();
		}
	}
	else
	{
		result = _mailbox.to_string();
	}
	return result;
}

const std::wstring Address::to_wstring() const
{
	std::wstring result;
	if (!_name.empty())
	{
		result = _name;
		tlib::replace(result, L"\"", L"\\\"");
		result = L"\"" + result + L"\"";

		if (!_mailbox.empty())
		{
			result += L" ";
			result += _mailbox.to_wquoted_mailbox();
		}
	}
	else
	{
		result = _mailbox.to_wstring();
	}
	return result;
}
const std::string Addresses::to_string() const
{
	std::string result;
	for (const_iterator it = begin(); it != end(); it++)
	{
		if (it != begin())
			result += ", ";
		result += it->to_string();
	}
	return result;
}
const std::wstring Addresses::to_wstring() const
{
	std::wstring result;
	for (const_iterator it = begin(); it != end(); it++)
	{
		if (it != begin())
			result += L", ";
		result += it->to_wstring();
	}
	return result;
}

void Addresses::parse(const std::string& str)
{
	parse(decode_header_field(str));
}

typedef enum _address_token_type
{
	ADDR_END = 0,
	ADDR_TEXT,
	ADDR_MAILBOX,
	ADDR_QUOTED_MAILBOX, // "<....>" string and with no '<' and '>'.
	ADDR_COMMA
} AddrTokenType;

typedef struct _parse_addr_token
{
	AddrTokenType type;
	std::wstring part1;
	std::wstring part2;
} Token;

typedef struct _parse_info
{
	const wchar_t* scan;
	const wchar_t* scan_end;
}ParseInfo;


typedef enum _addr_parse_state
{
	ADDR_STATE_BEGIN = 0,
	ADDR_STATE_MBOX_LOCAL,
	ADDR_STATE_MBOX_DOMAIN,
	ADDR_STATE_MBOX_LOCAL_QUOTE,
	ADDR_STATE_MBOX_LOCAL_QUOTE_ESCAPE,
	ADDR_STATE_MBOX_DOMAIN_QUOTE,
	ADDR_STATE_MBOX_DOMAIN_QUOTE_ESCAPE,
	ADDR_STATE_TEXT,
	ADDR_STATE_TEXT_QUOTE,
	ADDR_STATE_TEXT_QUOTE_ESCAPE,
	ADDR_STATE_QUOTED_MBOX_BEGIN,
	ADDR_STATE_QUOTED_MBOX_LOCAL,
	ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE,
	ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE_ESCAPE,
	ADDR_STATE_QUOTED_MBOX_DOMAIN,
	ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE,
	ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE_ESCAPE,
	ADDR_STATE_QUOTED_MBOX_DOMAIN_END,
	ADDR_STATE_QUOTED_MBOX_TEXT,
	ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE,
	ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE_ESCAPE
} AddrParseState;

Token& trim_token(Token& token)
{
	if (token.type == ADDR_TEXT)
	{
		tlib::trim(token.part1);
	}
	else if (token.type == ADDR_MAILBOX || token.type == ADDR_QUOTED_MAILBOX)
	{
		tlib::trim(token.part1);
		tlib::trim(token.part2);
	}
	return token;
}

bool is_token_empty(Token& token)
{
	if (token.type == ADDR_TEXT)
	{
		return token.part1.empty();
	}
	else if (token.type == ADDR_MAILBOX || token.type == ADDR_QUOTED_MAILBOX)
	{
		return token.part1.empty() && token.part2.empty();
	}
	else
		return true;
}

AddrTokenType next_token(ParseInfo& parse_info, Token& token)
{
	AddrParseState state = ADDR_STATE_BEGIN;
	while (parse_info.scan < parse_info.scan_end)
	{
		if (state == ADDR_STATE_BEGIN)
		{
			token.type = ADDR_TEXT;
			token.part1.clear();
			token.part2.clear();
			if (tlib::_isspace(*parse_info.scan))
			{
			}
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_MBOX_LOCAL_QUOTE;
			}
			else if (*parse_info.scan == '<')
			{
				state = ADDR_STATE_QUOTED_MBOX_BEGIN;
			}
			else if (*parse_info.scan == ',' || *parse_info.scan == ';')
			{
				token.type = ADDR_COMMA;
				parse_info.scan++;
				return token.type;
			}
			else if (*parse_info.scan == '@' ||
					*parse_info.scan == '>' ||
					*parse_info.scan == '(' ||
					*parse_info.scan == ')' ||
					*parse_info.scan == '[' ||
					*parse_info.scan == ']' ||
					*parse_info.scan == '\\' ||
					*parse_info.scan == '/' ||
					*parse_info.scan == ':')
			{
				token.part1.push_back(*parse_info.scan);
				state = ADDR_STATE_TEXT; // Normal word
			}
			else
			{
				token.part1.push_back(*parse_info.scan);
				state = ADDR_STATE_MBOX_LOCAL; // Normal word
			}
		}
		else if (state == ADDR_STATE_MBOX_LOCAL) // Mailbox local part.
		{
			if (tlib::_isspace(*parse_info.scan) ||
					*parse_info.scan == ',' || *parse_info.scan == ';' ||
					*parse_info.scan == '<')
			{
				if (token.part1.empty())
				{
					state = ADDR_STATE_BEGIN;
					continue;
				}
				else
				{
					token.type = ADDR_TEXT;
					return token.type;
				}
			}
			else if (*parse_info.scan == '"')
				state = ADDR_STATE_MBOX_LOCAL_QUOTE;
			else if (*parse_info.scan == '@')
			{
				if (token.part1.empty())
				{
					token.part1.push_back(*parse_info.scan);
					state = ADDR_STATE_TEXT;
				}
				else
					state = ADDR_STATE_MBOX_DOMAIN;
			}
			else if (*parse_info.scan == '>' ||
					*parse_info.scan == '(' ||
					*parse_info.scan == ')' ||
					*parse_info.scan == '[' ||
					*parse_info.scan == ']' ||
					*parse_info.scan == '\\' ||
					*parse_info.scan == '/' ||
					*parse_info.scan == ':')
			{
				token.part1.push_back(*parse_info.scan);
				state = ADDR_STATE_TEXT; // Normal word
			}
			else
				token.part1.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_MBOX_LOCAL_QUOTE) // In quoted string
		{
			if (*parse_info.scan == '\\')
				state = ADDR_STATE_MBOX_LOCAL_QUOTE_ESCAPE;
			else if (*parse_info.scan == '"')
			{
				if (token.part1.empty())
					state = ADDR_STATE_BEGIN;
				else
					state = ADDR_STATE_MBOX_LOCAL;
			}
			else
				token.part1.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_MBOX_LOCAL_QUOTE_ESCAPE) // In quoted escape.
		{
			token.part1.push_back(*parse_info.scan);
			state = ADDR_STATE_MBOX_LOCAL_QUOTE;
		}
		else if (state == ADDR_STATE_MBOX_DOMAIN)
		{
			if (tlib::_isspace(*parse_info.scan) ||
					*parse_info.scan == ',' || *parse_info.scan == ';' ||
					*parse_info.scan == '<')
			{
				if (token.part2.empty())
				{
					token.part1.push_back('@');
					token.type = ADDR_TEXT;
				}
				else
					token.type = ADDR_MAILBOX;
				return token.type;
			}
			else if (*parse_info.scan == '"')
				state = ADDR_STATE_MBOX_DOMAIN_QUOTE;
			else if (*parse_info.scan == '@' ||
					*parse_info.scan == '>' ||
					*parse_info.scan == '(' ||
					*parse_info.scan == ')' ||
					*parse_info.scan == '[' ||
					*parse_info.scan == ']' ||
					*parse_info.scan == '\\' ||
					*parse_info.scan == '/' ||
					*parse_info.scan == ':')
			{
				token.part1.push_back('@');
				token.part1 += token.part2;
				token.part1.push_back(*parse_info.scan);
				token.part2.clear();
				state = ADDR_STATE_TEXT; // Normal word
			}
			else
				token.part2.push_back(*parse_info.scan);

		}
		else if (state == ADDR_STATE_MBOX_DOMAIN_QUOTE)
		{
			if (*parse_info.scan == '\\')
				state = ADDR_STATE_MBOX_DOMAIN_QUOTE_ESCAPE;
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_MBOX_DOMAIN;
			}
			else
				token.part2.push_back(*parse_info.scan);

		}
		else if (state == ADDR_STATE_MBOX_DOMAIN_QUOTE_ESCAPE)
		{
			token.part2.push_back(*parse_info.scan);
			state = ADDR_STATE_MBOX_DOMAIN_QUOTE;
		}
		else if (state == ADDR_STATE_TEXT)
		{
			if (tlib::_isspace(*parse_info.scan) ||
					*parse_info.scan == ',' || *parse_info.scan == ';' ||
					*parse_info.scan == '<')
			{
				if (token.part1.empty())
				{
					state = ADDR_STATE_BEGIN;
					continue;
				}
				else
				{
					token.type = ADDR_TEXT;
					return token.type;
				}
			}
			else if (*parse_info.scan == '"')
				state = ADDR_STATE_TEXT_QUOTE;
			else
				token.part1.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_TEXT_QUOTE)
		{
			if (*parse_info.scan == '\\')
				state = ADDR_STATE_TEXT_QUOTE_ESCAPE;
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_TEXT;
			}
			else
				token.part1.push_back(*parse_info.scan);

		}
		else if (state == ADDR_STATE_TEXT_QUOTE_ESCAPE)
		{
			token.part1.push_back(*parse_info.scan);
			state = ADDR_STATE_TEXT_QUOTE;
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_BEGIN)
		{
			if (tlib::_isspace(*parse_info.scan))
			{
			}
			else if (*parse_info.scan == '<')
			{
				token.type = ADDR_TEXT;
				token.part1.push_back('<');
				return token.type;
			}
			else if (*parse_info.scan == '>')
			{
				state = ADDR_STATE_BEGIN;
			}
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE;
			}
			else if (*parse_info.scan == '@' ||
					*parse_info.scan == ',' ||
					*parse_info.scan == ';' ||
					*parse_info.scan == '(' ||
					*parse_info.scan == ')' ||
					*parse_info.scan == '[' ||
					*parse_info.scan == ']' ||
					*parse_info.scan == '\\' ||
					*parse_info.scan == '/' ||
					*parse_info.scan == ':')
			{
				token.part1.push_back('<');
				token.part1.push_back(*parse_info.scan);
				state = ADDR_STATE_QUOTED_MBOX_TEXT; // Normal word
			}
			else
			{
				token.part1.push_back(*parse_info.scan);
				state = ADDR_STATE_QUOTED_MBOX_LOCAL;
			}
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_LOCAL)
		{
			if (*parse_info.scan == '<')
			{
				token.type = ADDR_TEXT;
				token.part1.insert(token.part1.begin(), '<');
				return token.type;
			}
			else if (*parse_info.scan == '>')
			{
				token.type = ADDR_TEXT;
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back('>');
				parse_info.scan++;
				return token.type;
			}
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE;
			}
			else if (*parse_info.scan == '@')
			{
				state = ADDR_STATE_QUOTED_MBOX_DOMAIN;
			}
			else if (tlib::_isspace(*parse_info.scan) ||
					*parse_info.scan == ',' ||
					*parse_info.scan == ';' ||
					*parse_info.scan == '(' ||
					*parse_info.scan == ')' ||
					*parse_info.scan == '[' ||
					*parse_info.scan == ']' ||
					*parse_info.scan == '\\' ||
					*parse_info.scan == '/' ||
					*parse_info.scan == ':')
			{
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back(*parse_info.scan);
				state = ADDR_STATE_QUOTED_MBOX_TEXT; // Normal word
			}
			else
			{
				token.part1.push_back(*parse_info.scan);
			}
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE)
		{
			if (*parse_info.scan == '\\')
				state = ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE_ESCAPE;
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_LOCAL;
			}
			else
				token.part1.push_back(*parse_info.scan);

		}
		else if (state == ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE_ESCAPE)
		{
			token.part1.push_back(*parse_info.scan);
			state = ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE;
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_DOMAIN)
		{
			if (*parse_info.scan == '<')
			{
				token.type = ADDR_TEXT;
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back('@');
				token.part1 += token.part2;
				return token.type;
			}
			else if (*parse_info.scan == '>')
			{
				if (token.part2.empty())
				{
					token.type = ADDR_TEXT;
					token.part1.insert(token.part1.begin(), '<');
					token.part1.push_back('@');
					token.part1.push_back('>');
				}
				else
					token.type = ADDR_QUOTED_MAILBOX;
				parse_info.scan++;
				return token.type;
			}
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE;
			}
			else if (tlib::_isspace(*parse_info.scan))
			{
				if (token.part2.empty())
				{
					token.part1.insert(token.part1.begin(), '<');
					token.part1.push_back('@');
					token.part1.push_back(' ');
					state = ADDR_STATE_QUOTED_MBOX_TEXT;
				}
				else
					state = ADDR_STATE_QUOTED_MBOX_DOMAIN_END;
			}
			else if (*parse_info.scan == '@' ||
					*parse_info.scan == '(' ||
					*parse_info.scan == ')' ||
					*parse_info.scan == '[' ||
					*parse_info.scan == ']' ||
					*parse_info.scan == '\\' ||
					*parse_info.scan == '/' ||
					*parse_info.scan == ',' ||
					*parse_info.scan == ';' ||
					*parse_info.scan == ':')
			{
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back('@');
				token.part1 += token.part2;
				token.part1.push_back(*parse_info.scan);
				token.part2.clear();
				state = ADDR_STATE_QUOTED_MBOX_TEXT; // Normal word
			}
			else
				token.part2.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE)
		{
			if (*parse_info.scan == '\\')
				state = ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE_ESCAPE;
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_DOMAIN;
			}
			else
				token.part2.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE_ESCAPE)
		{
			token.part2.push_back(*parse_info.scan);
			state = ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE;
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_DOMAIN_END)
		{
			if (tlib::_isspace(*parse_info.scan))
			{
			}
			else if (*parse_info.scan == '<')
			{
				token.type = ADDR_TEXT;
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back('@');
				token.part1 += token.part2;
				return token.type;
			}
			else if (*parse_info.scan == '>')
			{
				token.type = ADDR_QUOTED_MAILBOX;
				parse_info.scan++;
				return token.type;
			}
			else if (*parse_info.scan == '"')
			{
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back('@');
				token.part1 += token.part2;
				token.part1.push_back(' ');
				token.part2.clear();
				state = ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE;
			}
			else
			{
				token.part1.insert(token.part1.begin(), '<');
				token.part1.push_back('@');
				token.part1 += token.part2;
				token.part1.push_back(' ');
				token.part2.clear();
				state = ADDR_STATE_QUOTED_MBOX_TEXT;
			}
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_TEXT)
		{
			if (*parse_info.scan == '<')
			{
				token.type = ADDR_TEXT;
				return token.type;
			}
			else if (*parse_info.scan == '>')
			{
				token.type = ADDR_TEXT;
				token.part1.push_back('>');
				parse_info.scan++;
				return token.type;
			}
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE;
			}
			else
				token.part1.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE)
		{
			if (*parse_info.scan == '\\')
				state = ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE_ESCAPE;
			else if (*parse_info.scan == '"')
			{
				state = ADDR_STATE_QUOTED_MBOX_TEXT;
			}
			else
				token.part1.push_back(*parse_info.scan);
		}
		else if (state == ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE_ESCAPE)
		{
			token.part1.push_back(*parse_info.scan);
			state = ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE;
		}
		parse_info.scan++;
	}
	if (state == ADDR_STATE_BEGIN)
	{
		token.type = ADDR_END;
	}
	else if (state == ADDR_STATE_MBOX_DOMAIN ||
			state == ADDR_STATE_MBOX_DOMAIN_QUOTE ||
			state == ADDR_STATE_MBOX_DOMAIN_QUOTE_ESCAPE)
	{
		if (token.part2.empty())
		{
			token.part1.push_back('@');
			token.type = ADDR_TEXT;
		}
		else
			token.type = ADDR_MAILBOX;
	}
	else if (state == ADDR_STATE_TEXT ||
			state == ADDR_STATE_TEXT_QUOTE ||
			state == ADDR_STATE_TEXT_QUOTE_ESCAPE ||
			state == ADDR_STATE_MBOX_LOCAL ||
			state == ADDR_STATE_MBOX_LOCAL_QUOTE ||
			state == ADDR_STATE_MBOX_LOCAL_QUOTE_ESCAPE)
	{
		if (token.part1.empty())
			token.type = ADDR_END;
		else
			token.type = ADDR_TEXT;
	}
	else if (state == ADDR_STATE_QUOTED_MBOX_BEGIN ||
			state == ADDR_STATE_QUOTED_MBOX_LOCAL ||
			state == ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE ||
			state == ADDR_STATE_QUOTED_MBOX_LOCAL_QUOTE_ESCAPE)
	{
		token.part1.insert(token.part1.begin(), '<');
		token.type = ADDR_TEXT;
	}
	else if ( state == ADDR_STATE_QUOTED_MBOX_TEXT ||
			 state == ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE ||
			 state == ADDR_STATE_QUOTED_MBOX_TEXT_QUOTE_ESCAPE)
	{
		token.type = ADDR_TEXT;
	}
	else if (state == ADDR_STATE_QUOTED_MBOX_DOMAIN ||
			state == ADDR_STATE_QUOTED_MBOX_DOMAIN_END ||
			state == ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE ||
			state == ADDR_STATE_QUOTED_MBOX_DOMAIN_QUOTE_ESCAPE)
	{
		if (token.part2.empty())
		{
			token.part1.insert(token.part1.begin(), '<');
			token.part1.push_back('@');
			token.type = ADDR_TEXT;
		}
		else
			token.type = ADDR_QUOTED_MAILBOX;
	}
	return token.type;
}

void Addresses::parse(const std::wstring& str)
{
	std::wstring name;
	Mailbox mailbox;
	bool mailbox_high_level = false;

	ParseInfo parse_info;
	parse_info.scan = str.c_str();
	parse_info.scan_end = parse_info.scan + str.length();

	clear();

	Token token;
	while (next_token(parse_info, token) != ADDR_END)
	{
		if (token.type == ADDR_MAILBOX)
		{
			if (mailbox.empty())
			{
				mailbox.set_local(token.part1);
				mailbox.set_domain(token.part2);
				mailbox_high_level = false;
			}
			else if (mailbox_high_level)
			{
				if (!name.empty())
					name.push_back(L' ');
				name += token.part1;
				name += L'@';
				name += token.part2;
			}
			else
			{
				if (!name.empty())
					name.push_back(L' ');
				name += mailbox.get_local();
				name += L'@';
				name += mailbox.get_domain();
				mailbox.set_local(token.part1);
				mailbox.set_domain(token.part2);
				mailbox_high_level = false;
			}
		}
		else if (token.type == ADDR_QUOTED_MAILBOX)
		{
			if (mailbox.empty())
			{
				mailbox.set_local(token.part1);
				mailbox.set_domain(token.part2);
			}
			else
			{
				if (!name.empty())
					name.push_back(L' ');
				name += mailbox.get_local();
				name += L'@';
				name += mailbox.get_domain();
				mailbox.set_local(token.part1);
				mailbox.set_domain(token.part2);
			}
			mailbox_high_level = true;
		}
		else if (token.type == ADDR_TEXT)
		{
			if (!name.empty())
				name.push_back(L' ');
			name += token.part1;
		}
		else if (token.type == ADDR_COMMA)
		{
			if (!name.empty() || !mailbox.empty())
			{
				Address address(name, mailbox);
				push_back(address);
			}
			name.clear();
			mailbox.clear();
			mailbox_high_level = false;
		}
	}
	if (!name.empty() || !mailbox.empty())
	{
		Address address(name, mailbox);
		push_back(address);
	}
}

} // end namespace



