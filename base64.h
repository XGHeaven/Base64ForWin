#ifndef XGHBASE64
#define XGHBASE64

#include <iostream>
#include <string>
using std::string;

class Base64 {
private:
	string str;
	string estr;
	string dstr;

public:
	static const char * map;
	static const unsigned char mask2 = 3;
	static const unsigned char mask4 = 15;
	static const unsigned char mask6 = 63;
	static const unsigned int mask32_8 = 255 << 24;
public:
	// constructor
	Base64(){}
	Base64(string initStr):str(initStr){}

	// append string to str
	Base64 & append(string & appendStr) {
		str += appendStr;
		return *this;
	}

	// encode base64
	Base64 & atob();

	// decode base64
	Base64 & btoa();

	// get string
	string & enString() {
		return estr;
	}
};


#endif