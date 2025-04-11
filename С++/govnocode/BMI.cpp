// typecast.срр - принудительное изменение типов

#include <iostream>
using namespace std;


int main ()
{
    double height, weight, BMI;
    cout << "Ввете ваш рост в СМ(~180.5): ";
    cin >> height;
    if (height < 0 || height > 300) {
        cout << "Давай без давай" << endl;
    } else {

        cout << "Введите ваш вес в КГ(~99.9): ";
        cin >> weight;
        if (weight < 0 || weight > 300 ) {
            cout << "Давай, ты уже умiр" << endl;
        } else {
        BMI = (weight * 10000) / (height * height);
        cout << "Ваш BMI = " << BMI << endl;
    }
    }

}