// 1DAE21N - Belmans Jef

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
    int intFoo{ 3 };
    char charBar{ 'A' };
    bool boolFoo{ 0 };
    float floatBar{ 3.14f };
    double doubleFoo{ 3.14 };

    cout << "Integer:   (" << intFoo << ")\n";
    cout << "Character: (" << charBar << ")\n";
    cout << "Boolean:   (" << boolFoo << ")\n";
    cout << "Float:     (" << floatBar << ")\n";
    cout << "Double:    (" << doubleFoo << ")\n";

    return 0;
}