#include <iostream>

int main()
{
    int last, a = 0, b = 1, next;
    std::cout << "Enter the number of terms: ";
    std::cin >> last;
    if (last > 12) {
        std::cout << "The number of terms is too large. Please enter a number less than or equal to 12." << std::endl;
        return 1;
    } else if (last <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;   
    }

    std::cout << "Fibonacci Series: " << a << " " << b << " ";
    for(int i = 2; i < last; i++){
        next = a + b;
        std::cout << next << " ";
        a = b;
        b = next;
    }
    return 0;
}
