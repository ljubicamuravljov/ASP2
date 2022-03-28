#ifndef _Info_h_
#define _Info_h_

#include <iostream>
#include <fstream>
#include<string>
#include <sstream>  
#include <vector>
using namespace std;

class Info {
	string naziv;

public:
	int size = 0;
	
	string** podaci;
	Info(string name,int n):naziv(name){
	
		
		string line;
		string rec ,temp;
		fstream file;
		file.open(name, ios::in);
		getline(file, line);
		podaci = new string* [n];
		for (int i = 0; i < n; i++) {
			podaci[i] = new string[3];
			getline(file, temp, ',');
		
			podaci[i][0] = temp;
			getline(file, temp, ',');
			podaci[i][1] = temp;
			getline(file, temp, '\n');
			podaci[i][2] = temp;
			size++;
		


		}

				
		
		
		

		


	}

};

#endif