#include "DynamicIntArray.h"
#include <iostream>
#include <algorithm> 

DynamicIntArray::DynamicIntArray()
{
	data = nullptr;
	size = 0;
	capacity = 0;
}
DynamicIntArray::DynamicIntArray(std::size_t size) : size(size), capacity(size) 
{
	data = new int[capacity];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : size(other.size),capacity(other.capacity)
{
	data = new int[capacity];
	std::copy(other.data, other.data + size, data);
}

DynamicIntArray::~DynamicIntArray()
{
	delete[] data;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if (this != &other)
	{
		delete[] data;
		
		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		std::copy(other.data, other.data + size, data);
	}
	return *this;
}

int& DynamicIntArray::operator[](std::size_t index) 
{
	return data[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	int* newData = new int[newSize];
	std::copy(data, data + std::min(size, newSize), newData);
	delete[] data;
	data = newData;
	size = newSize;
	capacity = newSize;
}

std::size_t DynamicIntArray::getSize() const 
{
	return size;
}

void DynamicIntArray::clear() {
	delete[] data;  
	data = nullptr;  
	size = 0;
	capacity = 0;
}

bool DynamicIntArray::operator==(const DynamicIntArray& other) 
{
	if (size != other.size) return false;  
	for (std::size_t i = 0; i < size; ++i) 
	{
		if (data[i] != other.data[i]) return false;  
	}
	return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other) 
{
	return !(*this == other); 
}

void DynamicIntArray::push_back(int element) {
	if (size == capacity) 
	{  
		capacity = (capacity == 0) ? 1 : capacity * 2;
		int* newData = new int[capacity];
		std::copy(data, data + size, newData); 
		delete[] data;  
		data = newData; 
	}
	data[size++] = element; 
}
