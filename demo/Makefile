all: testsmtp testpop3

testsmtp: testsmtp.cpp
	g++ -o testsmtp testsmtp.cpp -ltmail -ltlib `pkg-config --cflags --libs glib-2.0 sigc++-2.0`

testpop3: testpop3.cpp
	g++ -o testpop3 testpop3.cpp -ltmail -ltlib `pkg-config --cflags --libs glib-2.0 sigc++-2.0`

clean:
	-rm -f testsmtp testpop3

.PHONY: all
.PHONY: clean
