#include <iostream>

int main()
{
    double pi = 3.141592;
    double* ptr_pi;
    ptr_pi = &pi;

    std::cout << "Pi = " << pi << std::endl;
    *ptr_pi = 2.71828;
    std::cout << "Новое значение pi(через ptr_pi) = " << pi << std::endl;
    std::cout << "ptr_pi = " << *ptr_pi << std::endl;
}