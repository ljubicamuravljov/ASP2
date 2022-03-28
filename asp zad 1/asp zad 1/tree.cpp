#include "tree.h"

void Tree::add(Node* nov)
{
	if (root == NULL) {
		root = nov;
		root->setlvl(0);
	}
	else {
		int broj;
		Node* tren = root;
		Node* pom=new Node() ,*pom2=new Node();
		while (tren) {
			pom = tren;
				
			if (nov->getkey().compare(tren->getkey())<0) {
				tren = tren->getleft();
			}
			else if (nov->getkey().compare(tren->getkey()) == 0) {
				tren->brpov();
				broj = tren->gettransnum();
				if (broj > this->max) max = broj;
				nov->changetransnum(broj);
				if (!tren->getright()) {
					/*pom = tren;*/
					tren->right(nov);
					nov->papa(tren);
					
					nov->setlvl(tren->getlvl() + 1);
					return;
					
				}
				else {
					
					
					tren = tren->getright();
					while (tren->getleft()) {
						tren = tren->getleft();
					}
					pom = tren;
					pom->left(nov);
					nov->papa(pom);
					nov->setlvl(pom->getlvl()+1);

					
					
					while (this->succ(pom)) {
						pom2 = this->succ(pom);

						if (pom2->getkey().compare(pom->getkey())!=0) {
							break;
						}
						else {
							pom2->changetransnum(broj);
						}
						pom = pom2;
					}
					if (nov->getlvl() > this->h) h = nov->getlvl();
					return;
				}

			}
			else {
				tren = tren->getright();
			}
		}
		if (nov->getkey().compare(pom->getkey())<0) {
			pom->left(nov);
		}
		else {
			pom->right(nov);
		}
		nov->papa(pom);
		nov->setlvl(pom->getlvl() + 1);

	/*	nov->changetransnum(pom->gettransnum() + 1);
		pom->changetransnum(nov->gettransnum());
		while (this->succ(pom)) {
			pom2 = this->succ(pom);
			if (pom2->getkey() != pom->getkey()) {
				break;
			}
			else {
				pom2->brpov();
			}
			pom = pom2;
		}*/

		if (nov->getlvl() > this->h) h = nov->getlvl();
		}

}

void Tree::addfromfile(string ime)
{
	Node* nov;
	string klj, tra;
	ifstream fil(ime);
	while (fil >> klj) {
		fil >> tra;
		nov = new Node(klj, tra);
		this->add(nov);

	}
	

	fil.close();

}

Node* Tree::search(string klj,int pom)
{
	if (!this->root) { cout << "\n Prvo kreirajte stablo! \n"; return NULL; }
	Node* tren = root;
	string k = "";
	while (tren) {
		int a = klj.compare(tren->getkey());
		if (a == 0) { 
			if (pom == 1) { return tren; }
			k += tren->gettrans();
			k += " ";
			while (1) {
				if (this->succ(tren)) {
					if (this->succ(tren)->getkey().compare(klj) == 0) {
						tren = this->succ(tren);
						k += tren->gettrans();
						k += " ";
						if (!(this->succ(tren))) {
							cout << k;
							return tren;
						}
					}
					else cout << k; return tren;
				}
				return tren;

			}
			 }
		else if (a > 0) {
			tren = tren->getright();
		}
		else tren = tren->getleft();

	}
	cout << "Nema prevoda";
	return NULL;
}

Node* Tree::succ(Node* tren)
{
	Node* temp = tren;
	if (temp->getright()) {
		return this->mini(temp->getright());
	}
	else {
		Node* pret = temp->getpapa();
		while (pret and temp == pret->getright()) {
			temp = pret;
			pret = pret->getpapa();
		}
		return pret;
	}

}
Node* Tree::mini(Node* root)
{
	Node* tren = root;
	while (tren->getleft()) {
		tren = tren->getleft();
	}
	return tren;
}
Node* Tree::maxi(Node* root)
{
	Node* tren = root;
	while(tren->getright()) {
		tren = tren->getright();
	}
	return tren;
}

void Tree::ispis() const
{
	if (!this->root) { cout << "\n Prvo kreirajte stablo! \n"; return; }
	list <Node*> stek;
	string space = "      ";
	Node* pomocni = new Node();
	Node* tren = root;
	stek.push_back(root);
	while (!stek.empty()) {
		tren = stek.back();
		stek.pop_back();
		if (tren->getkey() == "-") {
			cout <<string(tren->getlvl(), '\t\t') <<"x:x\n";
			continue;
		}
		else {
			cout << string(tren->getlvl(), '\t\t') << tren->getkey() << " : " << tren->gettrans() << endl;
		}
		/*pomocni->setlvl(tren->getlvl() + 1);*/
		pomocni = new Node("-", "-", tren->getlvl() + 1);
		if (!tren->getright() and !tren->getleft()) continue;
			if (tren->getleft()) { stek.push_back(tren->getleft()); }
		
		else if(tren->getlvl()!=h) stek.push_back(pomocni);
		if (tren->getright()) { stek.push_back(tren->getright()); }
		
		else if(tren->getlvl()!=h) stek.push_back(pomocni);
	
		/*delete[] pomocni;*/

	}
	//delete[] pomocni;


}

