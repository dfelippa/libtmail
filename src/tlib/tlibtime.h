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

#ifndef TLIBTIME_H_
#define TLIBTIME_H_

#include "tlibbase.h"
#include "tlibstr.h"
#include <string>
#include <time.h>

namespace tlib
{

class TimeSpan
{
public:
	typedef enum _span_unit
	{
		unit_second,
		unit_minute,
		unit_hour,
		unit_day,
		unit_week,
		unit_year

	} SpanUnit;

	static const SpanUnit seconds = unit_second;
	static const SpanUnit minutes = unit_minute;
	static const SpanUnit hours = unit_hour;
	static const SpanUnit days = unit_day;
	static const SpanUnit weeks = unit_week;
	static const SpanUnit years = unit_year;

	explicit TimeSpan(SpanUnit unit = TimeSpan::seconds);
	explicit TimeSpan(time_t span, SpanUnit unit = TimeSpan::seconds);
	TimeSpan(const TimeSpan& other);

	void set_unit(SpanUnit unit);
	TimeSpan::SpanUnit get_unit() const;
	void set_total_seconds(long int span);
	time_t get_total_seconds() const;
	time_t get_seconds() const;
	time_t get_minutes() const;
	time_t get_hours() const;
	time_t get_days() const;
	time_t get_weeks() const;
	time_t get_years() const;
	bool is_forward() const;
	TimeSpan& operator = (const TimeSpan& other);
	TimeSpan& operator += (const TimeSpan& other);
	TimeSpan& operator -= (const TimeSpan& other);
private:
	time_t _span;
	SpanUnit _unit;
};

class Time
{
public:
	typedef enum _time_format
	{
		_format_standard,
		_format_date,
		_format_time,
		_format_utc_standard,
		_format_utc_date,
		_format_utc_time,
		_format_mail
	} TimeForamt;
	static const TimeForamt format_standard = _format_standard;
	static const TimeForamt format_date = _format_date;
	static const TimeForamt format_time = _format_time;
	static const TimeForamt format_utc_standard = _format_utc_standard;
	static const TimeForamt format_utc_date = _format_utc_date;
	static const TimeForamt format_utc_time = _format_utc_time;
	static const TimeForamt format_mail = _format_mail;

	Time();
	explicit Time(time_t tm);
	Time(const Time& other);
	explicit Time(const std::string& stime);
	const std::string to_string(TimeForamt format = format_standard) const;
	void parse(const std::string& stime, TimeForamt format = format_standard);
	inline void parse(const std::wstring& stime, TimeForamt format = format_standard);
	void get_utc_time(struct tm& tm) const;
	void set_utc_time(struct tm& tm);
	void get_local_time(struct tm& tm) const;
	void set_local_time(struct tm& tm);
	void update();

	Time& operator = (const Time& other);
	Time& operator += (const TimeSpan& span);
	Time& operator -= (const TimeSpan& span);
	time_t _tm;
};

inline void Time::parse(const std::wstring& stime, TimeForamt format)
{
	parse(wstring_to_locale(stime), format);
}

}

const tlib::Time operator + (const tlib::Time& tm, const tlib::TimeSpan& span);
const tlib::Time operator - (const tlib::Time& tm, const tlib::TimeSpan& span);
const tlib::TimeSpan operator - (const tlib::Time& tm1, const tlib::Time& tm2);
const tlib::TimeSpan operator + (const tlib::TimeSpan& span1, const tlib::TimeSpan& span2);
const tlib::TimeSpan operator - (const tlib::TimeSpan& span1, const tlib::TimeSpan& span2);

#endif /* TLIBTIME_H_ */
