#include "hashtable.h"

HashTable::HashTable(int depth, int p, int k) : depth(depth), p(p), k(k) {
	n = pow(2, depth);
	b = depth;
	arr = new Bucket*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new Bucket(depth, k);
		arr[i]->bits = highBits(i, depth, 2);
	}
}

void HashTable::printHash() const{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

bool HashTable::insertKey(Student s){
	//izracunam u koji baket treba da se smesti
	if (len == pow(2,p) * k) return false;
	int index = hashFunc(s.index);
	
	
	//probaj da stavis kljuc u baket
	if (arr[index]->len < arr[index]->cap) {
		//dodaj studenta
		arr[index]->addStudent(s);
		len++;
		return true;
	}

	if (p == depth) return false;//provera jel ima jos mesta
	//cuvanje svih baketa
	Bucket* leftCurr = arr[index];//baket koji treba da se prelomi
	Bucket* rightCurr = new Bucket(depth + 1, k);
	Bucket** temp = new Bucket * [n];

	for (int i = 0, j = 0; i < n; i++) 
		if(temp[j] != arr[index]) temp[j++] = arr[i];
	
	//sirenje hes tabele
	int oldN = n;
	depth++;
	n = (int)pow(2, depth);
	delete[] arr;
	arr = nullptr;
	arr = new Bucket * [n];
	//for (int i = 0; i < n; i++) arr[i] = nullptr;
	leftCurr->depth++;
	
	//split buket
	for (int i = leftCurr->len / 2 + 1, j = 0; i < leftCurr->len; i++) {
		rightCurr->arr[j] = leftCurr->arr[i];
		rightCurr->len++;
	}
	leftCurr->len /= 2 + 1;
	leftCurr->bits = highBits(leftCurr->arr[0].index, leftCurr->depth,depth);
	//treba da dodam novog studenta u rightCurr
	rightCurr->addStudent(s);
	rightCurr->bits = highBits(rightCurr->arr[0].index, rightCurr->depth,depth);
	//preraspodela baketa

	for (int i = 0; i < oldN - 1; i++) {
		Bucket* bucket = temp[i];
		int diff = pow(2, depth - bucket->depth);
		for (int j = 0; j < n; j++) {
			int* tempBits = highBits(j, bucket->depth,depth);
			if (compareBits(bucket->bits, tempBits, bucket->depth)) {
				for (int l = 0; l < diff; l++) arr[l + j] = bucket;
				break;
			}
		}
	}



	//za leftCurr
	//za rightCurr
	int diff = pow(2, depth - leftCurr->depth);
	for (int j = 0; j < n; j++) {
		int* tempBits = highBits(j, leftCurr->depth,depth);
		if (compareBits(leftCurr->bits, tempBits, leftCurr->depth)) {
			for (int l = 0; l < diff; l++) arr[l + j] = leftCurr;
			break;
		}
	}
	diff = pow(2, depth - rightCurr->depth);
	for (int j = 0; j < n; j++) {
		int* tempBits = highBits(j, rightCurr->depth,depth);
		if (compareBits(rightCurr->bits, tempBits, rightCurr->depth)) {
			for (int l = 0; l < diff; l++) arr[l + j] = rightCurr;
			break;
		}
	}

	len++;
	return true;
}


