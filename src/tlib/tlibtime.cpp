/*
 * tlibtime.cpp
 *
 *  Created on: 2010-6-18
 *      Author: thor
 */

#include "tlibtime.h"
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include "tlibstr.h"
#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#pragma warning(disable : 4996)
#define ABS _abs64
#else
#ifndef ABS
#define ABS abs
#endif
#endif

namespace tlib
{

static const char* week_name[7] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

int match_week(const char* str)
{
	if (strlen(str) < 3)
		return -1;
	for (int i = 0; i < 7; i++)
	{
		if (strncasecmp(str, week_name[i], 3) == 0)
			return i;
	}
	return -1;
}
static const char* month_name[12] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

int match_month(const char* str)
{
	if (strlen(str) < 3)
		return -1;
	for (int i = 0; i < 12; i++)
	{
		if (strncasecmp(str, month_name[i], 3) == 0)
			return i;
	}
	return -1;
}

typedef struct _time_zone_info
{
	const char* name;
	const char* value;
} TimeZoneInfo;
static const TimeZoneInfo time_zone[124] = {
		{ "CETDST", "+0200" },
		{ "EETDST", "+0300" },
		{ "METDST", "+0200" },
		{ "WETDST", "+0100" },
		{ "AESST", "+1100" },
		{ "AWSST", "+0900" },
		{ "AWDT", "+0900" },
		{ "AWST", "+0800" },
		{ "ACDT", "+1030" },
		{ "ACST", "+0930" },
		{ "AEDT", "+1100" },
		{ "AEST", "+1000" },
		{ "AHST", "-1000" },
		{ "AKDT", "-0800" },
		{ "AKST", "-0900" },
		{ "CADT", "+1030" },
		{ "CAST", "+0930" },
		{ "CEDT", "+0200" },
		{ "CEST", "+0200" },
		{ "EEDT", "+0300" },
		{ "EEST", "+0300" },
		{ "HADT", "-0900" },
		{ "HAST", "-1000" },
		{ "IDLE", "+1200" },
		{ "IDLW", "-1200" },
		{ "LIGT", "+1000" },
		{ "MEST", "+0200" },
		{ "MESZ", "+0200" },
		{ "MEWT", "+0100" },
		{ "NZDT", "+1300" },
		{ "NZST", "+1200" },
		{ "SADT", "+1030" },
		{ "WEDT", "+0100" },
		{ "WEST", "+0100" },
		{ "ADT", "-0300" },
		{ "AST", "-0400" },
		{ "BST", "+0100" },
		{ "CAT", "-1000" },
		{ "CCT", "+0800" },
		{ "CDT", "-0500" },
		{ "CET", "+0100" },
		{ "CST", "-0600" },
		{ "CXT", "+0700" },
		{ "DNT", "+0100" },
		{ "EDT", "-0400" },
		{ "EET", "+0200" },
		{ "EST", "-0500" },
		{ "FST", "+0100" },
		{ "FWT", "+0200" },
		{ "GMT", "+0000" },
		{ "GST", "+1000" },
		{ "HAA", "-0300" },
		{ "HAC", "-0500" },
		{ "HAE", "-0400" },
		{ "HAP", "-0700" },
		{ "HAR", "-0600" },
		{ "HAT", "-0230" },
		{ "HAY", "-0800" },
		{ "HDT", "-0900" },
		{ "HNA", "-0400" },
		{ "HNC", "-0600" },
		{ "HNE", "-0500" },
		{ "HNP", "-0800" },
		{ "HNR", "-0700" },
		{ "HNT", "-0330" },
		{ "HNY", "-0900" },
		{ "HST", "-1000" },
		{ "IST", "+0200" },
		{ "JST", "+0900" },
		{ "KST", "+0900" },
		{ "MDT", "-0600" },
		{ "MET", "+0100" },
		{ "MEZ", "+0100" },
		{ "MSD", "+0400" },
		{ "MSK", "+0300" },
		{ "MST", "-0700" },
		{ "NDT", "-0230" },
		{ "NFT", "+1130" },
		{ "NOR", "+0100" },
		{ "NST", "-0330" },
		{ "NZT", "+1200" },
		{ "PDT", "-0700" },
		{ "PST", "-0800" },
		{ "SAT", "+0930" },
		{ "SET", "+0100" },
		{ "SST", "+0200" },
		{ "SWT", "+0100" },
		{ "UTC", "+0000" },
		{ "WAT", "-0100" },
		{ "WDT", "+0900" },
		{ "WET", "+0000" },
		{ "WST", "+0800" },
		{ "YDT", "-0800" },
		{ "YST", "-0900" },
		{ "BT", "+0300" },
		{ "IT", "+0330" },
		{ "JT", "+0730" },
		{ "MT", "+0830" },
		{ "NT", "-1100" },
		{ "A", "+0100" },
		{ "B", "+0200" },
		{ "C", "+0300" },
		{ "D", "+0400" },
		{ "E", "+0500" },
		{ "F", "+0600" },
		{ "G", "+0700" },
		{ "H", "+0800" },
		{ "I", "+0900" },
		{ "K", "+1000" },
		{ "L", "+1100" },
		{ "M", "+1200" },
		{ "N", "-0100" },
		{ "O", "-0200" },
		{ "P", "-0300" },
		{ "Q", "-0400" },
		{ "R", "-0500" },
		{ "S", "-0600" },
		{ "T", "-0700" },
		{ "U", "-0800" },
		{ "V", "-0900" },
		{ "W", "-1000" },
		{ "X", "-1100" },
		{ "Y", "-1200" },
		{ "Z", "+0000" }
};

const char* match_timezone(const char* str, size_t* name_len)
{
	if (strlen(str) < 1)
		return 0;
	for (int i = 0; i < 124; i++)
	{
		if (strncasecmp(str, time_zone[i].name, strlen(time_zone[i].name)) == 0)
		{
			*name_len =  strlen(time_zone[i].name);
			return time_zone[i].value;
		}
	}
	return 0;
}



TimeSpan::TimeSpan(SpanUnit unit)
: _span(0), _unit(unit)
{
}

TimeSpan::TimeSpan(time_t span, SpanUnit unit)
: _span(span), _unit(unit)
{
}

TimeSpan::TimeSpan(const TimeSpan& other)
: _span(other._span), _unit(other._unit)
{

}

void TimeSpan::set_unit(SpanUnit unit)
{
	_unit = unit;
}

TimeSpan::SpanUnit TimeSpan::get_unit() const
{
	return _unit;
}

void TimeSpan::set_total_seconds(long int span)
{
	_span = span;
}

time_t TimeSpan::get_total_seconds() const
{
	return _span;
}

time_t TimeSpan::get_seconds() const
{
	if (_unit == TimeSpan::seconds)
	{
		return ABS(_span);
	}
	else
	{
		return ABS(_span) % 60;
	}
}

time_t TimeSpan::get_minutes() const
{
	if (_unit == TimeSpan::seconds)
	{
		return 0;
	}
	else if (_unit == TimeSpan::minutes)
	{
		return ABS(_span) / 60;
	}
	else
	{
		return (ABS(_span) % 3600) / 60;
	}
}

time_t TimeSpan::get_hours() const
{
	if (_unit == TimeSpan::seconds)
	{
		return 0;
	}
	else if (_unit == TimeSpan::minutes)
	{
		return 0;
	}
	else if (_unit == TimeSpan::hours)
	{
		return (ABS(_span) / 3600);
	}
	else
	{
		return ((ABS(_span) % (3600 * 24)) / 3600);
	}
}

time_t TimeSpan::get_days() const
{
	if (_unit == TimeSpan::seconds)
	{
		return 0;
	}
	else if (_unit == TimeSpan::minutes)
	{
		return 0;
	}
	else if (_unit == TimeSpan::hours)
	{
		return 0;
	}
	else if (_unit == TimeSpan::days)
	{
		return (ABS(_span) / (3600 * 24));
	}
	else if (_unit == TimeSpan::weeks)
	{
		return ((ABS(_span) % (3600 * 24 * 7)) / (3600 * 24));
	}
	else
	{
		return ((ABS(_span) % (3600 * 24 * 365)) / (3600 * 24));
	}
}

time_t TimeSpan::get_weeks() const
{
	if (_unit == TimeSpan::seconds)
	{
		return 0;
	}
	else if (_unit == TimeSpan::minutes)
	{
		return 0;
	}
	else if (_unit == TimeSpan::hours)
	{
		return 0;
	}
	else if (_unit == TimeSpan::days)
	{
		return 0;
	}
	else if (_unit == TimeSpan::weeks)
	{
		return (ABS(_span) / (3600 * 24 * 7));
	}
	else
	{
		return 0;
	}
}

time_t TimeSpan::get_years() const
{
	if (_unit == TimeSpan::seconds)
	{
		return 0;
	}
	else if (_unit == TimeSpan::minutes)
	{
		return 0;
	}
	else if (_unit == TimeSpan::hours)
	{
		return 0;
	}
	else if (_unit == TimeSpan::days)
	{
		return 0;
	}
	else if (_unit == TimeSpan::weeks)
	{
		return 0;
	}
	else
	{
		return (_span / (3600 * 24 * 365));
	}
}

TimeSpan& TimeSpan::operator = (const TimeSpan& other)
{
	_span = other._span;
	return *this;
}

TimeSpan& TimeSpan::operator += (const TimeSpan& other)
{
	_span += other._span;
	return *this;
}

TimeSpan& TimeSpan::operator -= (const TimeSpan& other)
{
	_span -= other._span;
	return *this;
}


bool TimeSpan::is_forward() const
{
	return (_span >= 0);
}

Time::Time()
{
	time(&_tm);
}

Time::Time(time_t tm)
: _tm(tm)
{
}

Time::Time(const Time& other)
: _tm(other._tm)
{
}

Time::Time(const std::string& stime)
{
	time(&_tm);
	parse(stime, format_standard);
}

Time& Time::operator = (const Time& other)
{
	_tm = other._tm;
	return *this;
}

Time& Time::operator += (const TimeSpan& span)
{
	_tm += span.get_total_seconds();
	return *this;
}

Time& Time::operator -= (const TimeSpan& span)
{
	_tm -= span.get_total_seconds();
	return *this;
}

#ifdef WIN32
const std::string __get_time_zone()
{
	TIME_ZONE_INFORMATION timezone;
	GetTimeZoneInformation(&timezone);
	char buf[20];
	memset(buf, 0, 20);
	if (timezone.Bias < 0 )
		sprintf(buf, "+%02d%02d", abs(timezone.Bias / 60), abs(timezone.Bias % 60));
	else
		sprintf(buf, "-%02d%02d", abs(timezone.Bias / 60), abs(timezone.Bias % 60));
	return std::string(buf, 5);
}
#endif

const std::string Time::to_string(TimeForamt format) const
{
	tm tp;
	char buf[128];
	if (format == format_mail)
	{
		get_local_time(tp);
		
#ifdef WIN32
		sprintf(buf, "%s, %02d %s %04d %02d:%02d:%02d ",
				week_name[tp.tm_wday], tp.tm_mday, month_name[tp.tm_mon], tp.tm_year + 1900,
				tp.tm_hour, tp.tm_min, tp.tm_sec);
		strcat(buf, __get_time_zone().c_str());
#elif defined(__linux)
		char fmt[128];
		sprintf(fmt, "%s, %02d %s %04d %02d:%02d:%02d %%z (%%Z)",
				week_name[tp.tm_wday], tp.tm_mday, month_name[tp.tm_mon], tp.tm_year + 1900,
				tp.tm_hour, tp.tm_min, tp.tm_sec);
		locale_t loc = newlocale(LC_ALL, "C", 0);
		strftime_l(buf, 127, fmt, &tp, loc);
		freelocale(loc);
#else
#error Not implement yet.
#endif
		return buf;
	}
	else if (format == format_date)
	{
		get_local_time(tp);
		strftime(buf, 127, "%Y-%m-%d", &tp);
		return buf;
	}
	else if (format == format_time)
	{
		get_local_time(tp);
		strftime(buf, 127, "%H:%M:%S", &tp);
		return buf;
	}
	else if (format == format_utc_date)
	{
		get_utc_time(tp);
		strftime(buf, 127, "%Y-%m-%d", &tp);
		return buf;
	}
	else if (format == format_utc_time)
	{
		get_utc_time(tp);
		strftime(buf, 127, "%H:%M:%S", &tp);
		return buf;
	}
	else if (format == format_utc_standard)
	{
		get_utc_time(tp);
		strftime(buf, 63, "%Y-%m-%d %H:%M:%S", &tp);
		return buf;
	}
	else
	{
		get_local_time(tp);
		strftime(buf, 63, "%Y-%m-%d %H:%M:%S", &tp);
		return buf;
	}
}

time_t tz_seconds(const char* tzvalue)
{
	const char* scan = tzvalue;
	int state = 0;
	bool neg = false;
	int hours = 0;
	int minutes = 0;
	std::string buf;
	while (*scan != '\0')
	{
		if (state == 0)
		{
			if (*scan == '+')
			{
				neg = false;
				state = 1;
			}
			else if (*scan == '-')
			{
				neg = true;
				state = 1;
			}
			else if (isdigit(*scan))
			{
				neg = false;
				buf.push_back(*scan);
				state = 2;
			}
			else
				return 0;
		}
		else if (state == 1) // 0 number
		{
			if (isdigit(*scan))
			{
				buf.push_back(*scan);
				state = 2;
			}
			else
				break;
		}
		else if (state == 2) // 1 number
		{
			if (isdigit(*scan))
			{
				buf.push_back(*scan);
				state = 3;
			}
			else
				break;
		}
		else if (state == 3)  // 2 number
		{
			if (isdigit(*scan))
			{
				buf.push_back(*scan);
				state = 4;
			}
			else
				break;
		}
		else if (state == 4)  // 3 number
		{
			if (isdigit(*scan))
			{
				buf.push_back(*scan);
				state = 5;
			}
			break;
		}
		scan++;
	}
	if (state == 2 || state == 3) // one or two number paser as hour
	{
		if (neg)
			return -(tlib::strto<int>(buf) * 60 * 60);
		else
			return (tlib::strto<int>(buf) * 60 * 60);
	}
	else if (state == 4) // three number
	{
		hours = tlib::strto<int>(buf.substr(0, 1));
		minutes = tlib::strto<int>(buf.substr(1, 2));
		if (neg)
			return -(hours * 60 * 60 + minutes * 60);
		else
			return (hours * 60 * 60 + minutes * 60);
	}
	else if (state == 5)
	{
		hours = tlib::strto<int>(buf.substr(0, 2));
		minutes = tlib::strto<int>(buf.substr(2, 2));
		if (neg)
			return -(hours * 60 * 60 + minutes * 60);
		else
			return (hours * 60 * 60 + minutes * 60);
	}
	else
		return 0;
}

void Time::get_utc_time(struct tm& tm) const
{
#ifdef WIN32
	gmtime_s(&tm, &_tm);
#elif defined(__linux)
	gmtime_r(&_tm, &tm);
#else
#error Not implement.
#endif
}

void Time::set_utc_time(struct tm& tm)
{
#ifdef WIN32
	_tm = _mkgmtime(&tm);
#elif defined(__linux)
	_tm = timegm(&tm);
#else
#error Not implement.
#endif
}

void Time::get_local_time(struct tm& tm) const
{
#ifdef WIN32
	localtime_s(&tm, &_tm);
#elif defined(__linux)
	localtime_r(&_tm, &tm);
#else
#error Not implement.
#endif
}

void Time::set_local_time(struct tm& tm)
{
	_tm = mktime(&tm);
}

static void __parse_date(const std::string& stime, tm& tp)
{
	struct tm tmp;
	memset(&tmp, -1, sizeof(tmp));
	sscanf(stime.c_str(),
		"%d-%d-%d",
		&(tmp.tm_year),
		&(tmp.tm_mon),
		&(tmp.tm_mday));

	if (tmp.tm_year != -1)
		tp.tm_year = tmp.tm_year - 1900;
	if (tmp.tm_mon != -1)
		tp.tm_mon = tmp.tm_mon;
	if (tmp.tm_mday != -1)
		tp.tm_mday = tmp.tm_mday;
}

static void __parse_time(const std::string& stime, tm& tp)
{
	struct tm tmp;
	memset(&tmp, -1, sizeof(tmp));
	sscanf(stime.c_str(),
		"%d:%d:%d",
		&(tmp.tm_hour),
		&(tmp.tm_min),
		&(tmp.tm_sec));
	if (tmp.tm_hour != -1)
		tp.tm_hour = tmp.tm_hour;
	if (tmp.tm_min != -1)
		tp.tm_min = tmp.tm_min;
	if (tmp.tm_sec != -1)
		tp.tm_sec = tmp.tm_sec;
}

static void __parse_date_time(const std::string& stime, tm& tp)
{
	struct tm tmp;
	memset(&tmp, -1, sizeof(tmp));
	sscanf(stime.c_str(),
		"%d-%d-%d %d:%d:%d",
		&(tmp.tm_year),
		&(tmp.tm_mon),
		&(tmp.tm_mday),
		&(tmp.tm_hour),
		&(tmp.tm_min),
		&(tmp.tm_sec));

	if (tmp.tm_year != -1)
		tp.tm_year = tmp.tm_year - 1900;
	if (tmp.tm_mon != -1)
		tp.tm_mon = tmp.tm_mon;
	if (tmp.tm_mday != -1)
		tp.tm_mday = tmp.tm_mday;
	if (tmp.tm_hour != -1)
		tp.tm_hour = tmp.tm_hour;
	if (tmp.tm_min != -1)
		tp.tm_min = tmp.tm_min;
	if (tmp.tm_sec != -1)
		tp.tm_sec = tmp.tm_sec;
}


void Time::parse(const std::string& stime, TimeForamt format)
{
	tm tp;
	if (format == format_mail)
	{
		const char* scan = stime.c_str();
		int state = 0;
		int value = 0;
		time_t tz = 0;
		bool oldtime = false;
		const char* tzstr = 0;
		std::string buf;
		while (*scan != '\0')
		{
			if (state == 0) // Start parse time
			{
				if (*scan == ' ' || *scan == '\t')
				{
				}
				else if ((value = match_week(scan)) >= 0)
				{
					tp.tm_wday = value;
					scan += 2;
					state = 1;
				}
				else if (isdigit(*scan)) // Parse as day
				{
					buf.push_back(*scan);
					state = 2;
				}
			}
			else if (state == 1)	// Need day of month
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					state = 2;
				}
				else if ((value = match_month(scan)) >= 0)
				{
					tp.tm_mon = value;
					scan += 2;
					state = 14;
					oldtime = true;
				}
			}
			else if (state == 2) // Need day of month
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
				}
				else
				{
					scan--;
				}
				value = tlib::strto<int>(buf);
				tp.tm_mday = value;
				state = 3;
				buf.clear();
			}
			else if (state == 3) // Need month name.
			{
				if (isspace(*scan))
				{
				}
				else if ((value = match_month(scan)) >= 0)
				{
					tp.tm_mon = value;
					scan += 2;
					state = 4;
				}
			}
			else if (state == 4) // Need year
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					state = 5;
				}
			}
			else if (state == 5) // Calculate year
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					if (buf.length() == 4)
					{
						tp.tm_year = tlib::strto<int>(buf) - 1900;
						buf.clear();
						if (oldtime)
							break;
						else
							state = 6;
					}
				}
				else
				{
					value = tlib::strto<int>(buf);
					if (value < 50)
					{
						tp.tm_year = 2000 + value - 1900;
					}
					else
					{
						tp.tm_year = value;
					}
					buf.clear();
					if (oldtime)
						break;
					else
						state = 6;
				}
			}
			else if (state == 6) // Now need hour.
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					state = 7;
				}
			}
			else if (state == 7) // Calculate hour
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					if (buf.length() == 2)
					{
						tp.tm_hour = tlib::strto<int>(buf);
						state = 8;
						buf.clear();
					}
				}
				else
				{
					tp.tm_hour = tlib::strto<int>(buf);
					state = 8;
					buf.clear();
				}

			}
			else if (state == 8) // Need minutes.
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					state = 9;
				}
			}
			else if (state == 9) // Calculate minutes
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					if (buf.length() == 2)
					{
						tp.tm_min = tlib::strto<int>(buf);
						state = 10;
						buf.clear();
					}
				}
				else
				{
					tp.tm_min = tlib::strto<int>(buf);
					state = 10;
					buf.clear();
				}
			}
			else if (state == 10) // Need seconds.
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					state = 11;
				}
			}
			else if (state == 11) // Calculate seconds
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					if (buf.length() == 2)
					{
						tp.tm_sec = tlib::strto<int>(buf);
						if (oldtime)
							state = 16;
						else
							state = 12;
						buf.clear();
					}
				}
				else
				{
					tp.tm_sec = tlib::strto<int>(buf);
					if (oldtime)
						state = 16;
					else
						state = 12;
					buf.clear();
				}
			}
			else if (state == 12) // Now need time zone info, like: +0800 ...
			{
				size_t name_len = 0;
				if (*scan == '+' || *scan == '-')
				{
					buf.push_back(*scan);
					state = 13;
				}
				else if ((tzstr = match_timezone(scan, &name_len)) != 0)
				{
					tz = tz_seconds(tzstr);
					break;
				}
			}
			else if (state == 13) // Calculate time zone
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
					if (buf.length() == 5)
					{
						tz = tz_seconds(buf.c_str());
						buf.clear();
						if (oldtime)
							state = 4;
						else
							break;
					}
				}
				else
				{
					tz = tz_seconds(buf.c_str());
					buf.clear();
					if (oldtime)
						state = 4;
					else
						break;
				}
			}
			else if (state == 14) // Is a asc date time format.
			{
				if (isdigit(*scan)) // Parse as day
				{
					buf.push_back(*scan);
					state = 15;
				}
			}
			else if (state == 15) // Need day of month
			{
				if (isdigit(*scan))
				{
					buf.push_back(*scan);
				}
				else
				{
					scan--;
				}
				value = tlib::strto<int>(buf);
				tp.tm_mday = value;
				state = 6;
				buf.clear();
				oldtime = true;
			}
			else if (state == 16) // Need time zone name or year
			{
				size_t name_len = 0;
				if (*scan == '+' || *scan == '-')
				{
					buf.push_back(*scan);
					state = 13;
				}
				else if ((tzstr = match_timezone(scan, &name_len)) != 0)
				{
					tz = tz_seconds(tzstr);
					scan += (name_len - 1);
					state = 4;
				}
			}

			scan++;
		}
		set_utc_time(tp);
		_tm -= tz;
	}
	else if (format == format_date)
	{
		get_local_time(tp);
		__parse_date(stime, tp);
		set_local_time(tp);
	}
	else if (format == format_time)
	{
		get_local_time(tp);
		__parse_time(stime, tp);
		set_local_time(tp);
	}
	else if (format == format_utc_date)
	{
		get_utc_time(tp);
		__parse_date(stime, tp);
		set_utc_time(tp);
	}
	else if (format == format_utc_time)
	{
		get_utc_time(tp);
		__parse_time(stime, tp);
		set_utc_time(tp);
	}
	else if (format == format_utc_standard)
	{
		get_utc_time(tp);
		__parse_date_time(stime, tp);
		set_utc_time(tp);
	}
	else
	{
		get_local_time(tp);
		__parse_date_time(stime, tp);
		set_local_time(tp);
	}
}

void Time::update()
{
	time(&_tm);
}


} // End of namespace ...

const tlib::Time operator + (const tlib::Time& tm, const tlib::TimeSpan& span)
{
	tlib::Time result(tm);
	result += span;
	return result;
}
const tlib::Time operator - (const tlib::Time& tm, const tlib::TimeSpan& span)
{
	tlib::Time result(tm);
	result -= span;
	return result;
}
const tlib::TimeSpan operator - (const tlib::Time& tm1, const tlib::Time& tm2)
{
	return tlib::TimeSpan(tm1._tm - tm2._tm);
}
const tlib::TimeSpan operator + (const tlib::TimeSpan& span1, const tlib::TimeSpan& span2)
{
	tlib::TimeSpan result(span1);
	result += span2;
	return result;
}
const tlib::TimeSpan operator - (const tlib::TimeSpan& span1, const tlib::TimeSpan& span2)
{
	tlib::TimeSpan result(span1);
	result -= span2;
	return result;
}


