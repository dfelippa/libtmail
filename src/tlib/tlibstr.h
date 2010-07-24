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

#ifndef _TLIBSTR_H_
#define _TLIBSTR_H_

#include "tlibbase.h"
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <wchar.h>
#include <string.h>

#ifdef WIN32
#  define USE_CONVERT_API
#  define strcasecmp _stricmp
#  define strncasecmp _strnicmp
#endif

namespace tlib {

inline bool char_exist(const std::string& src, const std::string& char_seq);
inline bool char_exist(const std::wstring& src, const std::wstring& char_seq);


// Case converting.
inline std::string & to_lower(std::string & src);
inline std::wstring & to_lower(std::wstring & src);
inline const std::string to_lower_copy(const std::string & src);
inline const std::wstring to_lower_copy(const std::wstring & src);
inline std::string & to_upper(std::string & src);
inline std::wstring & to_upper(std::wstring & src);
inline const std::string to_upper_copy(const std::string & src);
inline const std::wstring to_upper_copy(const std::wstring & src);



template <typename T, typename T_Char> inline
const std::basic_string<T_Char> to_string_base(const T & src);
template <typename T, typename T_Char> inline
const T from_string_base(const std::basic_string<T_Char> & src);

// Convert any type to string.
template <typename T> inline
const std::string strfrom(const T& src);
// Convert string to any type.
template <typename T> inline
const T strto(const std::string& src);

// Convert any type to wstring.
template <typename T> inline
const std::wstring wstrfrom(const T& src);
// Convert wstring to any type.
template <typename T> inline
const T wstrto(const std::wstring& src);


// Replace sub string to a new string.
const int unlimited = -1;
inline
std::string& replace(std::string& src, const std::string& fnd,
		const std::string& rep, int rep_times = unlimited);
inline
std::wstring& replace(std::wstring& src, const std::wstring& fnd,
		const std::wstring& rep, int rep_times = unlimited);
inline
const std::string replace_copy(const std::string& src,
		const std::string& fnd, const std::string& rep, 
		int rep_times = unlimited);
inline
const std::wstring replace_copy(const std::wstring& src,
		const std::wstring & fnd, const std::wstring& rep, 
		int rep_times =	unlimited);



// String trim.
bool _isspace(int ch);
bool _iscntrl(int ch);
bool _isalpha(int c);
bool _isalnum(int ch);
bool _isdigit(int ch);
bool _isxdigit(int ch);
bool _islower(int ch);
bool _isupper(int ch);
bool _ispunct(int ch);
inline bool _isgraph(int ch)
{
	return (ch >= 0x21 && ch <= 0x7e);
}

inline bool _isprint(int ch)
{
	return (ch >= 0x20 && ch <= 0x7e);
}
inline bool _isascii(int ch)
{
	return (ch >= 0x0 && ch <= 0x7f);
}

inline std::string & trim(std::string & src);
inline std::wstring & trim(std::wstring & src);
inline const std::string trim_copy(const std::string & src);
inline const std::wstring trim_copy(const std::wstring & src);
inline std::string & trim_left(std::string & src);
inline std::wstring & trim_left(std::wstring & src);
inline const std::string trim_left_copy(const std::string & src);
inline const std::wstring trim_left_copy(const std::wstring & src);
inline std::string & trim_right(std::string & src);
inline std::wstring & trim_right(std::wstring & src);
inline const std::string trim_right_copy(const std::string & src);
inline const std::wstring trim_right_copy(const std::wstring & src);


// String split and join
inline  std::vector<std::string> & split(const std::string & src,
		const std::string & delimit, std::vector<std::string> & array);
inline std::vector<std::wstring> & split(const std::wstring & src,
		const std::wstring & delimit, std::vector<std::wstring> & array);
inline const std::vector<std::string> split(const std::string & src,
		const std::string & delimit);
inline const std::vector<std::wstring> split(const std::wstring & src,
		const std::wstring & delimit);
inline std::vector<std::string> & split_append(const std::string & src,
		const std::string & delimit, std::vector<std::string> & array);
inline std::vector<std::wstring> & split_append(const std::wstring & src,
		const std::wstring & delimit, std::vector<std::wstring> & array);
inline std::string & join(const std::vector<std::string> & array,
		const std::string & delimit, std::string & result);
inline std::wstring & join(const std::vector<std::wstring> & array,
		const std::wstring & delimit, std::wstring & result);
inline const std::string join(const std::vector<std::string> & array,
		const std::string & delimit);
inline const std::wstring join(const std::vector<std::wstring> & array,
		const std::wstring & delimit);
inline std::string & join_append(const std::vector<std::string> & array,
		const std::string & delimit, std::string & result);
inline std::wstring & join_append(const std::vector<std::wstring> & array,
		const std::wstring & delimit, std::wstring & result);

// Convert between charset and windows codepage.
const char* convert_codepage_to_charset(unsigned int codepage);
unsigned int convert_charset_to_codepage(const char* charset);

// Get the current OS used charset.
const char* get_locale_charset();


// String charset convert.
const std::string& wstring_to_locale(const std::wstring &src, std::string& result);
inline const std::string wstring_to_locale(const std::wstring &src);

const std::wstring& locale_to_wstring(const std::string& src, std::wstring& result);
inline const std::wstring locale_to_wstring(const std::string& src);

const std::string& wstring_to_utf8(const std::wstring &src, std::string& result);
inline const std::string wstring_to_utf8(const std::wstring &src);

const std::wstring& utf8_to_wstring(const std::string& src, std::wstring& result);
inline const std::wstring utf8_to_wstring(const std::string& src);

const std::string& utf8_to_locale(const std::string& src, std::string& result);
inline const std::string utf8_to_locale(const std::string& src);

const std::string& locale_to_utf8(const std::string& src, std::string& result);
inline const std::string locale_to_utf8(const std::string& src);

const std::wstring& charset_to_wstring(const std::string& src, const std::string& charset, std::wstring& result);
inline const std::wstring charset_to_wstring(const std::string& src, const std::string& charset);

const std::string& wstring_to_charset(const std::wstring& src, const std::string& charset, std::string& result);
inline const std::string& wstring_to_charset(const std::wstring& src, const std::string& charset);



} // end of tlib namespace.


