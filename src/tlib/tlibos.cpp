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

#include "tlibos.h"
#ifdef WIN32
#  ifndef _WINSOCKAPI_
#    define _WINSOCKAPI_
#  endif
#  define _WIN32_WINNT 0x0500
#  define WINVER 0x0500
#  include <windows.h>
#elif defined(__linux)
#  include <unistd.h>
#endif

namespace tlib
{

const std::string gethostname()
{
	char hostname[512] = {0};
#ifdef WIN32
	DWORD host_size = 512;
	if (!GetComputerNameExA(ComputerNameDnsFullyQualified, hostname, &host_size))
		strcpy_s(hostname, 512, "computer.local");
#elif defined(__linux)
	::gethostname(hostname, 512);
#else
#error Not implements.
#endif
	return hostname;
}









}
