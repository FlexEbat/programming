#include <iostream>

int AstronomicalUnits(int year)
{
    return year * 63240;  
}

int main ()
{
    using namespace std;
    int year;
    cout << "Перевод светового года в астрономические единицы" << endl;
    cout << "Введите количество световых лет: ";
    cin >> year;
    cout << "Кол-во астрономических единиц!!!!: " << AstronomicalUnits(year) << endl;
    return 0;
}

