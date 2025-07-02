#include <iostream>
using namespace std;

void print(const char* text) {
    cout << text;
}

char* input(const char* text) {
    static char forReturn[100];
    print(text);
    cin >> forReturn;
    return forReturn;
}