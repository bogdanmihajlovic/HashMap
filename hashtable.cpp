#include "hashtable.h"

HashTable::HashTable(int p, int k,int c) : p(p), k(k), c(c) {
	n = pow(2, p);
	values = new Student ** [n];
	for (int i = 0; i < n; i++) {
		values[i] = new Student * [k];
		for (int j = 0; j < k; j++) values[i][j] = nullptr;
	}
}

void HashTable::addStudent(Student& s,int pos1, int pos2){
	values[pos1][pos2] = new Student(s);
}



bool HashTable::insertKey(Student s){
	//provera jel postoji kljuc
	if (findKey(s())) return false;
	//provera jel puna tabela
	if (count == n*k) return false;
	int stepCounter = 0;
	int index = this->hashFunc(s()); //izracunavanje h1(key)
	
	//proveravamo da li ima mesta u values[index][0]...values[index][k]
	for (int i = 0; i < k; i++) {
		if (!values[index][i] || values[index][i]->isDeleted()) {
			values[index][i] = new Student(s);
			count++;
			return true;
		}	
	}
	stepCounter++;
	int oldIndex = index;
	//dolazi do kolizije
	while (1) {
		if (stepCounter == n * k) return false;
		index = QuadriaticHashing(c).getAddress(s(), oldIndex, stepCounter, n);
		for (int i = 0; i < k; i++) {
			if (!values[index][i] || values[index][i]->isDeleted()) {
				values[index][i] = new Student(s);
				count++;
				return true;
			}
		}
		stepCounter++;
	}


	return false;
}

Student* HashTable::findKey(int key) const{
	int stepCounter = 0;
	int index = this->hashFunc(key);
	for (int i = 0; i < k; i++) 
		if (values[index][i] && (*values[index][i])() == key) return values[index][i];
	
	stepCounter++;
	int oldIndex = index;
	//dolazi do kolizije
	while (1) {
		if (stepCounter == n*k) break;
		index = QuadriaticHashing(c).getAddress(key, oldIndex, stepCounter, n);
		for (int i = 0; i < k; i++)
			if (values[index][i] &&  (*values[index][i])() == key && values[index][i]->isDeleted() == false) return values[index][i];
		stepCounter++;
	}

	return nullptr;
}

bool HashTable::deleteKey(int key){
	Student* student = findKey(key);
	if (!student) return false;
	student->setDeleted(true);
	count--;
	return true;
}

void HashTable::clear(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (values[i][j]) values[i][j]->setDeleted(true);
		}
	}
	count = 0;

}

bool HashTable::addSub(int key, string sub){
	Student* student = findKey(key);
	if (!student) return false;
	string* subs = student->subject;
	string* temp = new string[student->len + 1];
	for (int i = 0; i < student->len; i++) temp[i] = subs[i];
	student->len++;

	temp[student->len - 1] = sub;
	delete[] student->subject;
	student->subject = temp;
	return true;
}

bool HashTable::delSub(int key, string sub){
	Student* student = findKey(key);
	if (!student) return false;
	for (int i = 0; i < student->len; i++) {
		if (student->subject[i] == sub) {
			//brisi
			for (int j = i; j < student->len - 1; j++) student->subject[j] = student->subject[j + 1];
			student->len -= 1;
			return true;
		}
	}
	return false;
}

int HashTable::hashFunc(int key) const{ return (key % (int)pow(2, p)); }

ostream& operator<<(ostream& os, const HashTable& h){
	for (int i = 0; i < h.n; i++) {
		for (int j = 0; j < h.k; j++) {
			os << "Pos[" << i << "][" << j << "]--> ";
			if (h.values[i][j])
				if (!h.values[i][j]->isDeleted()) os << *h.values[i][j] << endl;
				else os << "DELETED" << endl;
			else os << "EMPTY" << endl;
		}
	}
	return os;
}
