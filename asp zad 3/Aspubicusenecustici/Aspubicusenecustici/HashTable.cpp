#include "HashTable.h"



int HashTable::HashF(int key, int p)
{
	int rez = key % p;
	return rez;
}

int inBaket(Baket* b,int key) {

	for (int i = 0; i < b->polja.size(); i++) {
		if (b->polja[i] == nullptr) { continue; }
		if (b->polja[i]->getKey() == key) return i;
	}
	return -1;

}
int* HashTable::uHash(int key) {
	
	int mat = HashF(key, p);
	int adr = mat;
	int nal;
	int* res = new int[2];
	Address addr;
	Baket* b;
	while (1) {
		b = tabela[adr];
		nal = inBaket(b, key);
		if (nal != -1) { 
			res[0] = nal;
			res[1] = adr;
			return res; }
		if (b->polja.size() != k) { 
			res[0] = -1;
			res[1] = adr;
			return res; ; }

		adr = addr.getAddress(key, mat, p, c);
	
		if (numkeys == p * k && adr == mat) { 
			res[0] = -1;
			res[1] = adr;
			return res; ; }


	}



}
void HashTable::pInsertKey(int key, string* inf)
{
	vector <Baket*> baketi;
	if (numkeys == p * k) { cout << "Tabela je puna!\n"; return; }
	if (numkeys == 0) {
		for (int i = 0; i < int(pow(2,b)); i++) {
			tabela[i]->d = b;
			tabela[i]->nula = -1;

		}
	}
	
	int mat = HashF(key, int(pow(2,b)));
	int j,r;
	int flagg = 0,pom=b;
	Polje* pp=new Polje();
	int vr;
	pp->setKey(key);
	pp->setInfo(inf);
	pp->setStatus("notemp");
	if (tabela[mat]->polja.size() == 0) {
		tabela[mat]->polja.push_back(pp);
		numkeys++;
		if (tabela[mat]->polja.size() == k && tabela[mat]->delful==0) tabela[mat]->delful = 1;
		return;


	}
	else if(tabela[mat]->delful!=1){
		
		for (j = 0; j < tabela[mat]->polja.size(); j++) {
			if (tabela[mat]->polja[j] == nullptr) {
				
				tabela[mat]->polja[j] = pp;
				numkeys++;
				if (tabela[mat]->polja.size() == k && tabela[mat]->delful==0) tabela[mat]->delful = 1;
				else if (tabela[mat]->polja.size() == k && tabela[mat]->delful < 0) { tabela[mat]->delful=tabela[mat]->delful+1; }
				return;

			}
			if (tabela[mat]->polja[j]->getKey() == key) {
				cout << "Kljuc vec u tabeli\n";
				return;
			}

			


		}
		if (j == tabela[mat]->polja.size()) {
			
			tabela[mat]->polja.push_back(pp);
			numkeys++;
			if (tabela[mat]->polja.size() == k) tabela[mat]->delful = 1;
			return;

		}
		

	
	}
	else {
		Baket* l, *d;
		
		if (tabela[mat]->d < b) {
			l = new Baket();
			l->nula = 0;
			d = new Baket();
			d->nula = 1;
			int i;
			int pom;
			int helpme=b;
			for ( i = 0; i < int(pow(2,b)); i++) {
				if (tabela[i] == tabela[mat]) break;
			}
			pom = i;
			l->d = tabela[i]->d + 1;
			d->d = l->d;
			while (1) {
				flagg = 0;
				for (i = 0; i < tabela[i]->polja.size(); i++) {
					if ((tabela[mat]->polja[i]->getKey() >> (helpme + 1)) % 2) {
						if (d->delful) {  flagg = 1; break; }
						d->polja.push_back(tabela[mat]->polja[i]);
						if (d->polja.size() == k) d->delful = 1;

					}
					else {
						if (l ->delful) {  flagg = 1; break; }
						if (l->delful != 1) {
							l->polja.push_back(tabela[mat]->polja[i]);
						}

						if (l->polja.size() == k) l->delful = 1;
					}


				}
				if (flagg) { pom++; continue; }
				if ((key >> (helpme + 1)) % 2) {
					if (d->delful) {  flagg = 1; }
					d->polja.push_back(pp);

				}
				else {
					if (l ->delful) {  flagg = 1;  }
					l->polja.push_back(pp);
				}
				if (flagg) { pom++; continue; }
				if (d->polja.size() == k) d->delful = 1;
				if (l->polja.size() == k) l->delful = 1;
				
				break;
			}
				i = pom;
				vr = int(pow(2, b)) / int(pow(2, l->d));
				for (i; i < pom + vr; i++) {
					tabela[i] = l;
				}
				pom = i;
				for (i; i < pom + vr; i++) {
					tabela[i] = d;
				}
			
		}
		else {
			if (p == int(pow(2, b))) { cout << "Nemoguce dodavanje"; return; }
			while (1) {
				flagg = 0;
				for (int i = 0; i < int(pow(2, b)); i++) {

					if (i != mat) {
						for (r = 0; r < baketi.size(); r++) {
							if (baketi[r] == tabela[i]) { break; }
						}
						if (r == baketi.size()) { baketi.push_back(tabela[i]); }
					}
					else {
						l = new Baket();
						
						d = new Baket();
						l->nula = 0;
						d->nula = 1;
						l->d = tabela[i]->d + 1;
						d->d = tabela[i]->d + 1;
						for (int m = 0; m < k; m++)
						{
							if (tabela[i]->polja[m]->getKey() == key) {
								cout << "\nKljuc vec u tabeli! ";
								return;
							}
							if ((tabela[i]->polja[m]->getKey() >> (pom + 1)) % 2) {
								if (d->delful) { baketi.clear(); flagg = 1; break; }
								d->polja.push_back(tabela[i]->polja[m]);
								if (d->polja.size() == k) d->delful = 1;

							}
							else {
								if (l->delful) { baketi.clear(); flagg = 1; break; }
								l->polja.push_back(tabela[i]->polja[m]);
								if (l->polja.size() == k) l->delful = 1;
							}
						}
						if (flagg == 1) { pom++; continue; }
						if ((key >> (pom + 1)) % 2) {
							if (d->delful) { baketi.clear(); pom++; flagg = 1; continue; }
							d->polja.push_back(pp);
							if (d->polja.size() == k) d->delful = 1;

						}
						else {
							if (l->delful) { baketi.clear(); pom++; flagg = 1; continue; }
							l->polja.push_back(pp);
							if (l->polja.size() == k) l->delful = 1;
						}
						if (l->polja.size() == k) l->delful = 1;
						if (d->polja.size() == k) d->delful = 1;

						baketi.push_back(l);
						baketi.push_back(d);
					}

				}
				



				break;



			}

			b++;

		

			int m = 0;
			int pocm = m;
			for (int i = 0; i < baketi.size(); i++) {
				vr = int(pow(2, b)) / int(pow(2, baketi[i]->d));
				for (m; m < pocm + vr; m++) {
					tabela[m] = baketi[i];

				}
				pocm = m;

			}
			

		}




	}


}
string* HashTable::findKey(int key)
{
	int mat ;
	if (flag == 1) {
		mat = HashF(key, int(pow(2,b)));
	}
	else {
		mat = HashF(key, p);
	}
	int adr = mat;
	int prov = p * k;
	int nal;
	Address addr;
	Baket* b;
	while (1) {
		b = tabela[adr];
	
		nal = inBaket(b, key);
		if (nal != -1) { return b->polja[nal]->getInfo(); }
		if (b->polja.size() != k) return nullptr;

		adr = addr.getAddress(key, mat, p, c);
		
	
		if ((numkeys == prov) and (adr == mat)) { return nullptr; }

	}

	return nullptr;
}

