#pragma once
#include <iostream>
#include "student.h"
#include "tempfunc.h"

using namespace std;


class Bucket {
public:
	Student* arr;
	int depth;
	int len = 0;
	int cap;
	int* bits;
	void del();
	void copy();
	void move();
public:
	Bucket(int depth, int cap) : depth(depth), cap(cap) {
		arr = new Student[cap];
		bits = new int[depth];
		//for (int i = 0; i < cap; i++) arr[i] = nullptr;
	}
	

	Bucket() = default;
	void addStudent(Student s);
	friend class HashTable;
	~Bucket() { del(); }
};