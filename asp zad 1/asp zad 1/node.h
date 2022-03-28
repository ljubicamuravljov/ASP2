#ifndef _node_h_
#define _node_h_
#include<iostream>
#include<cstdlib>
#include <string>
#include <cstring>
using namespace std;

class Node {

	int br,lvl;
	string key, trans;
	Node* levi, * desni, * otac;

public:
	Node() {
		key = trans = "-";
		br = 0;
		levi = desni = otac = NULL;
	}
	Node(string ke, string tra) {
		key = ke; trans = tra;
		br = 1;
		levi = desni = otac = NULL;
	}
	Node(string ke, string tra,int l) {
		key = ke; trans = tra;
		br = 1;
		lvl = l;
		levi = desni = otac = NULL;
	}
	void set(string ke, string tra) {
		key = ke; trans = tra;
		levi = desni = otac = NULL;

	}
	void sett(string k, string t) {
		key = k; trans = t;
	}
	void setlvl(int l) {	lvl = l;}
	void brpov() { br++;}
	int getlvl() const { return lvl;}
	void changetransnum(int a) { br = a;}
	void left(Node* temp) { levi = temp;}
	void right(Node* temp) { desni = temp;}
	void papa(Node* temp) { otac = temp;}
	string getkey() const{ return key; }
	string gettrans() const { return trans;}
	Node* getright() const { return desni;}
	Node* getleft() const { return levi;}
	Node* getpapa() const { return otac; }
	int gettransnum() const { return br; }
	//~Node() {
	//	delete[] key;
	//	delete[] trans;
	//}
};






#endif