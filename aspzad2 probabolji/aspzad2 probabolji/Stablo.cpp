#include "Stablo.h"


void Stablo::dodajl (Node* pom, string klj, int brojac)
{
	int d = pom->gettrenklj() + 1 + pom->getfather()->getpodstabla()[brojac - 1]->gettrenklj() + 1;

			string* pomoc = makestring(d,klj,pom->getfather()->getpodstabla()[brojac - 1],pom->getfather()->getkljucevi()[brojac-1],pom);
			int i;
		
			Node* novl = new Node(minp, red, red - 1), * nov2 = new Node(minp, red, red - 1);
			i = 0;
			for (i = 0; i < d / 2; i++) {

				*novl += pomoc[i];
			}
			pom->getfather()->getkljucevi()[brojac-1] = pomoc[i++];
		
			for (i; i < d; i++) {
				*nov2 += pomoc[i];
			}
			novl->setfather(pom->getfather());
			nov2->setfather(pom->getfather());
			novl->setlvl(pom->getlvl());
			nov2->setlvl(pom->getlvl());
			nov2->setindex(1);
			pom->getfather()->getpodstabla()[brojac] = nov2;
			pom->getfather()->getpodstabla()[brojac - 1] = novl;
			return;
}

void Stablo::dodajd(Node* pom, string klj, int brojac)
{
	int d = pom->gettrenklj()+ 1+ pom->getfather()->getpodstabla()[brojac+1]->gettrenklj() +1;
			
			string* pomoc = makestring(d,klj,pom,pom->getfather()->getkljucevi()[brojac],pom->getfather()->getpodstabla()[brojac + 1]);
			int i;
			
			int j;
			Node* novl = new Node(minp, red, red - 1) , *nov2= new Node(minp,red,red-1);
			i = 0;
			for (i = 0; i < d/ 2; i++) {

				*novl += pomoc[i];
			}
			pom->getfather()->getkljucevi()[brojac] = pomoc[i++];
				for (i; i < d; i++) {
				*nov2 += pomoc[i];
				}
				novl->setfather(pom->getfather());
				nov2->setfather(pom->getfather());
				nov2->setindex(1);

				novl->setlvl(pom->getlvl());
				nov2->setlvl(pom->getlvl());
				pom->getfather()->getpodstabla()[brojac] = novl;
				pom->getfather()->getpodstabla()[brojac+1] = nov2;

				return;
}

