#ifndef _Stablo_h_
#define _Stablo_h_
#include "Node.h"

#include<list>

#include <fstream>
class Stablo {
	int red;
	//minp za sve cvorove, max je red, maxkljuceva je red-1
	int minp = ceil((2 * red - 1) / 3);

	//maxp za koren, minp za koren=2;
	int maxp = 2 * floor((2 * red - 2) / 3) + 1;
 
	Node* koren = new Node(2, maxp, maxp - 1);
	
	void dodajl(Node* pom,string klj,int brojac);
	void dodajd(Node* pom, string klj, int brojac);
	void preklapanjel(Node* pom, string klj, int brojac);
	void preklapanjed(Node* pom, string klj, int brojac);
	string* makestring(int d, string klj, Node* levi,string srednji,Node*desni);

public:
	Stablo(int b=0):red(b){ }


	void inorder(string klj);

	bool pronadji(string klj);
	void setred(int b) { red = b; }
	void resetbr();
	Node* getkoren() const { return koren; }
	void dodajizdat(string name);
	bool operator+=(string klj);
	bool operator-=(string klj);
	friend ostream& operator<<(ostream& os,Stablo* s);
};
#endif
