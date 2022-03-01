#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	
	int index;
	string name, lastName;
	string* subject = nullptr;
	int len;
	bool deleted = false;
	void del();
	void copy(const Student& s);
	void move(Student& s);


public:
	//Student() = default;
	Student(int index = 0, string name = "", string lastName = "", string* arr = nullptr, int len = 0);
	Student(const Student&);
	Student(Student&&);
	Student& operator=(const Student&);
	Student& operator=(Student&&);
	~Student();
	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream& is, Student& s);
	void setDeleted(bool state) { deleted = state; }
	bool isDeleted() const { return deleted; }
	int operator()() const { return index; }
	friend class HashTable;
	friend class Bucket;

};