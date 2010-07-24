/************************************************************************
*
*  LibTLib
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

#include "tlibdata.h"
#include <stdexcept>
#include "md5.h"
#include <fstream>

namespace tlib
{

static const unsigned char hex_decode_table[256] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
	0,10,11,12,13,14,15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0,10,11,12,13,14,15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const unsigned char hex_decode_mask[256] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const std::string BinaryData::hex_str(HexLetterCase letter_case) const
{
	std::string result;
	result.reserve(size() * 2);
	static const char* lower_hex_table = "0123456789abcdef";
	static const char* upper_hex_table = "0123456789ABCDEF";
	const char* hex_table;
	if (letter_case == lower_case)
		hex_table = lower_hex_table;
	else
		hex_table = upper_hex_table;
	const unsigned char* scan = (const unsigned char*)c_str();
	const unsigned char* scan_end = scan + size();
	while (scan < scan_end)
	{
		result.push_back(hex_table[*scan >> 4]);
		result.push_back(hex_table[*scan & 0x0F]);
		scan++;
	}
	return result;
}

BinaryData& BinaryData::pop_front(BinaryData& data, size_t len)
{
	BinaryData::iterator pop_begin, pop_end;
	if (len > size())
	{
		pop_begin = begin();
		pop_end = end();
	}
	else
	{
		pop_begin = begin();
		pop_end = pop_begin + len;
	}
	data.assign(pop_begin, pop_end);
	erase(pop_begin, pop_end);
	return data;
}
void BinaryData::pop_front(size_t len)
{
	BinaryData::iterator pop_begin, pop_end;
	if (len > size())
	{
		pop_begin = begin();
		pop_end = end();
	}
	else
	{
		pop_begin = begin();
		pop_end = pop_begin + len;
	}
	erase(pop_begin, pop_end);
}
BinaryData& BinaryData::pop_back(BinaryData& data, size_t len)
{
	BinaryData::iterator pop_begin, pop_end;
	if (len > size())
	{
		pop_begin = begin();
		pop_end = end();
	}
	else
	{
		pop_begin = begin() + size() - len;
		pop_end = pop_begin + len;
	}
	data.assign(pop_begin, pop_end);
	erase(pop_begin, pop_end);
	return data;
}
void BinaryData::pop_back(size_t len)
{
	BinaryData::iterator pop_begin, pop_end;
	if (len > size())
	{
		pop_begin = begin();
		pop_end = end();
	}
	else
	{
		pop_begin = begin() + size() - len;
		pop_end = pop_begin + len;
	}
	erase(pop_begin, pop_end);
}

const char* test_charset(const tlib::BinaryData& data, bool& bom)
{
	const unsigned char* scan = (const unsigned char*)data.c_str();
	if (data.size() >= 3)
	{
		if (scan[0] == 0xEF && scan[1] == 0xBB && scan[2] == 0xBF)
		{
			bom = true;
			return "utf-8";
		}
		else if (scan[0] == 0xFF && scan[1] == 0xFE)
		{
			bom = true;
			return "utf-16";
		}
		else if (scan[0] == 0xFE && scan[1] == 0xFF)
		{
			bom = true;
			return "utf-16be";
		}
	}
	else if (data.size() >= 2)
	{
		if (scan[0] == 0xFF && scan[1] == 0xFE)
		{
			bom = true;
			return "utf-16";
		}
		else if (scan[0] == 0xFE && scan[1] == 0xFF)
		{
			bom = true;
			return "utf-16be";
		}
	}
	bom = false;
	// Has no BOM.
	// so, determine whether it is en UTF-8 charset.
	size_t len = data.size();
	bool utf8 = true;
	bool pure_ansi = true;
	for (size_t i = 0; i < len;)
	{
		if (scan[i] < 128)
		{
			i++;
		}
		else if (i < len - 1 && 
			(scan[i] & 0xE0) == 0xC0 && 
			(scan[i + 1] & 0xC0) == 0x80)
		{
			i += 2;
			pure_ansi = false;
		}
		else if (i < len - 2 &&
			(scan[i] & 0xF0) == 0xE0 && 
			(scan[i + 1] & 0xC0) == 0x80 &&
			(scan[i + 2] & 0xC0) == 0x80)
		{
			i += 3;
			pure_ansi = false;
		}
		else
		{
			utf8 = false;
			pure_ansi = false;
			break;
		}
	}
	if (utf8)
		return "utf-8";
	else if (pure_ansi)
		return "us-ascii";
	else
		return get_locale_charset();
}


std::wstring load_text_data_as_wstring(const tlib::BinaryData& data)
{
	bool bom;
	const char* charset = test_charset(data, bom);
	unsigned int cp = convert_charset_to_codepage(charset);
	if (cp == 1200) // utf-16
	{
		if (bom)
		{
			const wchar_t* start = (const wchar_t*)(data.c_str() + 2);
			return std::wstring(start, (data.size() - 2) / 2);
		}
		else
		{
			const wchar_t* start = (const wchar_t*)data.c_str();
			return std::wstring(start, data.size() / 2);
		}
	}
	else if (cp == 1201) // utf-16be
	{
		std::wstring result;
		if (bom)
		{
			const wchar_t* start = (const wchar_t*)(data.c_str() + 2);
			result.assign(start, (data.size() - 2) / 2);
		}
		else
		{
			const wchar_t* start = (const wchar_t*)data.c_str();
			result.assign(start, data.size() / 2);
		}
		for (size_t i = 0; i < result.size(); i++)
		{
			unsigned short uch = result[i];
			uch = (uch << 8) | (uch >> 8);
			result[i] = uch;
		}
		return result;
	}
	else
		return tlib::charset_to_wstring(data, charset);

}
std::string load_text_data_as_string(const tlib::BinaryData& data)
{
	bool bom;
	const char* charset = test_charset(data, bom);
	unsigned int cp = convert_charset_to_codepage(charset);
	if (cp == 1200) // utf-16
	{
		if (bom)
		{
			const wchar_t* start = (const wchar_t*)(data.c_str() + 2);
			return tlib::wstring_to_locale(std::wstring(start, (data.size() - 2) / 2));
		}
		else
		{
			const wchar_t* start = (const wchar_t*)data.c_str();
			return tlib::wstring_to_locale(std::wstring(start, data.size() / 2));
		}
	}
	else if (cp == 1201) // utf-16be
	{
		std::wstring result;
		if (bom)
		{
			const wchar_t* start = (const wchar_t*)(data.c_str() + 2);
			result.assign(start, (data.size() - 2) / 2);
		}
		else
		{
			const wchar_t* start = (const wchar_t*)data.c_str();
			result.assign(start, data.size() / 2);
		}
		for (size_t i = 0; i < result.size(); i++)
		{
			result[i] = (result[i] << 8) | (result[i] >> 8);
		}
		return tlib::wstring_to_locale(result);
	}
	else
		return tlib::wstring_to_locale(tlib::charset_to_wstring(data, charset));
}
std::wstring load_text_file_as_wstring(const std::wstring filename) throw(std::runtime_error)
{
#ifdef WIN32
	std::ifstream infile(filename.c_str());
#elif defined(__linux)
	std::ifstream infile(tlib::wstring_to_locale(filename).c_str());
#endif
	if (infile.fail())
		throw std::runtime_error("Open file error: " + tlib::wstring_to_locale(filename));

	tlib::BinaryData data;
	infile >> data;
	infile.close();

	return load_text_data_as_wstring(data);
}
std::wstring load_text_file_as_wstring(const std::string filename) throw(std::runtime_error)
{
	std::ifstream infile(filename.c_str());
	if (infile.fail())
		throw std::runtime_error("Open file error: " + filename);

	tlib::BinaryData data;
	infile >> data;
	infile.close();

	return load_text_data_as_wstring(data);
}
std::string load_text_file_as_string(const std::wstring filename) throw(std::runtime_error)
{
#ifdef WIN32
	std::ifstream infile(filename.c_str());
#elif defined(__linux)
	std::ifstream infile(tlib::wstring_to_locale(filename).c_str());
#endif

	if (infile.fail())
		throw std::runtime_error("Open file error: " + tlib::wstring_to_locale(filename));

	tlib::BinaryData data;
	infile >> data;
	infile.close();

	return load_text_data_as_string(data);
}
std::string load_text_file_as_string(const std::string filename) throw(std::runtime_error)
{
	std::ifstream infile(filename.c_str());
	if (infile.fail())
		throw std::runtime_error("Open file error: " + filename);

	tlib::BinaryData data;
	infile >> data;
	infile.close();

	return load_text_data_as_string(data);
}






namespace base64
{

//Base64 encode table
static const char base64_encode_table[64] = 
{
	65,  66,  67,  68,  69,  70,  71,  72,		//  00 -  07
	73,  74,  75,  76,  77,  78,  79,  80,		//  08 -  15
	81,  82,  83,  84,  85,  86,  87,  88,		//  16 -  23
	89,  90,  97,  98,  99,  100, 101, 102,		//  24 -  31
	103, 104, 105, 106, 107, 108, 109, 110,		//  32 -  39
	111, 112, 113, 114, 115, 116, 117, 118,		//  40 -  47
	119, 120, 121, 122, 48,  49,  50,  51,		//  48 -  55
	52,  53,  54,  55,  56,  57,  43,  47		//  56 -  63
};

//Base64 decode table
static const unsigned char base64_decode_table[256] = 
{
	255, 255, 255, 255, 255, 255, 255, 255,		//  00 -  07
	255, 255, 255, 255, 255, 255, 255, 255,		//  08 -  15
	255, 255, 255, 255, 255, 255, 255, 255,		//  16 -  23
	255, 255, 255, 255, 255, 255, 255, 255,		//  24 -  31
	255, 255, 255, 255, 255, 255, 255, 255,		//  32 -  39
	255, 255, 255, 62,  255, 255, 255, 63,		//  40 -  47
	52,  53,  54,  55,  56,  57,  58,  59,		//  48 -  55
	60,  61,  255, 255, 255, 255, 255, 255,		//  56 -  63
	255, 0,   1,   2,   3,   4,   5,   6,		//  64 -  71
	7,   8,   9,   10,  11,  12,  13,  14,		//  72 -  79
	15,  16,  17,  18,  19,  20,  21,  22,		//  80 -  87
	23,  24,  25,  255, 255, 255, 255, 255,		//  88 -  95
	255, 26,  27,  28,  29,  30,  31,  32,		//  96 - 103
	33,  34,  35,  36,  37,  38,  39,  40,		// 104 - 111
	41,  42,  43,  44,  45,  46,  47,  48,		// 112 - 119
	49,  50,  51,  255, 255, 255, 255, 255,		// 120 - 127
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255 
};

const std::string& encode(const char* src, size_t src_len, std::string& result, bool column_limited)
{
	if (src_len == 0)
	{
		result.clear();
		return result;
	}
	size_t out_len = (src_len + 2) / 3 * 4;
	size_t column_max;
	size_t line;
	if (column_limited)
	{
		column_max = 76;
		line = out_len / column_max + (out_len % column_max > 0 ? 1 : 0);
	}
	else
	{
		column_max = -1;
		line = 1;
	}
	out_len += (line * 2);

	result.clear();
	result.reserve(out_len);

	unsigned int value = 0;
	const unsigned char* scan = (const unsigned char*)(src);
	const unsigned char* end = scan + src_len;
	const unsigned char* safe_end = end - 3;
	unsigned char column = 0;

	while(scan <= safe_end)
	{
		// Input.
		value = *scan++;
		value <<= 8;
		value |= *scan++;
		value <<= 8;
		value |= *scan++;

		if (column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[value >> 18]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[(value >> 12) & 0x3F]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[(value >> 6) &  0x3F]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[value & 0x3F]);
		column++;
	}
	switch(end - scan) 
	{
	case 1:
		// Input.
		value = *scan++;
		value <<= 16;

		if (column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[value >> 18]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[(value >> 12) & 0x3F]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back('=');
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back('=');
		break;
	case 2:
		// Input.
		value = *scan++;
		value <<= 8;
		value |= *scan++;
		value <<= 8;

		if (column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[value >> 18]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[(value >> 12) & 0x3F]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back(base64_encode_table[(value >> 6) &  0x3F]);
		if (++column == column_max)
		{
			result.push_back('\r');
			result.push_back('\n');
			column = 0;
		}
		result.push_back('=');
		break;
	}
	return result;
}

const BinaryData& decode(const char* src, size_t src_len, BinaryData& result)
{
	size_t len = ((src_len + 3) / 4 + 1) * 3;
	result.clear();
	result.reserve(len);

	const char* scan = src;
	const char* scan_end = src + src_len;
	unsigned int value = 0;
	unsigned char valid_char = 0;
	unsigned char pos = 0;
	while( scan < scan_end)
	{
		valid_char = base64_decode_table[(int)*scan++];
		if (valid_char == 0xFF)
			continue;

		value <<= 6;
		value |= valid_char;
		if (++pos == 4)
		{
			result.push_back((char)(unsigned char)(value >> 16));
			result.push_back((char)(unsigned char)((value >> 8) & 0xFF));
			result.push_back((char)(unsigned char)(value & 0xFF));
			value = 0;
			pos = 0;
		}
	}

	switch(pos)
	{
	case 2:
		result.push_back((char)(unsigned char)(value >> 4));
		break;
	case 3:
		result.push_back((char)(unsigned char)(value >> 10));
		result.push_back((char)(unsigned char)((value >> 2) & 0xFF));
		break;
	}
	return result;
}

} //end namespace base64


namespace qprint
{

const std::string& encode(const char* src, size_t src_len,
						  std::string& result, bool column_limited)
{
	static const char* hex_table = "0123456789ABCDEF";
	const unsigned char* scan = (const unsigned char*)src;
	const unsigned char* scan_end = scan + src_len;
	size_t column_max;
	if (column_limited)
		column_max = 76;
	else
		column_max = -1;
	result.clear();
	result.reserve(src_len);
	size_t column = 0;
	while (scan < scan_end)
	{
		if ((*scan >= 33 && *scan <= 60) || (*scan >= 62 && *scan <= 126))
		{
			if (column + 1 < column_max)
			{
				result.push_back(*scan);
				column++;
			}
			else
			{
				result.push_back('=');
				result.push_back('\r');
				result.push_back('\n');
				result.push_back(*scan);
				column = 1;
			}
		}
		else if (*scan == ' ' || *scan == '\t')
		{
			if (scan == scan_end - 1)
			{
				if (column + 3 < column_max)
				{
					result.push_back('=');
					result.push_back(hex_table[*scan >> 4]);
					result.push_back(hex_table[*scan & 0x0F]);
					column += 3;
				}
				else
				{
					result.push_back('=');
					result.push_back('\r');
					result.push_back('\n');
					result.push_back('=');
					result.push_back(hex_table[*scan >> 4]);
					result.push_back(hex_table[*scan & 0x0F]);
					column = 3;
				}
			}
			else
			{
				if (column + 1 < column_max)
				{
					result.push_back(*scan);
					column++;
				}
				else
				{
					result.push_back('=');
					result.push_back('\r');
					result.push_back('\n');
					result.push_back(*scan);
					column = 1;
				}
			}
		}
		else
		{
			if (column + 3 < column_max)
			{
				result.push_back('=');
				result.push_back(hex_table[*scan >> 4]);
				result.push_back(hex_table[*scan & 0x0F]);
				column += 3;
			}
			else
			{
				result.push_back('=');
				result.push_back('\r');
				result.push_back('\n');
				column = 0;
				result.push_back('=');
				result.push_back(hex_table[*scan >> 4]);
				result.push_back(hex_table[*scan & 0x0F]);
				column += 3;
			}
		}
		scan++;
	}
	return result;
}

const BinaryData& decode(const char* src, size_t src_len, BinaryData& result)
{
	const char* scan = src;
	const char* scan_end = src + src_len;
	char char_value = 0;
	int state = 0;
	result.clear();
	result.reserve(src_len);
	std::string space_text;
	while (scan < scan_end)
	{
		if (state == 0)
		{
			if (*scan == '=')
				state = 1;
			else if (isspace(*scan))
			{
				space_text.push_back(*scan);
				state = 3;
			}
			else
				result.push_back(*scan);
		}
		else if (state == 1)
		{
			if (hex_decode_mask[(int)*scan])
			{
				char_value = hex_decode_table[(int)*scan];
				char_value <<= 4;
				state = 2;
			}
			else if (*scan == '\n')
			{
				state = 0;
			}
			else if (isspace(*scan))
			{
			}
			else
			{
				result.push_back(*scan);
				state = 0;
			}
		}
		else if (state == 2)
		{
			if (hex_decode_mask[(int)*scan])
			{
				char_value |= hex_decode_table[(int)*scan];
				result.push_back(char_value);
				state = 0;
			}
			else
			{
				result.push_back(*(scan - 1));
				result.push_back(*scan);
				state = 0;
			}
		}
		else
		{
			if (*scan == '=')
			{
				result += space_text;
				space_text.clear();
				state = 1;
			}
			else if (isspace(*scan))
			{
				space_text.push_back(*scan);
			}
			else
			{
				result += space_text;
				space_text.clear();
				result.push_back(*scan);
				state = 0;
			}
		}
		scan++;
	}
	return result;
}



} // End namespace qprint


namespace hash
{

const BinaryData md5(const BinaryData& data)
{
	unsigned char buffer[16];
	MD5_CTX context;
	MD5Init(&context);
	MD5Update(&context, (unsigned char*)data.c_str(), (unsigned int)data.size());
	MD5Final(buffer, &context);
	return BinaryData((char*)buffer, 16);
}

const BinaryData hmac_md5(const BinaryData& data, const BinaryData& key)
{
	unsigned char inner_pad[65];
	unsigned char outer_pad[65];
	unsigned char buffer[16];
	memset(inner_pad, 0, 65);
	memset(outer_pad, 0, 65);
	if (key.size() > 64)
	{
		BinaryData key_md5 = md5(key);
		memcpy(inner_pad, key_md5.c_str(), key_md5.size());
		memcpy(outer_pad, key_md5.c_str(), key_md5.size());
	}
	else
	{
		memcpy(inner_pad, key.c_str(), key.size());
		memcpy(outer_pad, key.c_str(), key.size());
	}
	for (int i = 0; i < 64; i++)
	{
		inner_pad[i] ^= 0x36;
		outer_pad[i] ^= 0x5c;
	}
	MD5_CTX context;
	MD5Init(&context);
	MD5Update(&context, inner_pad, 64);
	MD5Update(&context, (unsigned char*)data.c_str(), (unsigned int)data.size());
	MD5Final(buffer, &context);

	MD5Init(&context);
	MD5Update(&context, outer_pad, 64);
	MD5Update(&context, buffer, 16);
	MD5Final(buffer, &context);

	return BinaryData((char*)buffer, 16);
}


} // End of namespace hash



// Load/Save setting file.
std::map<std::string, std::string> load_setting(const std::string& filename)
{
	std::ifstream infile;
	std::map<std::string, std::string> ret;
	std::string instr;
	try
	{
		infile.open(filename.c_str(), std::ios::in);
		while (infile.good())
		{
			char buf[512];
			infile.read(buf, 512);
			instr.insert(instr.end(), buf, buf + infile.gcount());
		}
		infile.close();
	}
	catch (...)
	{
	}
	std::vector<std::wstring> lines;
	tlib::split(tlib::locale_to_wstring(instr), L"\n", lines);
	typedef std::vector<std::wstring>::iterator iterator;
	for (iterator line = lines.begin(); line != lines.end(); line++)
	{
		size_t fnd = (*line).find(L"=");
		if (fnd != std::string::npos)
		{
			std::string key;
			tlib::wstring_to_locale(
					tlib::trim_copy((*line).substr(0, fnd)), key);
			if (!key.empty())
				tlib::wstring_to_locale(
						tlib::trim_copy((*line).substr(fnd + 1)), ret[key]);
		}
		else
		{
			tlib::trim(*line);
			if (!(*line).empty())
			{
				std::string val;
				tlib::wstring_to_locale(*line, val);
				ret[val] = val;
			}
		}
	}
	return ret;
}

void save_setting(const std::string& filename,
		const std::map<std::string, std::string>& setting)
{
	std::ofstream outfile;
	outfile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.good())
	{
		throw std::runtime_error("Open file failed.");
	}
	for (std::map<std::string, std::string>::const_iterator it = setting.begin();
			it != setting.end(); it++)
	{
		outfile << it->first << "=" << it->second << "\n";
	}
	outfile.close();
}


} // end namespace tlib
