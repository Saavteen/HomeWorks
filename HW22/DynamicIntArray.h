#pragma once
#include <cstdlib>
#include <stdexcept>
#include <algorithm>  // для std::copy

template <typename T>
class DynamicArray 
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();
    void push_back(const T& element);
    void pop_back();
    T back() const;

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;
    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;

private:
    T* m_data;
    std::size_t m_size;
    std::size_t m_capacity;

    void allocateMemory(std::size_t newCapacity);
};

template <typename T>
DynamicArray<T>::DynamicArray() : m_data(nullptr), m_size(0), m_capacity(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(std::size_t size) : m_size(size), m_capacity(size) 
{
    m_data = new T[m_capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : m_size(other.m_size), m_capacity(other.m_capacity) 
{
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_data;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] m_data;

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](std::size_t index) 
{
    if (index >= m_size) 
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](std::size_t index) const 
{
    if (index >= m_size) 
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T>
void DynamicArray<T>::setSize(std::size_t newSize)
{
    if (newSize > m_capacity) 
    {
        reserve(newSize);
    }
    m_size = newSize;
}

template <typename T>
std::size_t DynamicArray<T>::getSize() const
{
    return m_size;
}

template <typename T>
void DynamicArray<T>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
void DynamicArray<T>::push_back(const T& element)
{
    if (m_size >= m_capacity) 
    {
        reserve(m_capacity > 0 ? m_capacity * 2 : 1);
    }
    m_data[m_size++] = element;
}

template <typename T>
void DynamicArray<T>::pop_back() 
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template <typename T>
T DynamicArray<T>::back() const 
{
    if (m_size == 0) 
    {
        throw std::out_of_range("Array is empty");
    }
    return m_data[m_size - 1];
}

template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > m_capacity) 
    {
        allocateMemory(reservedSpace);
    }
}

template <typename T>
std::size_t DynamicArray<T>::getCapacity() const 
{
    return m_capacity;
}

template <typename T>
void DynamicArray<T>::shrinkToFit()
{
    if (m_capacity > m_size)
    {
        allocateMemory(m_size);
    }
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const 
{
    if (m_size != other.m_size) 
    {
        return false;
    }
    for (std::size_t i = 0; i < m_size; ++i) 
    {
        if (m_data[i] != other.m_data[i]) 
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void DynamicArray<T>::allocateMemory(std::size_t newCapacity) 
{
    T* newData = new T[newCapacity];
    if (m_data != nullptr) 
    {
        std::copy(m_data, m_data + m_size, newData);
        delete[] m_data;
    }
    m_data = newData;
    m_capacity = newCapacity;
}
