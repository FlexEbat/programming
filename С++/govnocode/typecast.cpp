// typecast.срр - принудительное изменение типов

#include <iostream>
int main ()
{
    using namespace std;
    int auks, bats, coots ;
    // следующий оператор суммирует значения типа doube ,
    // а полученный результат преобразуется в тип int
    auks = 19.99 + 11.99;
    // эти операторы суммируют целочисленные
    bats = (int) 19.99 + (int) 11.99;
    coots = int (19.99) + int (11.99);
    cout << "auks = " << auks << ", bats =" << bats;
    cout << ", coots = " << coots << endl;
    char ch = ' Z ' ;
    cout << " The code for " << ch << " is ";
    cout << int ( ch) << endl;
    cout << " Yes , the code i s ";
    cout << static_cast<int> ( ch) << endl ;
    return 0; 
}