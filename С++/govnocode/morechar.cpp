#include <iostream>

int main ()
{
    using namespace std;
    char ch;
    cin >> ch;
    int i;
    cout << "The ASCII coed of the character for "<< ch << " is" << endl;
    cout << "Add one to the character code character" << endl;
    ch +=1;
    i = ch;
    cout << "The ASCII code of the character for "<< ch << " is " << i << endl;
    cout << "Displaying char ch using cout.put(ch): ";
    //Использование cout.put() для отображения символьной константы 
    cout.put(ch);
    cout.put('!');
    cout << endl << "Done" << endl;
    return 0;
}

