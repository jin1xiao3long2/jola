#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
T add(T a, T b){
    return a+b;
}

int main(){
    cout << add(1,3) << endl;
    return 0;
}