#include "Containers.h"
#include <iostream>
using namespace std;

Container::~Container()
{

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
}

int & MyArray::operator[](int index)
{
	return ar[index];
}

MyArray & MyArray::operator=(const MyArray & ar)
{
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
}