template<typename T_Char>
bool __char_exist(const std::basic_string<T_Char>& src, const std::basic_string<T_Char>& char_seq);

inline bool tlib::char_exist(const std::string& src, const std::string& char_seq)
{
	return __char_exist<char>(src, char_seq);
}
inline bool tlib::char_exist(const std::wstring& src, const std::wstring& char_seq)
{
	return __char_exist<wchar_t>(src, char_seq);
}


// Convert any type to string.
template <typename T, typename T_Char> inline
const std::basic_string<T_Char> tlib::to_string_base(const T & src)
{
	std::basic_stringstream<T_Char> sbuf;
	sbuf << src;
	return sbuf.str();
}

// Convert string to any type.
template <typename T, typename T_Char> inline
const T tlib::from_string_base(const std::basic_string<T_Char> & src)
{
	std::basic_stringstream<T_Char> sbuf(src);
	T obj;
	sbuf >> obj;
	return obj;
}

// Convert any type to string.
template <typename T> inline
const std::string tlib::strfrom(const T& src)
{
	return to_string_base<T, char>(src);
}

// Convert string to any type.
template <typename T> inline
const T tlib::strto(const std::string& src)
{
	return from_string_base<T, char>(src);
}

// Convert any type to wstring.
template <typename T> inline
const std::wstring tlib::wstrfrom(const T& src)
{
	return to_string_base<T, wchar_t>(src);
}

// Convert wstring to any type.
template <typename T> inline
const T tlib::wstrto(const std::wstring& src)
{
	return from_string_base<T, wchar_t>(src);
}

inline std::string & tlib::to_lower(std::string & src)
{
	std::transform(src.begin(), src.end(), src.begin(), tolower);
	return src;
}

inline std::wstring & tlib::to_lower(std::wstring & src)
{
	std::transform(src.begin(), src.end(), src.begin(), tolower);
	return src;
}

