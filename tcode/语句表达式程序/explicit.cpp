#include <iostream>

using std::cout;
using std::endl;

int main(){
    int Int = 3;
    double Double = 3.3;
    cout << typeid(Int + Double).name() << endl;
    cout << typeid(static_cast<char>(Double) + Int).name() << endl;
    return 0;
}