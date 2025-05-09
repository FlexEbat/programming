#include <iostream>
#include <string>

enum class PaymentType { Piecework, Hourly };

struct Person
{
    std::string name;
    std::string surname;
    std::string middlename;
    int age; 
    std::string Address_of_residence; // адрес проживания
    std::string job_title; // должност
    PaymentType Payment;
};


void Registration_employee(Person &Worker)
{
    int ChoicePayment;
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
    std::cout << "Введите способ оплаты: \n";
    std::cout << "1 - Почасовой. \n";
    std::cout << "2 - Сдельный. \n";
    std::cin >> ChoicePayment;
    std::cin.ignore();

    if (ChoicePayment == 1){
        Worker.Payment = PaymentType::Hourly;
    } else {
        Worker.Payment = PaymentType::Piecework;
    }
}

void Info_Employee(Person &Worker)
{
    std::cout << "\nИнформация о сотруднике:\n";
    std::cout << "Имя: " << Worker.name << "\n";
    std::cout << "Фамилия: " << Worker.surname << "\n";
    std::cout << "Отчество: " << Worker.middlename << "\n";
    std::cout << "Возраст: " << Worker.age << "\n";
    std::cout << "Адрес проживания: " << Worker.Address_of_residence << "\n";
    std::cout << "Должность: " << Worker.job_title << "\n";
    if (Worker.Payment == PaymentType::Hourly) {
        std::cout << "Способ оплаты: Почасовой\n";
    } else {
        std::cout << "Способ оплаты: Сдельный\n";
    }
}


int main()
{
    Person Worker;
    while (true)
    {
        
        int choice;
        std::cout << "Лаборатория Xum1337. Вы можете зарегистрировать сотрудника и посмотреть о нём информацию!\n";
        std::cout << "Your choice*(1 - registration; 2 - info): ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            Registration_employee(Worker);
            break;
        case 2:
             Info_Employee(Worker);
             break;
        default:
            break;
        }
        // Registration_employee(Worker);
        // Info_Employee(Worker);

    }
    


    return 0;
    
}