inline const std::string tlib::to_lower_copy(const std::string & src)
{
	std::string cp(src);
	return to_lower(cp);
}

inline const std::wstring tlib::to_lower_copy(const std::wstring & src)
{
	std::wstring cp(src);
	return to_lower(cp);
}

inline std::string & tlib::to_upper(std::string &src)
{
	std::transform(src.begin(), src.end(), src.begin(), toupper);
	return src;
}

inline std::wstring & tlib::to_upper(std::wstring &src)
{
	std::transform(src.begin(), src.end(), src.begin(), toupper);
	return src;
}

inline const std::string tlib::to_upper_copy(const std::string & src)
{
	std::string cp(src);
	return to_upper(cp);
}

inline const std::wstring tlib::to_upper_copy(const std::wstring & src)
{
	std::wstring cp(src);
	return to_upper(cp);
}

template<typename T_Char>
std::basic_string<T_Char> & __replace(std::basic_string<T_Char> & src,
		const std::basic_string<T_Char> & fnd,
		const std::basic_string<T_Char> & rep, int rep_times);

inline std::string & tlib::replace(std::string & src, const std::string & fnd,
		const std::string & rep, int rep_times)
{
	return __replace<char> (src, fnd, rep, rep_times);
}

inline std::wstring & tlib::replace(std::wstring & src,
		const std::wstring & fnd, const std::wstring & rep, int rep_times)
{
	return __replace<wchar_t> (src, fnd, rep, rep_times);
}

inline const std::string tlib::replace_copy(const std::string & src,
		const std::string & fnd, const std::string & rep, int rep_times)
{
	std::string cp(src);
	return replace(cp, fnd, rep, rep_times);
}

inline const std::wstring tlib::replace_copy(const std::wstring & src,
		const std::wstring & fnd, const std::wstring & rep, int rep_times)
{
	std::wstring cp(src);
	return replace(cp, fnd, rep, rep_times);
}



template <typename T_Char>
std::basic_string<T_Char> & __trim_left(std::basic_string<T_Char> & src);

template <typename T_Char>
std::basic_string<T_Char> & __trim_right(std::basic_string<T_Char> & src);


inline std::string & tlib::trim(std::string & src)
{
	return trim_left(trim_right(src));
}


inline std::wstring & tlib::trim(std::wstring & src)
{
	return trim_left(trim_right(src));
}


inline const std::string tlib::trim_copy(const std::string & src)
{
	std::string cp(src);
	return trim(cp);
}


inline const std::wstring tlib::trim_copy(const std::wstring & src)
{
	std::wstring cp(src);
	return trim(cp);
}

inline std::string & tlib::trim_left(std::string & src)
{
	return __trim_left<char> (src);
}

inline std::wstring & tlib::trim_left(std::wstring & src)
{
	return __trim_left<wchar_t> (src);
}

inline const std::string tlib::trim_left_copy(const std::string & src)
{
	std::string cp(src);
	return trim_left(cp);
}

inline const std::wstring tlib::trim_left_copy(const std::wstring & src)
{
	std::wstring cp(src);
	return trim_left(cp);
}

inline std::string & tlib::trim_right(std::string & src)
{
	return __trim_right<char> (src);
}

inline std::wstring & tlib::trim_right(std::wstring & src)
{
	return __trim_right<wchar_t> (src);
}

inline const std::string tlib::trim_right_copy(const std::string & src)
{
	std::string cp(src);
	return trim_right(cp);
}

inline const std::wstring tlib::trim_right_copy(const std::wstring & src)
{
	std::wstring cp(src);
	return trim_right(cp);
}

template <typename T_Char>
std::vector<std::basic_string<T_Char> > & __split_append(
		const std::basic_string<T_Char> & src,
		const std::basic_string<T_Char> & delimit,
		std::vector<std::basic_string<T_Char> > & array);


template <typename T_Char> inline
std::vector<std::basic_string<T_Char> > & __split(
		const std::basic_string<T_Char> & src,
		const std::basic_string<T_Char> & delimit,
		std::vector<std::basic_string<T_Char> > & array)
{
	array.clear();
	return __split_append(src, delimit, array);
}

