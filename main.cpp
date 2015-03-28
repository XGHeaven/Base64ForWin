#include <iostream>
#include "base64.h"
#include <string>
using namespace std;

int main() {
	string s;
	Base64 base64;

	while (cin >> s) {
		base64.append(s);
	}
	cout << "start calc" << endl;
	base64.atob();
	cout << "calc cemplete : " << endl;
	cout << base64.enString() << endl;

	return 0;
}