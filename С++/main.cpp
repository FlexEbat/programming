#include <iostream>

void kgToPound() 
{
    double kg, pound;
    std::cout <<"Введите вес в килограммах: ";
    std::cin >> kg;
    if (kg <= 0 ) {
        std::cout << "Вес не может быть <= 0" << std::endl;
    }
    else {
        pound = kg * 2.20462;
        std::cout << "Вес в фунтах: " << pound << std::endl;
    }
}    

int main ()
{
    using namespace std;
    int choice;
    do 
    {
        cout << "Привет. Здесь ты можешь:\n 1. Из КГ в Фунты\n 2. DOLLAR TO RUB.\n";
        cout << "Что ты хочешь сделать: ";
        cin >> choice;
        if (choice == 1) {
            kgToPound();
        }
        /* code */
    } while (choice != 0);
    cout << "Выход из программы." << endl;
    
    return 0;
}