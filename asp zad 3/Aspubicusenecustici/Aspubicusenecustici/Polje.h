#ifndef _Polje_h_
#define _Polje_h_


#include <iostream>

#include<string>

using namespace std;
class Polje {
	string status;
	int key;
	string* info;


public:
	Polje() {
		status = "empty"; key = 0; info = nullptr;
	}
	string getStatus() { return status; }
	int getKey() { return key; }
	

	void setStatus(string s) { status = s; }
	void setKey(int k) { key = k; }
	void setInfo(string* i) { info = i; }
	string* getInfo() { return info; }
};



#endif