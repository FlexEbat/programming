#include <iostream>

int add(int &a, int &b){
    std::cout << "Введит першое число: ";
    std::cin >> a;
    std::cout << "Введит второе число: ";
    std::cin >> b;
    
    return a + b;
}

int main()
{
    int a,b;
    int result = add(a, b);
    std::cout << a << " + " << b << " = " << result << std::endl;
    return 0;
}