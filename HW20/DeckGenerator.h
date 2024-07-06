#pragma once
#include <vector>
#include <cstdlib>
#include <stdexcept>

template <typename T>
T generateRandomElement(const std::vector<T>& database) {
    if (database.empty()) 
    {
        throw std::out_of_range("Database is empty");
    }
    unsigned int index = std::rand() % database.size();
    return database[index];
}

//template <typename T>
//int generateRandomIndex(const std::vector<T>& database)
//{
//    if (database.empty())
//    {
//        throw std::out_of_range("Database is empty");
//    }
//    return std::rand() % database.size();
//}

