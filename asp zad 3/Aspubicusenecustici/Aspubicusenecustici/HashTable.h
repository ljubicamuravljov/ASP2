#ifndef _HashTable_h_
#define _HashTable_h_

#include "Info.h"
#include "Baket.h"
#include <iostream>
#include "Address.h"
#include<string>
#include<math.h> 
#include<vector>
#include <fstream>

using namespace std;



class HashTable{
	int k;
	int p;
	int akt;
	int b;
	int c;
	Baket** tabela;
	
	
	int numkeys;
	//Info* inform;


	int HashF(int key, int p);

public:
	int flag;
	HashTable(int ka, int pe) :k(ka), p(int(pow(2,pe))),numkeys(0) {
		tabela = new Baket*[p];
		for (int i = 0; i < p; i++) {
			tabela[i] = new Baket();
		}

		cout << "Uneti vrednost c za Kvadratno pretrazivanje: ";
		cin >> c;
		cout << "\nUneti vrednost pocetne dubine: ";
		cin >> b;

	}
	HashTable() = default;
	void pInsertKey(int key, string* info);
	string* findKey(int key);
	int* uHash(int key);
	bool deleteKey(int key);
	bool insertKey(int key, string* inf);
	void clear();
	int keyCount() {
		return numkeys;
	}
	int tableSize() { return p; }
	double fillRatio() { return numkeys / p; }
	friend ostream& operator<<(ostream& os, HashTable Tab);

};
#endif