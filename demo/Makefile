all: testsmtp
testsmtp: testsmtp.cpp
	g++ -o testsmtp testsmtp.cpp -ltmail -ltlib `pkg-config --cflags --libs glib-2.0 sigc++-2.0`
