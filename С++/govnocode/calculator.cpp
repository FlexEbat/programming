#include <iostream>
#include <cmath>

using namespace std;


void addition() 
{
    double a, b;
    cout << "Enter two numbers to add: " << endl;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << a << " + " << b << " = " << a + b << endl;
}

void subtraction() 
{
    double a, b;
    cout << "Enter two numbers to add\n";
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << a << " - " << b << " = " << a - b << endl;
}

int main () 
{
    int operation;
    cout << "Hi, this program is a calculator.\n" ;
    cout << "1. Addition\n2. Subtraction\n";
    cout << "Select the operation from the menu: ";
    cin >> operation;
    
    if (operation == 1) {
        addition();
        cout << endl;
    } else if (operation == 2) {
        subtraction();
        cout << endl;
    } else {
        cout << "Invalid operation selected." << endl;
    }

    return 0;
}