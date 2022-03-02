#pragma once
#include "adressfunction.h"


class DoubleHashing : public AdressFunction {
private:
	static int p, q;
public:
	virtual int getAddress(int key, int index, int i, int n) const override {
	//	return_address = a + i*(q + (k mod p));
		return index + i * (q + (key % p));
	}
};

//int DoubleHashing::p = 13;
//int DoubleHashing::q = 1;
