#include "base64.h"

#ifdef XGHBASE64
#include <iostream>

// cmonmet
// using std::cout;
// using std::endl;
// commet end

const char * Base64::map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

Base64 & Base64 :: atob () {
	int len = str.length();
	// cout << len << endl;
	int i;
	unsigned short int flag = 0;
	unsigned int ibs = 0; // 4 int base64 string
	estr = "";

	for (i=0; i<len; i++) {
		unsigned char c = str[i];

		switch(flag) {
			case 0:
				ibs <<= 8;
				ibs |= (c ^ mask2) & c;
				// cout <<ibs<<endl;
				ibs <<= 2; // 2+2
				ibs |= c & mask2;
				flag ++;
				break;
			case 1:
				ibs <<= 8;
				ibs |= (c ^ mask4) & c;
				ibs <<= 2; //2+4
				ibs |= c & mask4;
				flag ++;
				break;
			case 2:
				ibs <<=8;
				ibs |= (c ^ mask6) & c;
				ibs <<= 2;
				ibs |= c & mask6;

				// let do it
				flag = 0;

				// cout << ibs <<endl;

				for (int j=0; j<4; j++) {
					estr += map[ibs >> 24];
					ibs <<= 8;
				}
				break;
		}
		// cout << ibs <<endl ;
	}

	if (flag) {
		ibs <<= (3 - flag) * 10;
		// cout<<ibs;
		int j = 0;
		for (j=0; j<=flag; j++) {
			estr += map[ibs >> 24];
			ibs <<= 8;
		}
		for (;j<4;j++) estr += "=";
	}

	return *this;
}



#endif