#include <iostream>
#include <string>
#include <sstream>
//bool operator<(const foo& lhs, const foo& rhs){
//    return lhs.end < rhs.end;
//}

using namespace std;

int main(){
    istringstream istr("5 1.2");
    int a;
    float b;
    istr >> a >> b;
    cout << a << "  " << b << endl;
    return 0;
}