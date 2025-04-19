#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Hat 
{
    int price;
    string name;
    int age;
};

int main ()
{
    Hat my_hat;
    my_hat.price = 1488;
    my_hat.age = 18;
    cout << "Введите как вас зовут: ";
    getline(cin, my_hat.name);
    cout << "Смари " << my_hat.name << " чипсы стоят: " << my_hat.price << " рублей" << "\nНО! Тебе нет " << my_hat.age << " Лет.";
    cout << " по этому ди нахуй";
    return 0;
}
