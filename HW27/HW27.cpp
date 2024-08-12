#include <iostream>
#include <cmath>
#include "Vector2d.h"
#include "Vector3d.h"

void testVector2d()
{
    Vector2d v1(0, 0, 3, 4); 
    Vector2d v2(0, 0, -3, -4);
    Vector2d v3(0, 0, 3, 0);
    Vector2d v4(0, 0, 0, 4); 

    std::cout << "Dot product v1 and v2: " << v1.dotProduct(v2) << std::endl; 
    std::cout << "Dot product v1 and v3: " << v1.dotProduct(v3) << std::endl; 
    std::cout << "Dot product v3 and v4: " << v3.dotProduct(v4) << std::endl;

    Vector2d v1_negated = v1.negate();
    std::cout << "v1 negated: (" << v1_negated.x << ", " << v1_negated.y << ")" << std::endl;

    std::cout << "v1 and v2 relative state: " << static_cast<int>(v1.getRelativeState(v2)) << std::endl; 
    std::cout << "v1 and v3 relative state: " << static_cast<int>(v1.getRelativeState(v3)) << std::endl; 
    std::cout << "v3 and v4 relative state: " << static_cast<int>(v3.getRelativeState(v4)) << std::endl; 

    v1.scale(2.0f, 0.5f);
    std::cout << "v1 scaled: (" << v1.x << ", " << v1.y << ")" << std::endl; 
}

int main()
{
    testVector2d();

    Vector3d v1(1, 0, 0);
    Vector3d v2(0, 1, 0);

    Vector3d v3 = v1.crossProduct(v2);

    std::cout << "v1 = ";
    v1.print();
    std::cout << "v2 = ";
    v2.print();
    std::cout << "v1 x v2 = ";
    v3.print();
    return 0;
}