#include <iostream>

int main()
{
    int x = 10;
    int* ptr_x;
    ptr_x = &x;

    std::cout << "X = " << x << std::endl;
    std::cout << "А *ptr_x = " << *ptr_x << std::endl;
    std::cout << "А ptr_x = " << ptr_x << std::endl;
    return 0;
}