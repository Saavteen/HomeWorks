#pragma once
#include <cmath>

struct Vector2d
{
    int x = 0;
    int y = 0;

    // i. Конструктор для побудови вектора з двох точок: tail, head
    Vector2d(float x0, float y0, float x1, float y1)
    {
        x = static_cast<int>(x1 - x0);
        y = static_cast<int>(y1 - y0);
    }

    // ii. Скалярний добуток
    float dotProduct(const Vector2d& other) const
    {
        return static_cast<float>(x * other.x + y * other.y);
    }

    // iii. Інверсія (негативний вектор)
    Vector2d negate() const
    {
        return Vector2d(-x, -y);
    }

    // iv. Enum class для визначення взаємного положення векторів
    enum class VectorRelativeState
    {
        Identical,
        CoDirected,
        OppositeDirected,
        AcuteAngle,
        ObtuseAngle,
        RightAngle
    };

    // iv. Метод для визначення взаємного положення векторів
    VectorRelativeState getRelativeState(const Vector2d& other) const
    {
        float dot = dotProduct(other);
        float magnitude1 = std::sqrt(static_cast<float>(x * x + y * y));
        float magnitude2 = std::sqrt(static_cast<float>(other.x * other.x + other.y * other.y));
        float cosTheta = dot / (magnitude1 * magnitude2);

        if (x == other.x && y == other.y)
            return VectorRelativeState::Identical;
        else if (cosTheta == 1.0f)
            return VectorRelativeState::CoDirected;
        else if (cosTheta == -1.0f)
            return VectorRelativeState::OppositeDirected;
        else if (cosTheta > 0 && cosTheta < 1.0f)
            return VectorRelativeState::AcuteAngle;
        else if (cosTheta < 0)
            return VectorRelativeState::ObtuseAngle;
        else if (std::fabs(cosTheta) < 1e-6f) // cos(90 degrees) == 0
            return VectorRelativeState::RightAngle;

        return VectorRelativeState::Identical; // fallback, should never reach here
    }

    // v. Метод масштабування
    void scale(float factorX, float factorY)
    {
        x = static_cast<int>(x * factorX);
        y = static_cast<int>(y * factorY);
    }

private:
    Vector2d(int x, int y) : x(x), y(y) {}
};