void Tree::Delete_node(string k,string t)
{
	if (!this->root) { cout << "\n Prvo kreirajte stablo! \n"; return; }
	Node* pom = root;
	Node* pom2 = NULL,*pom3=NULL;
	Node* tren;

	if (this->search(k,1)) {
		tren = this->search(k,1);
		while (1) {
			if (tren->gettrans().compare(t) != 0) {
				tren = this->succ(tren);
				if (tren->getkey() != k) cout << "Cvor nije pronadjen!\n"; return;
			}
			else break;
		}
	/*	if (tren = root) {
			if (tren->getright()) {
				root->left(tren->getleft());
				smanjivanje(tren->getright());
			}
			else { root = tren->getleft();root->right(tren->getright()); }
			delete tren;

		}*/
		if (!tren->getleft() and !tren->getright()) {
			if (tren == root) { 
				delete tren;
				return; }
			pom2 = tren->getpapa();
			if (pom2->getleft() == tren) {
				pom2->left(NULL);
			}
			else {
				pom2->right(NULL);
			}delete tren;
		}
		else if ((!tren->getleft() and tren->getright()) or (tren->getleft() and !tren->getright())) {
			if (tren == root) { 
				if (tren->getright()) root = tren->getright();
				else root = tren->getleft();

				delete tren; return; }
			pom = tren->getpapa();
			pom2 = tren->getright() ? tren->getright():tren->getleft() ;
			if (pom->getright() == tren) {
				pom->right(pom2);
			}
			else {
				pom->left(pom2);
			}
			smanjivanje(pom2);
			pom2->papa(pom);
			delete tren;

		}
		else {

			pom = succ(tren);
			tren->sett(pom->getkey(),pom->gettrans());
			pom2 = pom->getright();
			pom3= pom->getpapa();
			/*if(tren==root)*/
			if (pom == tren->getright()) {
				tren->getright()->papa(tren);
				tren->right(pom->getright());
				
				delete pom;
				return;


			}
			if(pom3!= root) pom3->left(pom2);
			if (pom2) {
				smanjivanje(pom2);
			}
			delete pom;
		/*	delete tren;*/


		}

	}
	else {
		cout << "\nUneti kljuc nije u stablu.\n";
	}


}

string Tree::maxprevodi() const
{
	if (!this->root) { cout << "\n Prvo kreirajte stablo! \n"; return "/"; }
	list <Node*> stack;
	stack.push_back(root);
	Node* tren = root;
	while (!stack.empty()) {
		tren = stack.back();
		stack.pop_back();

		while (tren) {
			if (tren->gettransnum() == max) return tren->getkey();

			if (tren->getright()) {
				stack.push_back(tren->getright());
			}
			tren = tren->getleft();


		}


	}


	return string();
}

void Tree::printInorder() const
{
	list <Node*> stek;
	Node* next = root;
	while (1) {
		while (next) {
			stek.push_back(next);
			next = next->getleft();

		}
		if (!stek.empty()) {
			next = stek.back();
			stek.pop_back();
			cout << next->getkey() << " ";
			next = next->getright();

		}
		else return;




	}


}

void Tree::smanjivanje(Node* root)
{
	list <Node*> stack;
	stack.push_back(root);
	Node* tren = root;
	while (!stack.empty()) {
		tren = stack.back();
		stack.pop_back();

		while (tren) {
			tren->setlvl(tren->getlvl() - 1);

			if (tren->getright()) {
				stack.push_back(tren->getright());
			}
			tren = tren->getleft();


		}


	}

}

Tree::~Tree()
{
	list <Node*> stack,stek;
	stack.push_back(root);
	Node* tren = root;
	while (!stack.empty()) {
		tren = stack.back();
		stack.pop_back();

		while (tren) {
			stek.push_back(tren);

			if (tren->getright()) {
				stack.push_back(tren->getright());
			}
			tren = tren->getleft();


		}


	}
	while (!stek.empty()) {
		tren = stek.back();
		stek.pop_back();
		delete tren;

	}
	root = NULL;
	
	return;

}
