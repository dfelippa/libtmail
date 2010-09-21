#############################################################################
#
#  LibTMail
#  Copyright (C) 2010  Thor Qin
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2 of the License, or (at your option) any later version.
# 
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
# 
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
#
#  Author: Thor Qin
#  Bug Report: thor.qin@gmail.com
#
#############################################################################


# Depends: glib, openssl, sigc++

LIB = $(DESTDIR)/lib
INC = $(DESTDIR)/usr/include/tmail

all:
	$(MAKE) -C ./build

clean:
	$(MAKE) -C ./build clean

install:
	install -d $(INC)/tlib $(LIB)
	install -m644 ./build/libtmail.so.* $(LIB)
	-rm $(LIB)/libtmail.so
	ln -s $(LIB)/libtmail.so.* $(LIB)/libtmail.so
	install -m644 ./src/*.h $(INC)
	ldconfig

uninstall:
	rm -f $(LIB)/libtmail.so*
	rm -f -r $(INC)
	ldconfig

.PHONY: all
.PHONY: clean
.PHONY: install
.PHONY: uninstall
