/*
 * tlibsys.cpp
 *
 *  Created on: 2010-7-5
 *      Author: thor
 */

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
