# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#   < tmail-1.0 >
#
#     Created on: 2010-7-23
#         Author: Thor Qin
#          EMail: thor.qin@gmail.com
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Depends: glib, openssl, sigc++

LIB = $(DESTDIR)/lib
INC = $(DESTDIR)/usr/include/tmail

all:
	$(MAKE) -C ./build

clean:
	$(MAKE) -C ./build clean

install:
	install -d $(INC)/tlib $(LIB)
	install -m644 ./build/libtmail-1.0.so $(LIB)
	install -m644 ./src/*.h $(INC)
	install -m644 ./src/tlib/*.h $(INC)/tlib
	ldconfig

uninstall:
	rm -f $(LIB)/libtmail-1.0.so $(LIB)/libtmail.so.1
	rm -f -r $(INC)
	ldconfig

.PHONY: all
.PHONY: clean
.PHONY: install
.PHONY: uninstall