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

#include "tlibptr.h"
#ifdef WIN32
#include <windows.h>
#pragma warning( disable : 4290 )
#elif defined(__linux)
#include <glib.h>
#endif

namespace tlib
{

void Object::reference(void)
{
#ifdef WIN32
	InterlockedIncrement(&_ref);
#elif defined(__linux)
	g_atomic_int_inc(&_ref);
#else
#error Not implement.
#endif
}

void Object::dereference(void)
{
#ifdef WIN32
	if (InterlockedDecrement(&_ref) == 0)
		delete this;
#elif defined(__linux)
	if (g_atomic_int_dec_and_test(&_ref))
		delete this;
#else
#error Not implement.
#endif
}



}
