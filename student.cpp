#include "student.h"
#include "tempfunc.h"


void Student::del(){
	len = 0;
	index = 0;
	name = "";
	lastName = "";
	if(subject)delete[] subject;
}

void Student::copy(const Student& s){
	deleted = s.deleted;
	index = s.index;
	name = s.name;
	lastName = s.lastName;
	len = s.len;
	subject = new string[len];
	for (int i = 0; i < len; i++) subject[i] = s.subject[i];
}

void Student::move(Student& s){
	len = s.len;
	index = s.index;
	name = s.name;
	lastName = s.lastName;
	subject = s.subject;
	s.subject = nullptr;
}

Student::Student(int index, string name, string lastName, string* arr , int len ) : index(index), name(name), lastName(lastName), len(len) {
	subject = new string[len];
	for (int i = 0; i < len; i++) subject[i] = arr[i];
}

Student::Student(const Student& s){ copy(s); }

Student::Student(Student&& s) {
	move(s);
}

Student& Student::operator=(const Student& s){
	if (this != &s) {
		del();
		copy(s);
	}
	return *this;
}

Student& Student::operator=(Student&& s){
	if (this != &s) {
		del();
		move(s);
	}
	return *this;
}

Student::~Student() { del(); }

ostream& operator<<(ostream& os, const Student& s){

	os << s.index << " " << s.name << " " << s.lastName << " ";
	for (int i = 0; i < s.len; i++) os << s.subject[i] << " ";
	return os;
}

istream& operator>>(istream& is, Student& s){
	char c;
	s.len = 0;
	s.subject = nullptr;
	s.index = 0;
	s.name = "";
	s.lastName = "";

	string temp = "";
	c = getchar();
	if (c == '\n') return is;
	temp += c;
	while (true) {
		c = getchar();
		if (c == ',') break;
		temp = temp + c;
	}
	//is >> temp;
	//temp = c + temp;
	s.index = stoi(temp);
	//is >> s.index; 
	//c = getchar(); 
	is >> s.name;
	c = getchar();
	while (true) {
		c = getchar();
		if (c == ',' || c == '\n') break;
		s.lastName += c;
	}
	string txt;
	if (c == ',') {
		getline(is, txt);
		if (!txt.size()) return is;
		s.subject = splitString(txt, &s.len);
	}
	return is;
}

