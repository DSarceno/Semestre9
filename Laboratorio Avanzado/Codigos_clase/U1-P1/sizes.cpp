#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    bool        boolVar;
    char        charVar;
    unsigned    unsignedVar;
    int         intVar;
    float       floatVar;

    cout<< "Bytes utilizados por bool:\t"       << sizeof(boolVar)      << endl;
    cout<< "Bytes utilizados por char:\t"       << sizeof(charVar)      << endl;
    cout<< "Bytes utilizados por unsigned:\t"   << sizeof(unsignedVar)  << endl;
    cout<< "Bytes utilizados por int:\t"        << sizeof(intVar)       << endl;
    cout<< "Bytes utilizados por float:\t"      << sizeof(floatVar)     << endl;

    return 0;
}