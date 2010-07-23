/*
 * tlibptr.cpp
 *
 *  Created on: 2010-7-5
 *      Author: thor
 */

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
