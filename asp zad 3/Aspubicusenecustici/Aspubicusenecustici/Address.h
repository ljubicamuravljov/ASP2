#ifndef _Address_h_
#define _Address_h_


class Address {
	int i = 0;

public:
	int getAddress(int key, int a, int n, int c) {
		i++;
		return (a + c * i * i)%n;

	};
	int geti() { return i; }
};





#endif