void Stablo::preklapanjel(Node* pom, string klj, int brojac)
{
		int grl = floor((2 * red - 2) / 3);
		int grs = floor((2 * red - 1) / 3);
		int grd = floor(2 * red / 3);
		Node *levi,*srednji,*desni,*novd = new Node(minp, red, red - 1);
		desni = novd;
		int d = pom->gettrenklj() + 1 + pom->getfather()->getpodstabla()[brojac - 1]->gettrenklj() + 1;
		levi = pom->getfather()->getpodstabla()[brojac - 1];
		srednji = pom;
		string* pomoc = makestring(d, klj, pom->getfather()->getpodstabla()[brojac - 1], pom->getfather()->getkljucevi()[brojac - 1], pom);
	
		int i;
		int j;
		i = 0;
		int br = 0;
		for (i = 0; i < grl; i++) {
			levi->getkljucevi()[i] = pomoc[i];
		
		}
		for (int k = i; k < levi->getmaxpodst() - 1; k++) {
			levi->getkljucevi()[k] = "";
		}
		levi->settrenklj(grl);
	
		pom->getfather()->getkljucevi()[brojac - 1] = pomoc[i++];

		j = i;
		for (i; i < (j + grs); i++) {
			srednji->getkljucevi()[br++] = pomoc[i];
		}
		
		for (int k = br; k < srednji->getmaxpodst() - 1; k++) {
			srednji->getkljucevi()[k] = "";
		}
		srednji->settrenklj(grs);

		if (pom->getfather()->mogucedod()) {

			pom->getfather()->getkljucevi()[brojac] = pomoc[i++];
			pom->getfather()->dodkljuc();
			for (i; i < d; i++) {
			*desni += pomoc[i];
			}
			desni->setindex(srednji->getindex() + 1);
		/*novl->setfather(pom->getfather());
		novs->setfather(pom->getfather());*/
			desni->setfather(pom->getfather());
			novd->setlvl(pom->getlvl() );
			pom->getfather()->getpodstabla()[brojac+1] = novd;
			pom->getfather()->setpodst(brojac+2);
		}
		else {
			if (pom->getfather() == koren) {

				
				string help = pomoc[i++];
				for (i; i < d; i++) {
					*desni += pomoc[i];
				}

				int d = koren->getmaxpodst() + 1;
				desni->setindex(srednji->getindex() + 1);
				Node** sinovi = new Node * [d];
				int br = 0;
				i = 0;
				for (i = 0; i < d - 1; i++) {
					koren->getpodstabla()[i]->setlvl(koren->getpodstabla()[i]->getlvl() + 1);
					sinovi[i] = koren->getpodstabla()[i];

				}
				sinovi[i] = novd;
				novd->setlvl(sinovi[0]->getlvl());


				int p = koren->gettrenklj() + 1;
				string* klj1 = new string[p];

				for (i = 0; i < p - 1; i++) {

					klj1[i] = koren->getkljucevi()[i];
				}
				klj1[i] = "";

				while (klj1[i] < help) {
					if (klj1[i] == "") { klj1[i] = help; break; }
					i++;

				}
				if (i != (p - 1)) {
					int j = i;
					for (int i = p - 1; i > j; i--) {
						klj1[i] = klj1[i - 1];
					}

					klj1[j] = help;
				}
				i = 0;
				for (i; i < p / 2; i++) {

					koren->getkljucevi()[i] = klj1[i];
				}
				koren->settrenklj(i);
				koren->setpodst(i + 1);
				j = i;
				for (i; i < koren->getmaxpodst() - 1; i++) {
					koren->getkljucevi()[i] = "";
				}

				Node* novk = new Node(2, maxp, maxp - 1);
				Node* novd2 = new Node(minp, red, red - 1);
				*novk += klj1[p / 2];

				for (i = p/2+1; i < p; i++) {

					*novd2 += klj1[i];
				}
				koren->setlvl(1);
				koren->setfather(novk);
				novd2->setlvl(1);
				novd2->setpodst(2);
				novk->getpodstabla()[0]=koren;
				novk->getpodstabla()[1] = novd2;
				novd2->setfather(novk);
				novk->setpodst(2);
				koren = novk;
				novd2->setindex(1);

				
				br = 0;
				int ind;
				for (i = 0; i <= koren->gettrenklj(); i++) {
					ind = 0;
					for (j = 0; j < koren->getpodstabla()[i]->gettrenklj() + 1; j++) {
						sinovi[br]->setfather(koren->getpodstabla()[i]);

						sinovi[br]->setindex(ind++);
						koren->getpodstabla()[i]->getpodstabla()[j] = sinovi[br++];

					}
					//koren->getpodstabla()[i]->setpodst(j);
			

				}



			}



			/*else {


			}*/


			
		}



}