bool HashTable::deleteKey(int key)
{

	int rez[2];
	rez[0] = uHash(key)[0];
	rez[1] = uHash(key)[1];

	if (rez[0] == -1) return false;
	Baket* b;
	b = tabela[rez[1]];
	b->delful = b->delful - 1;
	numkeys--;
	b->polja[rez[0]] = nullptr;
	//if (b->polja.size() == 0) {
	//	if (flag) {
	//		if (b->nula == 0) {




	//		}
	//		else if (b->nula == 1) {

	//		}
	//		else {

	//		}

	//	}
	//}
	
	return true;
}

bool HashTable::insertKey(int key, string* inf)
{
	if (numkeys == p*k) { cout << "Tabela je puna!\n"; return false; }


	int mat = HashF(key, p);
	int i,j;
	Polje* pp=new Polje();
	pp->setKey(key);
	pp->setInfo(inf);
	pp->setStatus("notemp");
	if (tabela[mat]->polja.size() == 0) {
		tabela[mat]->polja.push_back(pp);
		numkeys++;
		if (tabela[mat]->polja.size() == k && tabela[mat]->delful==0) tabela[mat]->delful = 1;
		return true;


	}
	else if(tabela[mat]->delful!=1){
		
		for (j = 0; j < tabela[mat]->polja.size(); j++) {
			if (tabela[mat]->polja[j] == nullptr) {
				
				tabela[mat]->polja[j] = pp;
				numkeys++;
				if (tabela[mat]->polja.size() == k && tabela[mat]->delful==0) tabela[mat]->delful = 1;
				else if (tabela[mat]->polja.size() == k && tabela[mat]->delful < 0) { tabela[mat]->delful=tabela[mat]->delful+1; }
				return true;

			}
			if (tabela[mat]->polja[j]->getKey() == key) {
				cout << "Kljuc vec u tabeli\n";
				return false;
			}

		}
		if (j == tabela[mat]->polja.size()) {
			
			tabela[mat]->polja.push_back(pp);
			numkeys++;
			if (tabela[mat]->polja.size() == k) tabela[mat]->delful = 1;
			return true;

		}

	}
	else {
		int a; 
		Address adr;
		while (1) {

			a = adr.getAddress(key, mat, p, c);
			if (adr.geti()==p*k) { cout << "Neuspesno dodavanje!\n"; return false; }
			if(tabela[a]->delful!=1){
		
				for (j = 0; j < tabela[a]->polja.size(); j++) {
					if (tabela[a]->polja[j]->getKey() == key) {
						cout << "Kljuc vec u tabeli\n";
						return false;
					}

					if (tabela[a]->polja[j] == nullptr) {
				
						tabela[a]->polja[j] = pp;
						numkeys++;
						if (tabela[a]->polja.size() == k) tabela[a]->delful = 1;
						return true;
					}

				}
			if (j == tabela[a]->polja.size()) {
			
				tabela[a]->polja.push_back(pp);
				numkeys++;
				if (tabela[a]->polja.size() == k) tabela[a]->delful = 1;
				return true;

			}

		}

		}

	}

	return 0;
}

void HashTable::clear()
{

	for (int i = 0; i < p; i++) {
		tabela[i] = new Baket();
	}


}

ostream& operator<<(ostream& os, HashTable Tab)
{
	for (int i = 0; i < Tab.p; i++) {
		os << i << " ";
		os << Tab.tabela[i];
		os << endl;

	}

	return os;

}
