#include "bucket.h"
void Bucket::del(){
	delete[] arr;
	delete[] bits;
	arr = nullptr;
	bits = nullptr;
}
void Bucket::addStudent(Student s){
	arr[len] = s;
	len++;
}
