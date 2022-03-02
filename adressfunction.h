#pragma once
#include <iostream>
#include <cmath>


using namespace std;

class AdressFunction {
public:
	virtual int getAddress(int key, int index, int i, int n) const = 0;
};