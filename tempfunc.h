#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_STRING = 100;

string* splitString(string, int*);

void printMenu();
int* highBits(int num, int n,int limit = 0);
bool compareBits(int* a, int* b, int len);