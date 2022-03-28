#ifndef _Node_h_
#define _Node_h_

#include<iostream>
#include<string>
using namespace std;


class Node {
	int trenpodst = 0;
	int trenklj = 0;
	int minpodst;
	int maxpodst;
	int index=0;
	int lvl=0;
	int brojac=0;
	
	int maxkljuc;

	string* kljucevi = new string[maxkljuc];
	Node** podstabla = new Node*[maxpodst];

	Node* otac = nullptr;;

	//struct Elemk {
	//	string kljuc;
	//	Elemk* next;
	//	Elemk* prev;

	//	Elemk(string k,Elemk*n= nullptr,Elemk* p=nullptr):kljuc(k),next(n),prev(p){}


	//};
	//struct Elemp {
	//	Node* podst;
	//	Elemp* next;
	//	Elemp* prev;

	//	Elemp(Node* p, Elemp* n = nullptr,Elemp* pr=nullptr) :podst(p), next(n),prev(pr) {}
	//};

	//Elemk* prvik = nullptr;
	//Elemp* prvip = nullptr;

public:
	Node(int minp,int maxp,int maxk):minpodst(minp),maxpodst(maxp),maxkljuc(maxk){
		for (int i = 0; i < maxpodst; i++) {
			podstabla[i] = nullptr;
	}
	}

	void setfather(Node* f) { otac = f; }

	void operator+=(string klj);

	void dodajpodst(Node* n);
	bool mogucedod() { return trenklj < maxkljuc; }
	int gettrenpodst() const { return trenpodst; }
	int gettrenklj() const { return trenklj; }
	int getminpods() const { return minpodst; }
	int getmaxpodst() const { return maxpodst; }
	
	int getindex()const { return index; }
	int getbrojac()const { return brojac;}
	void settrenklj(int k) { trenklj = k; }
	void setpodst(int k) { trenpodst = k; }
	void setbroj(int b) { brojac = b; }
	int getlvl()const { return lvl; }
	void setlvl(int l) { lvl = l; }
	void dodkljuc() { trenklj++; }
	void odkljuc() { trenklj--; }
	Node** getpodstabla()const { return podstabla; }
	Node* getfather() const { return otac; }
	string* getkljucevi()const { return kljucevi; }
	void setindex(int i) { index = i; }
	friend ostream& operator<<(ostream& os,const Node& n);
};




#endif