#pragma once
#include "student.h"
#include "quadriatichashing.h"
#include <vector>
#include <cmath>

class HashTable {
private:
	
	Student*** values;
	int n, k, p, c;
	int count = 0;
public:
	//HashTable() = default;
	HashTable(int p, int k = 1, int c = 1);
	void addStudent(Student& s,int pos1,int pos2);
	friend ostream& operator<<(ostream& os, const HashTable& h);
	
	bool insertKey(Student s);
	Student* findKey(int key) const;
	bool deleteKey(int key);
	void clear();
	int keyCount() const { return count; }
	int tableSize() const { return k * n; }
	double fillRatio() const { return  double(count) / (n*k); }
	bool addSub(int key, string sub);
	bool delSub(int key, string sub);
	int hashFunc(int key) const;
};