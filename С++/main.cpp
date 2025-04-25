#include <iostream>
#include <string>
using namespace std;

enum class COLOR {
    RED = 30, GREEN = 32, BLUE = 34, YELLOW = 33,
    CYAN = 36, MAGENTA = 35, WHITE = 39, BLACK = 37,
};
string color_to_string(COLOR c) {
    switch (c) {
        case COLOR::RED: return "RED";
        case COLOR::GREEN: return "GREEN";
        case COLOR::BLUE: return "BLUE";
        case COLOR::YELLOW: return "YELLOW";
        case COLOR::CYAN: return "CYAN";
        case COLOR::MAGENTA: return "MAGENTA";
        case COLOR::WHITE: return "WHITE";
        case COLOR::BLACK: return "BLACK";
        default: return "UNKNOWN";
    }
}

int main()
{
    const int WEEK = 7;
    cout << "sizeof(COLOR) = " << sizeof(COLOR) << endl;

    COLOR W = COLOR::RED;
    cout << "Color = " << color_to_string(W) << endl;

    cout << "sizeof(WEEK) = " << sizeof(WEEK) << endl;

    return 0;
}
