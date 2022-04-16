
#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;

    a[1][0] = 3;
    a[1][1] = 1;

    Matrix b(2, 2);

    b[0][0] = 2;
    b[0][1] = 2;
    
    b[1][0] = 0;
    b[1][1] = -1;
    std::cout << "a: " << a << std::endl;
    std::cout << "a: " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a + b = " << a - b << std::endl;
    std::cout << "a * 3 = " << a * 3 << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "b * a = " << b * a << std::endl;
    
    a *= b;
    std::cout << "a *=b: " << a << std::endl;

    a += b;
    std::cout << "a +=b: " << a << std::endl;

    a -= b;
    std::cout << "a -=b: " << a << std::endl;

    Matrix c = a * b;
    std::cout << "c = a * b: " << c << std::endl;

    c = a + b;
    std::cout << "c = a + b: " << c << std::endl;
    std::cout << "-c: " << -c << std::endl;

}


