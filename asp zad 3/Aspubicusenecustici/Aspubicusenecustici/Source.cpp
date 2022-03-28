#include "HashTable.h"
#include <sstream>

int main() {


	/*


	Info* inf=new Info("students_50.csv", 50);
	HashTable tabela(2,3);
	int klj=0;
	string key;
	string* info;
	for (int i = 0; i < inf->size; i++) {
		info = new string();
		key = inf->podaci[i][0];
		stringstream help(key);

		help >> klj;

		*info = inf->podaci[i][1] +" " + inf->podaci[i][2];
		
		tabela.insertKey(klj, info);
	}



	cout << tabela;

	if (tabela.findKey(20140716)) { cout << *tabela.findKey(20140716); }

	tabela.deleteKey(20140716);
	cout << tabela;

	cout << " probaa";

	*/
	
	HashTable* tabela=new HashTable();
	Info* inf;
	int ind;
	//string* ost;
	string *ost=nullptr;
	int a;
	int flag;
	int klj=0;
	int poc;
	string key;
	string* info;
	string naziv;
	int stud;
	while (1) {
		cout << "GLAVNI MENI\n" << "--------------\n";
		cout << "\n1. Kreiranje tabele";
		cout << "\n2. Upis kljuceva iz .csv";
		cout << "\n3. Dodavanje kljuca";
		cout << "\n4. Brisanje kljuca";
		cout << "\n5. Azuriranje sadrzaja";
		cout << "\n6. Ispis tabele";
		cout << "\n7. Ispis sadrzaja kljuca";
		cout << "\n8. Brisanje tabele";
		cout << "\n9.Kraj programa\n";

		cin >> a;

		switch (a) {
		case 1: 
			cout << "\nUneti vrednosti k i p: ";
			int k, p;
			cin >> k >> p;
			tabela = new HashTable(k, p);
			cout << "\nZa prosirljivo upisi 1, za obicno 0.";
			cin >> flag;
			tabela->flag = flag;
			break;
		case 2:
			cout << "\nUneti naziv .csv fajla: ";
			cin >> naziv;
			cout << "\nUneti broj studenata: ";
			cin >> stud;

			inf=new Info(naziv, stud);
			
			for (int i = 0; i < inf->size; i++) {
				info = new string();
				key = inf->podaci[i][0];
				stringstream help(key);

				help >> klj;

				*info = inf->podaci[i][1] + " " + inf->podaci[i][2];
				if (flag) {
					tabela->pInsertKey(klj, info);
					//cout << *tabela<<endl;
				}
				else {
					tabela->insertKey(klj, info);
				}
			}
			break;
		case 3:
			cout << "\nUneti zeljeni index: ";
			cin >> ind;
			cout << endl;
			//ost = new string();
			//cout << "\nUneti Ime Prezime i Predmete: \n";
			cin.ignore();
			ost = new string();
		//cout << "ubicuse\n";
			getline(std::cin, *ost);
			if (!flag) {
				tabela->insertKey(ind, ost); 
			}
			else {

				tabela->pInsertKey(ind, ost);


			}
			break;
		case 4:
			cout << "\nUneti zeljeni kljuc za brisanje: ";
			cin >> ind;
			tabela->deleteKey(ind);
			break;
		case 5:
			cout << "\n1.Dodavanje ispita\n2.Brisanje ispita\n";
			cin >> ind;
			switch (ind) {
			case 1:
				cout << "\nUpisati kljuc studenta za modifikaciju: ";
				cin >> stud;

				info = tabela->findKey(stud);
				if (!info) { cout << "\nKljuc ne postoji u tabeli! "; break; }
				cout << "\nUpisati predmete za dodavanje: ";
				cin.ignore();

				getline(cin, *ost);
				*info += " ";
				*info += *ost;
				break;
			case 2:
				cout << "\nUpisati kljuc studenta za modifikaciju: ";
				cin >> stud;

				info = tabela->findKey(stud);
				if (!info) { cout << "\nKljuc ne postoji u tabeli! "; break; }

				cout << "\nUpisati predmet za brisanje: ";
				cin >> *ost;


				poc = (*info).find(*ost);
				(*info).erase(poc, (*ost).length());

				

				break;

			}
			break;

		case 6:
			cout << *tabela;
			break;

		case 7:
			cout << "\nUnesi kljuc: ";
			cin >> ind;
			cout << *(tabela->findKey(ind))<<endl;
			break;
		case 8:
			tabela->clear();
			break;
		}
		
		



	}

	

}