inline std::vector<std::string> & tlib::split(const std::string & src,
		const std::string & delimit, std::vector<std::string> & array)
{
	return __split<char> (src, delimit, array);
}

inline std::vector<std::wstring> & tlib::split(const std::wstring & src,
		const std::wstring & delimit, std::vector<std::wstring> & array)
{
	return __split<wchar_t> (src, delimit, array);
}

inline const std::vector<std::string> tlib::split(const std::string & src,
		const std::string & delimit)
{
	std::vector<std::string> array;
	return split(src, delimit, array);
}

inline const std::vector<std::wstring> tlib::split(const std::wstring & src,
		const std::wstring & delimit)
{
	std::vector<std::wstring> array;
	return split(src, delimit, array);
}

inline std::vector<std::string> & tlib::split_append(const std::string & src,
		const std::string & delimit, std::vector<std::string> & array)
{
	return __split_append<char> (src, delimit, array);
}

inline std::vector<std::wstring> & tlib::split_append(const std::wstring & src,
		const std::wstring & delimit, std::vector<std::wstring> & array)
{
	return __split_append<wchar_t> (src, delimit, array);
}

template<typename T_Char>
std::basic_string<T_Char> & __join_append(
		const std::vector<std::basic_string<T_Char> > & array,
		const std::basic_string<T_Char> & delimit,
		std::basic_string<T_Char> & result);


template<typename T_Char> inline
std::basic_string<T_Char> & __join(
		const std::vector<std::basic_string<T_Char> > & array,
		const std::basic_string<T_Char> & delimit,
		std::basic_string<T_Char> & result)
{
	result.clear();
	return __join_append(array, delimit, result);
}

inline std::string& tlib::join_append(const std::vector<std::string> & array,
		const std::string & delimit, std::string & result)
{
	return __join_append<char> (array, delimit, result);
}

inline std::wstring& tlib::join_append(
		const std::vector<std::wstring> & array, const std::wstring & delimit,
		std::wstring & result)
{
	return __join_append<wchar_t> (array, delimit, result);
}

inline std::string& tlib::join(const std::vector<std::string>& array,
		const std::string& delimit, std::string& result)
{
	return __join<char> (array, delimit, result);
}

inline std::wstring& tlib::join(const std::vector<std::wstring>& array,
		const std::wstring& delimit, std::wstring& result)
{
	return __join<wchar_t> (array, delimit, result);
}

inline const std::string tlib::join(const std::vector<std::string>& array,
		const std::string& delimit)
{
	std::string result;
	return __join_append<char> (array, delimit, result);
}

inline const std::wstring tlib::join(const std::vector<std::wstring>& array,
		const std::wstring& delimit)
{
	std::wstring result;
	return __join_append<wchar_t> (array, delimit, result);
}



inline const std::wstring tlib::locale_to_wstring(const std::string& src)
{
	std::wstring result;
	return locale_to_wstring(src, result);
}

inline const std::string tlib::wstring_to_locale(const std::wstring &src)
{
	std::string result;
	return wstring_to_locale(src, result);
}

inline const std::wstring tlib::utf8_to_wstring(const std::string& src)
{
	std::wstring result;
	return utf8_to_wstring(src, result);
}

inline const std::string tlib::wstring_to_utf8(const std::wstring &src)
{
	std::string result;
	return wstring_to_utf8(src, result);
}

inline const std::string tlib::utf8_to_locale(const std::string& src)
{
	std::string result;
	return utf8_to_locale(src, result);
}

inline const std::string tlib::locale_to_utf8(const std::string& src)
{
	std::string result;
	return locale_to_utf8(src, result);
}

inline const std::wstring tlib::charset_to_wstring(const std::string& src, const std::string& charset)
{
	std::wstring result;
	return charset_to_wstring(src, charset, result);
}

inline const std::string& tlib::wstring_to_charset(const std::wstring& src, const std::string& charset)
{
	std::string result;
	return wstring_to_charset(src, charset, result);
}

#endif /* _TLIBSTR_H_ */
