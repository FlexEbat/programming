#include <iostream>
#include <string>


struct Person
{
    std::string name;
    std::string surname;
    std::string middlename;
    int age; 
    std::string Address_of_residence; // адрес проживания
    std::string job_title; // должност
};

enum class PaymentType { Piecework, Hourly };

void Registration_employee(Person &Worker)
{
    std::cout << "Введите имя вашего сотрудника: ";
    std::getline(std::cin, Worker.name);
    std::cout << "Введите фамилию вашего сотрудника: ";
    std::getline(std::cin, Worker.surname);
    std::cout << "Введите отчество вашего сотрудника: ";
    std::getline(std::cin, Worker.middlename);
    std::cout << "Введите возраст сотрудника: ";
    std::cin >> Worker.age;
    std::cin.ignore();
    std::cout << "Введите адрес проживания сотрудника: ";
    std::getline(std::cin, Worker.Address_of_residence);
    std::cout << "Введите должность сотрудника: ";
    std::getline(std::cin, Worker.job_title);
}

int main()
{
    int choice;

    
    std::cout << "Welcome to our factory.Here you can register an employee, but before that you need to indicate:\n";
    std::cout << "1. Name.\n 2.Surname.\n 3.MiddleName.\n 4.Address of residence.\n5. Dolly.\n6.Type of payment (piecework, hourly)\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore();
    Person Worker;
    
    if (choice == 1) 
    {

        Registration_employee(Worker);


    }
    std::cout << "\nИнформация о сотруднике:\n";
    std::cout << "Имя: " << Worker.name << "\n";
    std::cout << "Фамилия: " << Worker.surname << "\n";
    std::cout << "Отчество: " << Worker.middlename << "\n";
    std::cout << "Возраст: " << Worker.age << "\n";
    std::cout << "Адрес проживания: " << Worker.Address_of_residence << "\n";
    std::cout << "Должность: " << Worker.job_title << "\n";
    return 0;
    
}
