#include <iostream>
#include <climits>

int main ()
{
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_long_long = LLONG_MAX;
   // Операция sizeof выдает размер типа или переменной 
   cout << "int: " << sizeof (int) << " bytes." << endl;
   cout << "short: " << sizeof (n_short) << " bytes." << endl;
   cout << "long: " << sizeof (n_long) << " bytes." << endl;
   cout << "long long: " << sizeof (n_long_long) << " bytes." << endl;
   
    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_long_long << endl;
    cout << "\n";
    cout << "Minimal int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    return 0;
}

