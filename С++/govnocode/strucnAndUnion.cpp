#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
    union id
    {
        int id;
    } id_val;
};

int main()
{
    Person person[2] {
        {"John", 30},
        {"Jane", 25}
    };
    cout << "Вас зовут: " << person[0].name << "; " << "Вам " << person[0].age << " лет." << " Но у вас нет ID. Надо это исправить!" << endl;
    cout << "Введите ваш ID: ";
    cin >> person[0].id_val.id;
    cout << "ID: " << person[0].id_val.id << "; "<< "Вас зовут: " << person[0].name << "; " << "Вам " << person[0].age << " лет." << endl;
    cout << "Второму персонажу автоматически присвоен ID.\n"; 
    cout << "ID: " << person[0].id_val.id + 1 << "; " << "Вас зовут: " << person[1].name << "; " << "Вам " << person[1].age << " лет." << endl;

    return 0;

}
