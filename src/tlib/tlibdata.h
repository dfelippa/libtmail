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

#ifndef _TLIBDATA_H_
#define _TLIBDATA_H_

#include "tlibbase.h"
#include "tlibstr.h"
#include <iostream>
#include <vector>


namespace tlib {


class BinaryData : public std::string
{
public:
	typedef enum _letter_case
	{
		_lower_case = 0,
		_upper_case = 1
	}HexLetterCase;
	static const HexLetterCase lower_case = _lower_case;
	static const HexLetterCase upper_case = _upper_case;
	inline BinaryData();
	inline BinaryData(const BinaryData& src);
	inline BinaryData(const std::string& src);
	explicit inline BinaryData(const std::wstring& src);
	inline BinaryData(const char* src, size_type size);
	inline BinaryData& operator = (const BinaryData& src);
	const std::string hex_str(HexLetterCase letter_case = lower_case) const;
public:
	inline BinaryData& operator << (const BinaryData & in);
	inline BinaryData& operator << (const std::string & in);
	inline BinaryData& operator << (const std::wstring & in);
	inline BinaryData& operator << (long in);
	inline BinaryData& operator << (int in);
	inline BinaryData& operator << (short in);
	inline BinaryData& operator << (unsigned long in);
	inline BinaryData& operator << (unsigned int in);
	inline BinaryData& operator << (unsigned short in);
	BinaryData& pop_front(BinaryData& data, size_t size);
	void pop_front(size_t size);
	BinaryData& pop_back(BinaryData& data, size_t size);
	void pop_back(size_t size);
};

inline BinaryData::BinaryData() 
: std::string()
{
}

inline BinaryData::BinaryData(const BinaryData& src)
: std::string(src)
{
}

inline BinaryData::BinaryData(const std::string& src)
: std::string(src)
{
}

inline BinaryData::BinaryData(const std::wstring& src)
: std::string()
{
	*this << src;
}

inline BinaryData::BinaryData(const char* src, size_type size)
: std::string(src, size)
{
}

inline BinaryData& BinaryData::operator = (const BinaryData& src)
{
	std::string::operator = (src);
	return *this;
}

inline BinaryData& BinaryData::operator << (const BinaryData & in)
{
	insert(end(), in.begin(), in.end());
	return *this;
}

inline BinaryData& BinaryData::operator << (const std::string & in)
{
	insert(end(), in.begin(), in.end());
	return *this;
}

inline BinaryData& BinaryData::operator << (const std::wstring & in)
{
	insert(end(), (char *)in.begin().operator ->(),
			(char *)in.begin().operator ->() + in.size() * sizeof(wchar_t));
	return *this;
}

inline BinaryData& BinaryData::operator << (long in)
{
	insert(end(), (char *)&in, (char *)&in + sizeof(long));
	return *this;
}

inline BinaryData& BinaryData::operator << (int in)
{
	insert(end(), (char *)&in, (char *)&in + sizeof(int));
	return *this;
}

inline BinaryData& BinaryData::operator << (short in)
{
	insert(end(), (char *)&in, (char *)&in + sizeof(short));
	return *this;
}

inline BinaryData& BinaryData::operator << (unsigned long in)
{
	insert(end(), (char *)&in, (char *)&in + sizeof(unsigned long));
	return *this;
}

inline BinaryData& BinaryData::operator << (unsigned int in)
{
	insert(end(), (char *)&in, (char *)&in + sizeof(unsigned int));
	return *this;
}

inline BinaryData& BinaryData::operator << (unsigned short in)
{
	insert(end(), (char *)&in, (char *)&in + sizeof(unsigned short));
	return *this;
}


std::wstring load_text_data_as_wstring(const tlib::BinaryData& data);
std::string load_text_data_as_string(const tlib::BinaryData& data);
std::wstring load_text_file_as_wstring(const std::wstring filename) throw(std::runtime_error);
std::wstring load_text_file_as_wstring(const std::string filename) throw(std::runtime_error);
std::string load_text_file_as_string(const std::wstring filename) throw(std::runtime_error);
std::string load_text_file_as_string(const std::string filename) throw(std::runtime_error);


namespace base64
{
// Encode
const std::string& encode(const char* src, size_t src_len,
						  std::string& result, bool column_limited = false);
inline const std::string& encode(const std::string& src, std::string& result, 
								 bool column_limited = false);
inline const std::string encode(const std::string& src, bool column_limited = false);
inline const std::string& encode(const std::wstring& src, std::string& result,
								 bool column_limited = false);
inline const std::string encode(const std::wstring& src, bool column_limited = false);

// Decode
const BinaryData& decode(const char* src, size_t src_len, BinaryData& result);
inline const BinaryData& decode(const std::string& src, BinaryData& result);

/////////////////////////
inline const std::string& encode(const std::string& src, std::string& result,
		bool column_limited)
{
	return encode(src.data(), src.size(), result, column_limited);
}
inline const std::string encode(const std::string& src, bool column_limited)
{
	std::string result;
	return encode(src, result, column_limited);
}
inline const std::string& encode(const std::wstring& src, std::string& result,
		bool column_limited)
{
	return encode((const char*)src.data(), src.size() * sizeof(wchar_t), result, column_limited);
}
inline const std::string encode(const std::wstring& src, bool column_limited)
{
	std::string result;
	return encode(src, result, column_limited);
}
inline const BinaryData& decode(const std::string& src, BinaryData& result)
{
	return decode(src.c_str(), src.length(), result);
}

} // End of namespace base64


namespace qprint
{

// Encode
const std::string& encode(const char* src, size_t src_len,
						  std::string& result, bool column_limited = false);
inline const std::string& encode(const std::string& src, std::string& result,
								 bool column_limited = false);
inline const std::string& encode(const std::wstring& src, std::string& result,
								 bool column_limited = false);

// Decode
const BinaryData& decode(const char* src, size_t src_len, BinaryData& result);
inline const BinaryData& decode(const std::string& src, BinaryData& result);

/////////////////////////
inline const std::string& encode(const std::string& src, std::string& result, bool column_limited)
{
	return encode(src.data(), src.size(), result, column_limited);
}
inline const std::string& encode(const std::wstring& src, std::string& result, bool column_limited)
{
	return encode((const char*)src.data(), src.size() * sizeof(wchar_t), result, column_limited);
}
inline const BinaryData& decode(const std::string& src, BinaryData& result)
{
	return decode(src.c_str(), src.length(), result);
}

} // End of namespace qprint



namespace hash
{
	const BinaryData md5(const BinaryData& data);
	const BinaryData hmac_md5(const BinaryData& data, const BinaryData& key);
} // End of namespace hash





// Load/Save setting file.
std::map<std::string, std::string> load_setting(const std::string& filename);
void save_setting(const std::string& filename,
		const std::map<std::string, std::string>& setting);

} // end namespace tlib





inline
std::ostream& operator << (std::ostream& out, const tlib::BinaryData& data)
{
	if (out.good())
		out.write(data.begin().operator ->(), (std::streamsize)data.size());
	return out;
}

inline
std::istream & operator >> (std::istream& in, tlib::BinaryData& data)
{
	data.clear();
	while (in.good())
	{
		char buf[512];
		in.read(buf, 512);
		data.insert(data.end(), buf, buf + in.gcount());
	}
	return in;
}


#endif /* _TLIBDATA_H_ */
