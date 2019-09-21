#include "Containers.h"
#include <iostream>
using namespace std;

Container::~Container()
{
	size = 0;
}

MyArray::MyArray()
{
	ar = nullptr;
	size = 0;
}

MyArray::MyArray(int n)
{
	size = n;
	ar = new int[n];
	for (int i = 0; i < n; i++)
		ar[i] = 0;
}

MyArray::MyArray(const MyArray & ar)
{
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
}

int MyArray::getSize() const
{
	return size;
}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
}

void MyArray::addCapacity(int n)
{
	int* temp = new int[size+n];
	for (int i = 0; i < size; i++)
		temp[i] = ar[i];
	delete[] ar;
	ar = temp;
	for (int i = size; i < size+n; i++)
		ar[i] = 0;
	size += n;
}

int & MyArray::operator[](int index)
{
	return ar[index];
}

MyArray & MyArray::operator=(const MyArray & ar)
{
	if (this == &ar)
		return *this;
	delete [] this->ar;
	size = 0;
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
	return *this;
}

MyArray::~MyArray()
{
	delete[] ar;
	size = 0;
}