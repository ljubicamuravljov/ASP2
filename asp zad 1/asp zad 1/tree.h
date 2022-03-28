#ifndef _tree_h_
#define _tree_h_
#include<iostream>
#include "node.h"
#include <list>
#include<cstdlib>
#include <fstream>
using namespace std;

class Tree {
	Node* root;
	int h,max;

public:
	Tree() {
		root = NULL;
		h = 0; max = 0;
	}
	Tree(Node* koren) {
		root = koren;
		h = 0; max = 1;
	}
	void add(Node* nov);
	void addfromfile(string ime);
	Node* search(string klj,int pom); //dodaj dohvatanje i ispis reci
	Node* getroot() const { return root; };
	Node* succ(Node* tren);
	Node* mini(Node* root);
	Node* maxi(Node* root);
	void ispis() const;
	void Delete_node(string k,string t);
	string maxprevodi() const;
	void printInorder() const;
	void smanjivanje(Node* root);
	
	~Tree();


	
};


#endif