#include <iostream>

using std::cout;
using std::endl;

int main(){
    char Char = 'a';
    short Short = 2;
    int Int = 5;
    long int Longint = 23;
    float Float = 2.2;
    unsigned char Uchar = 'b';
    unsigned short Ushort = 3;
    unsigned int Uint = 4;
    unsigned long Ulong = 33;
    double Double = 3.3;
    long double Ldouble = 44.2;

    cout << typeid(Char + Int).name() << endl;

    return 0;
}