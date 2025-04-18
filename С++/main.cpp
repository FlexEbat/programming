#include <iostream>
// #include <cstring>
using namespace std;
int main () 
{
    const int SIZE = 20;
    char dessert[SIZE];
    char name[SIZE];
    cout << "Введите ваше имя: ";
    cin.getline(name, SIZE);
    cout << "Введите ваш любимый десерт: ";
    cin.getline(dessert, SIZE);
    cout << "Привет, " << name << "! Твой любимый десерт - " << dessert << "." << endl;
    return 0;
}