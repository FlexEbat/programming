// typecast.срр - принудительное изменение типов

#include <iostream>
using namespace std;

double inchesToPounds(double height)
{
    return height * 0.083333;
} 

int main ()
{
    cout << "Введите ваш рост в дюймах: ";
    double height;
    cin >> height;
    if (height < 0) {
        cout << "Ты че долбаёб, ты че не растёшь вообще?????" << endl;
    } else {
        cout << "Ваш рост в футах: " << inchesToPounds(height) << endl;
        cout << "Ваш рост в см: " << inchesToPounds(height) / 0.032808 << endl;
        cout << "Ваш рост в метрах:  " << inchesToPounds(height) / 3.2808 << endl;
    } 
    return 0; 
}

