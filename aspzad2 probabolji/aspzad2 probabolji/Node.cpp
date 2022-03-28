#include "Node.h"

void Node::operator+=(string klj)
{
	trenklj++;
	if (kljucevi[0] == "") {
		kljucevi[0] = klj;
		
		return;
	}
	int i = 0;
	while (kljucevi[i] < klj) {
		if (kljucevi[i] == "") { kljucevi[i] = klj; return; }
		i++;

	}
	int j = i;
	for (int i = maxkljuc - 1; i > j; i--) {
		kljucevi[i] = kljucevi[i - 1];
	}
	kljucevi[j] = klj;

	//Elemk* tren = prvik;
	//Elemk* pred = nullptr;
	//if (!prvik) {
	//	trenklj++;
	//	prvik->kljuc = klj;
	//	return;
	//}
	//while (tren && tren->kljuc<klj) {

	//	pred = tren;
	//	tren = tren->next;

	//}

	//Elemk* nov = new Elemk(klj);
	//nov->prev = pred;
	//nov->next = tren;

	//pred->next = nov;
	//tren->prev = nov;
	//trenklj++;



	
	return;
}

void Node::dodajpodst(Node* n)
{
	trenpodst++;
	int i = 0;
	if (podstabla[i] == nullptr) { podstabla[i] = n; n->setindex(i); return; }

	while (podstabla[i]->getkljucevi()[0] < n->getkljucevi()[0]) {

		i++;
	}
	if (!podstabla[i]) { podstabla[i] = n; return; }
	int j = i;
	for (i = maxpodst - 1; i > j; i--) {
		podstabla[i] = podstabla[i - 1];
	}
	podstabla[j] = n;
	n->setindex(j);
	return;
	

}

ostream& operator<<(ostream& os, const Node& n)
{
	os << " | ";
	for (int i = 0; i < n.gettrenklj(); i++) {
		os << n.getkljucevi()[i] << " ";
	}
	os << " | ";
	return os;

}
