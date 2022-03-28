#include "Stablo.h"



int main() {
	/*
	//Stablo s1;

	//int red;
	//cin >> red;
	Stablo s1(3);

	//Node* pom = s1.getkoren();
	s1 += "a";
	cout << &s1<<endl;
	s1 += "b";
	cout << &s1<<endl;
	s1 += "c";
	cout << &s1<<endl;
	s1 += "d";
	cout << &s1<<endl;
	s1 += "e";
	cout << &s1<<endl;
	s1 += "f";
	cout << &s1<<endl;
	s1 += "g";
	cout << &s1 << endl;

	//cout << s1.pronadji("e");
	//cout << s1.pronadji("a");
	//cout << s1.pronadji("c");
	//cout << s1.pronadji("d");
	//cout << s1.pronadji("b");
	//cout << s1.pronadji("g");
	//cout << s1.pronadji("f");
	s1 += "h";
	cout << endl;
	cout << &s1;
	s1 += "o";
	cout << endl;
	cout << &s1;
	s1 += "k";
	cout << endl;
	cout << &s1;
	cout << s1.pronadji("r");
	cout << s1.pronadji("aa");
	cout << s1.pronadji("g");
	cout << s1.pronadji("ab");

	//cout << &s1;
	//s1.inorder(s1.getkoren());
	cout << endl;
	//s1.inorder("c");
	s1 -= "g";
	//s1 -= "f";
	cout << &s1;
	cout << endl;
	
	//cout << &s1;
	s1.inorder("a");
	s1.inorder("sp");

	cout << "Proba";
	*/

	
	Stablo s1;
	int a;
	string b;
	string dat;
	while (1) {
		cout << "\nGLAVNI MENI\n"
			"----------------"
			"\n1.Kreiranje stabla"
			"\n2.Dodavanje kljuca"
			"\n3.Brisanje kljuca"
			"\n4.Ispis stabla"
			"\n5.Pronalazenje kljuca"
			"\n6.Za X ispisati koliko pre X."
			"\n7.Dodavanje kljuca iz datoteke\n";

		cin >> a;
		switch (a) {

		case 1:
			int red;
			cout << "\nUneti red stabla u opsegu od 3-10: ";
			cin >> red;
			if (red < 3 || red>10) { cout << "\nLos unos. "; continue; }

			s1 = Stablo(red);
			break;


		case 2:
			cout << "\nUneti kljuc za unos: ";

			cin >> b;
			if (!(s1 += b)) cout << "\nKljuc vec u stablu.";
			break;

		case 3:
			cout << "\nUneti kljuc za brisanje: ";

			cin >> b;
			if (!(s1 -= b)) cout << "\nKljuc ne postoji";
			break;
		case 4:
			cout << &s1;

			break;

		case 5:
			cout << "\nUneti kljuc za pretragu: ";
			cin >> b;
			if (s1.pronadji(b)) cout << "\nKljuc je u stablu.";
			else cout << "\nKljuc nije u stablu.";
			break;
		case 6:
			cout << "\nUneti kljuc za pretragu: ";
			cin >> b;
			s1.inorder(b);
			break;
		case 7:
			cout << "\nUneti ime datoteke: ";
			cin >> dat;
			s1.dodajizdat(dat);

		}







	}




	

	
	

}