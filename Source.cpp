#include "hashtable.h"
#include "tempfunc.h"

using namespace std;
int main() {
	//TO DO
	// dodati predmet studentu
	// obrisati predmet studentu


	int option = 0;
	int key = 0;
	int p = 0;
	int k = 0;
	char c;
	bool check;
	string sub;
	cout << "Unesite parametar c: ";
	cin >> c;
	cout << "Unesite parametar p: ";
	cin >> p;
	cout << "Unesite parametar k: ";
	cin >> k;
	c = getchar();
	HashTable hashmap(p, k, c);
	Student student;
	cout << "Unesite studenta(index,ime prezime,predmet1 predmet2 ...): \n";

	while (true) {
		//cout << "Unesite studenta(index,ime prezime,predmet1 predmet2 ...): ";
		cin >> student;
		if (!student()) break;
		check = hashmap.insertKey(student);
		if (check) cout << "Uspesno dodat student!\n";
		else cout << "Neuspesno dodat student!\n";
	}

	while (1) {
		printMenu();
		cin >> option;
		c = getchar();
		Student* pstudent;
		switch (option)
		{
		case 1:	
			cout <<  "Unesite studenta(index,ime prezime,predmet1 predmet2 ...): ";
			cin >> student;
			check = hashmap.insertKey(student);
			if (check) cout << "Uspesno dodat student!\n";
			else cout << "Neuspesno dodat student!\n";
			break;
		case 2:
			cout << "Unesite indeks studenta kog zelite da obrisete: ";
			cin >> key;
			check = hashmap.deleteKey(key);
			if (check) cout << "Uspesno obrisan student!\n";
			else cout << "Neuspesno obrisan student!\n";
			break;
		case 3:
			cout << hashmap;
			break;
		case 4:
			cout << "Unesite indeks studenta: ";
			cin >> key;
			pstudent = hashmap.findKey(key);
			if (pstudent) cout << "Uspesno pronadjen student: " << *pstudent << endl;
			else cout << "Neuspesno pronadjen student!\n";
			break;
		case 5:
			hashmap.clear();
			cout << "Uspesno ispraznjena tabela!\n";
			break;
		case 6:
			cout << "Broj kljuceva u tabeli je: " << hashmap.keyCount() << endl;
			break;
		case 7:
			cout << "Stepen popunjesnoti u tabeli je: " << hashmap.fillRatio() << endl;
			break;
		case 8:
			cout << "Unesite indeks studenta: ";
			cin >> key;
			cout << "Unesite predmet koji zelite da dodate: ";
			cin >> sub;
			check = hashmap.addSub(key, sub);
			if (check) cout << "Uspesno dodat predmet!\n";
			else cout << "Neuspesno dodat predmet!\n";
			break;
		case 9:
			cout << "Unesite indeks studenta: ";
			cin >> key;
			cout << "Unesite predmet koji zelite da obrisete: ";
			cin >> sub;
			check = hashmap.delSub(key, sub);
			if (check) cout << "Uspesno obrisan predmet!\n";
			else cout << "Neuspesno obrisan predmet!\n";
			break;
		case 10:
			return 0;
		default:
			continue;
		}
		
	}
	

	

}
/*

20110451 Zeljko Milinkovic 13S052SIS 13S114MUPS 13S111ASP1 13S111ORT1 13S082VS
20060089 Sergej Isic 13S112OS1 13S112ASP2 13S091EJV
20200245 Milijan Jovicevic 13S114MIPS 13S113AOR1 13S032PMT 13S082VS 13S112VD
19980735 Milijan Mako 3S074IOA 13S042ODE 13S113AOR1 13S114PP1 13S114MIPS
19960486 Luka Urosevic

20110451    Zeljko Milinkovic	13S052SIS 13S114MUPS 13S111ASP1 13S111ORT1 13S082VS
20060089	Sergej Isic	13S112OS1 13S112ASP2 13S091EJV
20200245	Milijan Jovicevic	13S114MIPS 13S113AOR1 13S032PMT 13S082VS 13S112VD
19980735	Milijan Mako	13S074IOA 13S042ODE 13S113AOR1 13S114PP1 13S114MIPS
19960486	Luka Urosevic

20190727,Andrea Mandic,
19950415,Nevena Jahic,13S113PS 13S112POS
20200415,Teodora Bakovic,
19980243,Aleksa Petrovic,13S113IS 13S114VLSI
20020333,Darinka Popadic,13S111RMFP 13S114PRS 13S112AR
20180486,Denis Vidosavljevic,13S112ORT2 13S113TS
20180070,Damjan Celebic,13S112OS1
19960046,Goran Stefanovic,13S112POS 13S053NM 13S091S 13S113BP2 13S111PP2
20040345,Ljubisa Antonijevic,
19990185,Bozidar Ivanovic,13S113USP 13S112ASP2 13S111P2 13S081M2 13S113BP2 13S113IS1
20110451,Zeljko Milinkovic,13S052SIS 13S114MUPS 13S111ASP1 13S111ORT1 13S082VS
20060089,Sergej Isic,13S112OS1 13S112ASP2 13S091EJV
20200245,Milijan Jovicevic,13S114MIPS 13S113AOR1 13S032PMT 13S082VS 13S112VD
19980735,Milijan Mako,13S074IOA 13S042ODE 13S113AOR1 13S114PP1 13S114MIPS
19960486,Luka Urosevic,


*/


