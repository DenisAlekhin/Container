#include "MyVector.h"
#include <iostream>
using namespace std;

MyVector::MyVector() : MyArray() { capacity = 0; }

MyVector::MyVector(int n) : MyArray(n) { capacity = n; }

MyVector::MyVector(int n, int value)
{
	capacity = n;
	size = n;
	ar = new int[n];
	for (int i = 0; i < n; i++)
		ar[i] = value;
}

MyVector::MyVector(const MyVector& vec): MyArray(vec)
{ 
	capacity = vec.capacity; 
}

int MyVector::getCapacity() const
{
	return capacity;
}

void MyVector::addCapacity(int n)
{
	MyArray::addCapacity(n);
	capacity += n;
}

void MyVector::pushBack(int val)
{
	if (size < capacity)
		ar[size++] = val;
	else
	{
		MyVector::addCapacity(1);
		ar[size-1] = val;
	}
}

int MyVector::popBack()
{
	return ar[size--];
}

void MyVector::insert(int index, int val)
{
	if (size == capacity) addCapacity(1);
	else size++;
	for (int i = size - 1; i > index; i--)
		ar[i] = ar[i - 1];
	ar[index] = val;
}

int MyVector::remove(int index)
{
	int val = ar[index];
	size--;
	for (int i = index; i < size; i++)
		ar[i] = ar[i + 1];
	return val;
}

MyVector& MyVector::operator=(const MyVector& vec)
{
	if (this == &vec)
		return *this;
	delete[] this->ar;
	size = vec.size;
	capacity = vec.capacity;
	this->ar = new int[capacity];
	for (int i = 0; i < capacity; i++)
		this->ar[i] = vec.ar[i];
	return *this;
}