void Stablo::preklapanjed(Node* pom, string klj, int brojac)
{
	int grl = floor((2 * red - 2) / 3);
	int grs = floor((2 * red - 1) / 3);
	int grd = floor(2 * red / 3);
	Node* levi, * srednji,*desni, * novd = new Node(minp, red, red - 1);

	int d = pom->gettrenklj() + 1 + pom->getfather()->getpodstabla()[brojac+1]->gettrenklj() + 1;
	levi = pom;
	srednji = pom->getfather()->getpodstabla()[brojac +1];
	desni = novd;
	string* pomoc = makestring(d,klj,pom,pom->getfather()->getkljucevi()[pom->getindex()],pom->getfather()->getpodstabla()[pom->getindex()+1]);
	int i;

	int br = 0;
	int j;
	i = 0;
	for (i = 0; i < grl; i++) {
		levi->getkljucevi()[i] = pomoc[i];
		
	}
	for (int k = i; k < levi->getmaxpodst()-1; k++) {
		levi->getkljucevi()[k] = "";
	}
	levi->settrenklj(grl);
	

	pom->getfather()->getkljucevi()[brojac] = pomoc[i++];
	j = i;
	for (i; i < (j + grs); i++) {
		srednji->getkljucevi()[br++] = pomoc[i];
	}
	for (int k = br; k < levi->getmaxpodst()-1; k++) {
		srednji->getkljucevi()[k] = "";
	}
	srednji->settrenklj(grs);

	if (pom->getfather()->mogucedod()) {
		pom->getfather()->getkljucevi()[brojac + 1] = pomoc[i++];
		pom->getfather()->dodkljuc();
		for (i; i < d; i++) {
			*desni += pomoc[i];
		}
		desni->setindex(srednji->getindex() + 1);
		/*novl->setfather(pom->getfather());
		novs->setfather(pom->getfather());*/
		desni->setfather(pom->getfather());
		novd->setlvl(pom->getlvl());
		pom->getfather()->getpodstabla()[brojac + 2] = novd;
		pom->getfather()->setpodst(brojac + 3);
	}

	else {
		

		if (pom->getfather() == koren) {

				
				string help = pomoc[i++];
				for (i; i < d; i++) {
					*desni += pomoc[i];
				}

				int d = koren->getmaxpodst() + 1;
				desni->setindex(srednji->getindex() + 1);

				Node** sinovi = new Node * [d];
				int br = 0;
				i = 0;
				for (i = 0; i < d - 1; i++) {
					koren->getpodstabla()[i]->setlvl(koren->getpodstabla()[i]->getlvl() + 1);
					sinovi[i] = koren->getpodstabla()[i];

				}

				i = 0;
				while (sinovi[i]->getkljucevi()[0] < novd->getkljucevi()[0]) {
					if (sinovi[i]->getkljucevi()[0] == "") { sinovi[i] = novd; break; }
					i++;
				}
				j = i;
				if (i != d - 1) {
					for (i = d - 1; i > j; i--) {
						sinovi[i] = sinovi[i - 1];
					}
					sinovi[i] = novd;
				}

				//sinovi[i] = novd;
				novd->setlvl(sinovi[0]->getlvl());


				int p = koren->gettrenklj() + 1;
				string* klj1 = new string[p];

				for (i = 0; i < p - 1; i++) {

					klj1[i] = koren->getkljucevi()[i];
				}
				klj1[i] = "";
				i = 0;
				while (klj1[i] < help) {
					if (klj1[i] == "") { klj1[i] = help; break; }
					i++;

				}
				if (i != (p - 1)) {
					int j = i;
					for (int i = p - 1; i > j; i--) {
						klj1[i] = klj1[i - 1];
					}

					klj1[j] = help;
				}
				i = 0;
				for (i; i < p / 2 ; i++) {

					koren->getkljucevi()[i] = klj1[i];
				}
				koren->settrenklj(i);
				koren->setpodst(i + 1);
				j = i;
				for (i; i < koren->getmaxpodst() - 1; i++) {
					koren->getkljucevi()[i] = "";
				}
				i = j;
				Node* novk = new Node(2, maxp, maxp - 1);
				Node* novd2 = new Node(minp, red, red - 1);
				*novk += klj1[i++];

				for (i ; i < p; i++) {

					*novd2 += klj1[i];
				}
				koren->setlvl(1);
				koren->setfather(novk);
				novd2->setlvl(1);
				novd2->setpodst(2);
				novk->getpodstabla()[0]=koren;
				novk->getpodstabla()[1] = novd2;
				novd2->setfather(novk);
				novk->setpodst(2);
				koren = novk;
				novd2->setindex(1);

				
				br = 0;
				for (i = 0; i <= koren->gettrenklj(); i++) {

					for (j = 0; j < koren->getpodstabla()[i]->gettrenklj() + 1; j++) {
						sinovi[br]->setfather(koren->getpodstabla()[i]);
						koren->getpodstabla()[i]->getpodstabla()[j] = sinovi[br++];

					}
					//koren->getpodstabla()[i]->setpodst(j);
			

				}



			}


	}



	

				
	
	

}

