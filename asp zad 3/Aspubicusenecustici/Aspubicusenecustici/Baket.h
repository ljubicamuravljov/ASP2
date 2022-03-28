#ifndef _Baket_h_
#define _Baket_h_

#include "Polje.h"
#include<vector>
class Baket {
public:
	int delful;
	int d;
	int nula;
	vector<Polje*> polja;

	friend ostream& operator<<(ostream& os, Baket *b);
};




#endif