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

void rubToUsd() {
    double rub;
    const double DOLLAR = 82.03;
    const std::string DATE = "18.04.2025";
    std::cout << "Курс актуален на " << DATE << std::endl;
    std::cout << "Введите сумму в рублях для перевода её в доллары: ";
    std::cin >> rub;
    if (rub <= 0){
        std::cout << "Сумма не может быть <= 0" << std::endl;
        rubToUsd();
    } else
    {
        double dollar = rub / DOLLAR;
        std::cout << "Ваши " << rub << " рублей - это " << dollar << " долларов"  << std::endl; 
    }

}

void usdToRub() {
    double rub;
    const double DOLLAR = 82.03;
    const std::string DATE = "18.04.2025";
    std::cout << "Курс актуален на " << DATE << std::endl;
    std::cout << "Введите сумму в рублях для перевода её в доллары: ";
    std::cin >> rub;
    if (rub <= 0){
        std::cout << "Сумма не может быть <= 0" << std::endl;
        rubToUsd();
    } else
    {
        double rub2 = rub * DOLLAR;
        std::cout << "Ваши " << DOLLAR << " долларов - это " << rub2 << " рублей"  << std::endl; 
    }

}

int main ()
{
    using namespace std;
    int choice;
    do 
    {
        cout << "Привет. Здесь ты можешь:\n 1. Из КГ в Фунты\n 2. Перевод рублей в доллары.\n 3. Перевод доллары в рубли\n";
        cout << "!!! ВЫХОД ИЗ ПРОГРАММЫ - 0 !!!\n";
        cout << "Что ты хочешь сделать: ";
        cin >> choice;
        if (choice == 1) {
            kgToPound();
        } else if (choice == 2) {
            rubToUsd();
        } else if (choice == 3) {
            usdToRub();
        }
    } while (choice != 0);
    cout << "Давай не заёбывай <3" << endl;
    
    return 0;
}