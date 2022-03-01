#pragma once
#include "bucket.h"
#include <vector>
#include <cmath>

class HashTable {
//private:
public:
	Bucket** arr;
	int n; //broj ulaza
	int k;//broj kljuceva u jednom baketu
	int p;//parametar p, maksimalna dubina
	int len = 0;//broj trenutnih kljuceva
	int depth;//trenutna dubina
	int b;
public:
	HashTable(int depth, int p, int k);
	bool insertKey(Student s);
	int hashFunc(int key) const { return (key % (int)pow(2, depth)); }
	void printHash() const;
};