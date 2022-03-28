#include"tree.h"


int main() {

		cout << "Dobrodosli" << endl;
		int a;
		Tree * bst = new Tree();
		Node* tren = new Node();
	while (1) {

		cout << "\nGlavni Meni\n"
			"1.Formiranje stabla\n"
			"2.Formiranje iz datoteke\n"
			"3.Pretraga po kljucu\n"
			"4.Umetanje novog kljuca\n"
			"5.Ispis stabla\n"
			"6.Brisanje kljuca\n"
			"7.Brisanje stabla\n"
			"8.Odredjivanje reci sa najvecim brojem prevoda\n"
			"9.Kraj programa\n"
			"10. Inorder print\n";

		cout << "Odaberite redni broj: ";
		cin >> a;
		string ulaz;
		string k, t,e;
		switch (a) {
		case 1:
			bst = new Tree();
			cout << "\nUnosite kljuc i prevod u formatu: Stolica Chair. Za kraj unosa upisite - -\n";
			while (1) {
				cin >> k>>t;
				if (k == "-") break;
				//delete[] tren;
				tren = new Node(k, t);
				/*Node* tren = new Node(k, t);*/
				bst->add(tren);
			}


		/*	Stolica Chair
			Zglob Ankle
			Zglob bbb
			Ananas Pineapple
			Bure Barrel
			Ananas tttt
			Ali But
			Stolica ssss
			Boni ker
			Pas Dog
			Stolica tri
			Stolica cetri
			- -*/
			break;
		case 2:
			bst = new Tree();
			cout << "\n Unesite ime ulazne datoteke: ";
			cin >> ulaz;
			bst->addfromfile(ulaz);
			break;

		case 3:
			if (!bst->getroot()) { cout << "\n Prvo kreirajte stablo! \n"; break; }
			cout << "\n Unesite kljuc koji zelite da pretrazite: ";
			cin >> k;

			cout << "\nPrevod: " << bst->search(k,0);
			break;

		case 4:
			if (!bst->getroot()) { cout << "\n Prvo kreirajte stablo! \n"; break; }
			cout << "\nUnesite kljuc i prevod u formatu: Stolica Chair\n";
			cin >> k >> t;
			//delete[] tren;
				tren = new Node(k, t);
			/*Node* tren = new Node(k, t);*/
			bst->add(tren);
			break;

		case 5:
			if (!bst->getroot()) { cout << "\n Prvo kreirajte stablo! \n"; break; }
			bst->ispis();
			break;
		case 6:
			if (!bst->getroot()) { cout << "\n Prvo kreirajte stablo! \n"; break; }
			cout << "\nUpisite kljuc i prevod za brisanje: ";
			cin >> k >> t;
			bst->Delete_node(k, t);
			break;
		case 7:
			bst->~Tree();
			/*delete bst;*/
			break;
		case 8:
			if (!bst->getroot()) { cout << "\n Prvo kreirajte stablo! \n"; break; }
			cout << "\n Rec sa najvise prevoda: " << bst->maxprevodi()<<endl;
			break;
		case 9:
			exit(0);
		case 10:
			bst->printInorder();
		default:
			
			cout << "\nNeispravan unos, probajte ponovo\n";
			break;

		}

	}

}