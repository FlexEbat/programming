#include <iostream>

using namespace std;

int agetomonth(int age) 
{
    return age * 12;  
}

int main ()
{
    int age;
    
    cout << "Введите ваш возраст: ";
    cin >> age;
    
    if (age < 0 || age > 100 )
    {
        cout << "Возвраст должен быть > 0 и < 100" << endl;
        return 1;
    } else {
        cout << "Ваш возраст в месяцах: " << agetomonth(age) << endl;   
    }
    return 0;
    
}