#include "Baket.h"

ostream& operator<<(ostream& os, Baket* b)
{
	
	if (b->polja.size() == 0) { os << "EMPTY "; }
	else {
		for (int i = 0; i < b->polja.size(); i++) {
			if (b->polja[i]) {

				os << b->polja[i]->getKey() << " ";
			}
			else {
				os << " DELETED ";
			}

		}
	}


	return os;
}
