#include <iostream>

int main()
{
    int a{1};
    short b{2};
    float c{14.88};
    double d{14.8888};
    char e{'A'};
    unsigned long long f{1234567890123456789};
    long double g{1488.14888888};

    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
    std::cout << "C = " << c << std::endl;
    std::cout << "D = " << d << std::endl;
    std::cout << "E = " << e << std::endl;
    std::cout << "F = " << f << std::endl;
    std::cout << "G = " << g << std::endl;

    std::cout << "Размер A = " << sizeof(a) << std::endl;
    std::cout << "Размер B = " << sizeof(b) << std::endl;
    std::cout << "Размер C = " << sizeof(c) << std::endl;
    std::cout << "Размер D = " << sizeof(d) << std::endl;
    std::cout << "Размер E = " << sizeof(e) << std::endl;
    std::cout << "Размер F = " << sizeof(f) << std::endl;
    std::cout << "Размер G = " << sizeof(g) << std::endl;

    return 0;
}