string* Stablo::makestring(int d, string klj, Node* levi,string srednji,Node*desni)
{
	string* pomoc = new string[d];
	int i;
	for (i = 0; i < levi->gettrenklj(); i++) {
		pomoc[i] = levi->getkljucevi()[i];

	}
	pomoc[i++] = srednji;
	int j = 0;
	for (i; i < d - 1; i++) {
		pomoc[i] = desni->getkljucevi()[j++];

	}
	i = 0;
	while (pomoc[i] < klj) {
		if (pomoc[i] == "") { pomoc[i] = klj; break; }
		i++;

	}
	if (i != (d - 1)) {
		int j = i;
		for (int i = d - 1; i > j; i--) {
			pomoc[i] = pomoc[i - 1];
		}

		pomoc[j] = klj;
	}

	return pomoc;
}

void Stablo::inorder(string klj)
{
	list<Node*> stek;
	Node* next = koren;
	int br = 0;
	while (1) {
		while (next) {
			stek.push_back(next);
			next = next->getpodstabla()[0];

		}
		if (!stek.empty()) {
			next = stek.back();


			stek.pop_back();
			if (next->getkljucevi()[next->getbrojac()] == klj) {
				cout << br; return;
			}
	
			//cout << next->getkljucevi()[next->getbrojac()] << " ";
			br++;

			next->setbroj(next->getbrojac() + 1);
			if (next->getbrojac() < next->gettrenklj()) stek.push_back(next);
			if (next->getindex() != next->getmaxpodst() ) {

				next = next->getpodstabla()[next->getbrojac()];
			}

		}
		else {
			this->resetbr();
			return;
		}


	}

}

bool Stablo::pronadji(string klj)
{
	Node* pom = koren;
	int brojac;
	while (pom != nullptr) {

		brojac = 0;
		while ((pom->getkljucevi()[brojac] < klj) && (brojac < pom->gettrenklj())) {
			brojac++;
			if (brojac == pom->gettrenklj()) break;
		}

		if (pom->getkljucevi()[brojac] == klj) { return true; }
		pom = pom->getpodstabla()[brojac];


	}
	return false;
}

void Stablo::resetbr()
{
	{
	list <Node*> red;
	Node* next =koren;
	int i;

	int pom=0;
	red.push_back(next);
	while (red.size() && red.front()) {
		next = red.front();

		if (next == koren) {
			for (int i = 0; i < koren->gettrenpodst()+1; i++) {
				red.push_back(next->getpodstabla()[i]);
				
				
			}
			next->setbroj(0);
			
		}
		else {
			
			for (int i = 0; i < next->gettrenpodst(); i++) {
				red.push_back(next->getpodstabla()[i]);
				
				
			}
			next->setbroj(0);
			
		}

		red.pop_front();

	}

}
}


void Stablo::dodajizdat(string name)
{
	Node* nov;
	string klj;
	ifstream fil(name);
	while (fil >> klj) {
		
		
		*this+=klj;

	}
	

	fil.close();

}

bool Stablo::operator+=(string klj)
{
	Node* pom = koren, * pomo;
	int brojac = 0;
	if (pronadji(klj)) { return false; }
	while (pom->gettrenpodst() != 0) {

		brojac = 0;
		while ((pom->getkljucevi()[brojac] < klj) && (brojac < pom->gettrenklj())) {
			brojac++;
		}
		//if (pom->getkljucevi()[brojac] < klj) brojac++;
	    pom = pom->getpodstabla()[brojac]; 


	}

	if (pom->mogucedod()) {
		*pom += klj;
		return true;
	}

	if (pom==koren) {
		Node* novl = new Node(minp, red, red - 1), * nov2 = new Node(minp, red, red - 1);
		Node* novk = new Node(2, maxp, maxp - 1);
		int s = pom->gettrenklj() + 1;
		string* pom1 = new string[s];
		string* k = pom->getkljucevi();
		for (int i = 0; i < s - 1; i++) {
			pom1[i] = k[i];
		}

		int i = 0;

		while (pom1[i] < klj) {
			if (pom1[i] == "") { pom1[i] = klj; break; }
			i++;

		}
		if (i != (s - 1)) {
			int j = i;
			for (int i = s - 1; i > j; i--) {
				pom1[i] = pom1[i - 1];
			}

			pom1[j] = klj;
		}
		i = 0;
		for (i = 0; i < s / 2; i++) {

			*novl += pom1[i];
		}
		*novk += pom1[i++];
		for (i; i < s; i++) {
			*nov2 += pom1[i];
		}
		koren = novk;
		novl->setfather(koren);
		novk->dodajpodst(nov2);
		
		novk->dodajpodst(novl);
		novl->setindex(0);
		nov2->setindex(1);
		nov2->setfather(koren);
		novl->setlvl(1);
		nov2->setlvl(1);
		
		return true;

	}

	if(brojac!=pom->getfather()->gettrenklj()){

		if (pom->getfather()->getpodstabla()[brojac + 1]->mogucedod()) {
			dodajd(pom,klj,brojac);

		}
		else if (brojac) {
			if (pom->getfather()->getpodstabla()[brojac - 1]->mogucedod()) {
				dodajl(pom, klj, brojac);
			}
			else {
			preklapanjed(pom,klj,brojac);

			}
		}
		else {
		preklapanjed(pom,klj,brojac);

		}
		
		
	}
	else {
		if (pom->getfather()->getpodstabla()[brojac - 1]->mogucedod()) {
			dodajl(pom, klj, brojac);
		}
		else {
			preklapanjel(pom, klj, brojac);
		}
	}



}

