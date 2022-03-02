#include "hashtable.h"
#include "student.h"
#include <iostream>
using namespace std;
int main() {
	int p = 5, k = 1, d = 2;
	char c;
	bool check;
	cout << "Unesite parametar p: ";
	cin >> p;
	cout << "Unesite parametar k: ";
	cin >> k;
	cout << "Unesite parametar d: ";
	cin >> d;
	//c = getchar();
	HashTable hashmap(d, p, k);
	Student student;
	
	while (true) {
		cin >> student;
		if (!student()) break;
		check = hashmap.insertKey(student);
		if (check) cout << "Uspesno dodat student!\n";
		else cout << "Neuspesno dodat student!\n";
	}
	int n;
	while (true) {
		
		printMenu();
		int n;
		cin << n;
		switch(n) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10: return 0;
		}
	}
	
}

/*
20190727,Andrea Mandic,
19950415,Nevena Jahic,13S113PS 13S112POS
20200415,Teodora Bakovic,
19980243,Aleksa Petrovic,13S113IS 13S114VLSI
20020333,Darinka Popadic,13S111RMFP 13S114PRS 13S112AR
20180486,Denis Vidosavljevic,13S112ORT2 13S113TS
*/