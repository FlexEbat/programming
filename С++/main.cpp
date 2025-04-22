#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person {
    string name;
    short age;
    double money;
};

int main ()
{
    person person;
    cout << "Введите сколько вам лет: ";
    cin >> person.age;
    cout << "Введите сколько у вас денег: ";
    cin >> person.money;
    cin.ignore();
    cout << "Введите как вас зовут: ";
    getline(cin, person.name);
    cout << "\n";
    cout << "Hi " << person.name << " u have some money: " << person.money << " dollars" << " and u " << person.age << " ages";
    return 0;

}
