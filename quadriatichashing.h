#pragma once
#include "adressfunction.h"

class QuadriaticHashing : public AdressFunction {
private:
	static int c;
public:
	QuadriaticHashing() = default;
	QuadriaticHashing(int coef);
	virtual int getAddress(int key, int index, int i, int n) const override {
		return (index + i * i * c) % n;
	}
};