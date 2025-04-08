#include <iostream>

using namespace std;

int agetomonth(int age) 
{
    return age * 12;  
}

int main ()
{
    int age;
    cout << "Введит ваш возраст: ";
    cin >> age;
    cout << "Ваш возраст в месяцах: " << agetomonth(age) << endl;   
    return 0;
}