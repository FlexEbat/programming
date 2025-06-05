#include <iostream>

int main()
{
    int* ptr1;
    int* ptr2;
    int val1 = 10, val2 = 20;
    ptr1 = &val1;
    ptr2 = &val2;
    std::cout << "ptr1 = " << ptr1 << std::endl;
    std::cout << "ptr2 = " << ptr2 << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;

usefully
}