bool Stablo::operator-=(string klj)
{

	Node* pom = koren;
	int brojac;
	while (pom != nullptr) {

		brojac = 0;
		while ((pom->getkljucevi()[brojac] < klj) && (brojac < pom->gettrenklj())) {
			brojac++;
			if (brojac == pom->gettrenklj()) break;
		}

		if (pom->getkljucevi()[brojac] == klj) {

			if (pom->gettrenpodst() == 0) {
				if (pom->gettrenklj() - 1 >= pom->getminpods() ) {

					for (int i = brojac; i < pom->gettrenklj() - 1; i++) {
						pom->getkljucevi()[i] = pom->getkljucevi()[i + 1];


					}
					pom->getkljucevi()[pom->gettrenklj() - 1] = "";
					pom->odkljuc();
					return true;
				}

				else {
					int i;
					if (brojac != pom->getfather()->gettrenpodst() - 1) {
						if (pom->getfather()->getpodstabla()[brojac + 1]->gettrenklj() >= pom->getfather()->getpodstabla()[brojac + 1]->getminpods()) {
							for (i = brojac; i < pom->gettrenklj()-1; i++) {
								pom->getkljucevi()[i] = pom->getkljucevi()[i + 1];
						

							}
							pom->getkljucevi()[i] = pom->getfather()->getkljucevi()[0];
							for (i = 0; i < pom->getfather()->gettrenklj()-1 ; i++) {
								pom->getfather()->getkljucevi()[i] = pom->getfather()->getkljucevi()[i + 1];
						

							}
							pom->getfather()->getkljucevi()[i] = pom->getfather()->getpodstabla()[pom->getindex()+1]->getkljucevi()[0];

							for (i = 0; i <  pom->getfather()->getpodstabla()[pom->getindex()+1]->gettrenklj() -1; i++) {
								pom->getfather()->getpodstabla()[pom->getindex()+1]->getkljucevi()[i] = pom->getfather()->getpodstabla()[pom->getindex()+1]->getkljucevi()[i + 1];
						

							}
							pom->getfather()->getpodstabla()[pom->getindex() + 1]->getkljucevi()[i] = "";

							pom->getfather()->getpodstabla()[pom->getindex() + 1]->odkljuc();

							return true;
						}



					}



				}

			}


		}


		pom = pom->getpodstabla()[brojac];



	}
	return false;


}

ostream& operator<<(ostream& os, Stablo* s)
{
	list <Node*> red;
	Node* next = s->koren;
	int i;

	int pom=0;
	red.push_back(next);
	while (red.size() && red.front()) {
		next = red.front();

		if (next == s->koren) {
			for (int i = 0; i < s->koren->gettrenpodst(); i++) {
				red.push_back(next->getpodstabla()[i]);
				
				
			}
			os << *next;

		}
		else {
			if (pom < next->getlvl()) {
				pom = next->getlvl();
				os << endl;
			}
			for (int i = 0; i < next->gettrenpodst(); i++) {
				red.push_back(next->getpodstabla()[i]);
				
				
			}
			os << *next;
		}

		red.pop_front();



	}
	return os;
}