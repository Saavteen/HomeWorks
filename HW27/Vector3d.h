#pragma once
#include <iostream>

class Vector3d {
public:
    float x, y, z;

    // Конструктори
    Vector3d() : x(0), y(0), z(0) {}
    Vector3d(float x, float y, float z) : x(x), y(y), z(z) {}

    // Метод для векторного добутку
    Vector3d crossProduct(const Vector3d& other) const {
        return Vector3d(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Метод для виведення вектора
    void print() const {
        std::cout << "Vector3d(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};