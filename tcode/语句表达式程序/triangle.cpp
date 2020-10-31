#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    float a, b, c;
    int state;
    cin >> a >> b >> c;
    int max = std::max(std::max(a,b),c); //std::max(a,b): 求a和b的最大值
    if(a + b <= c){
        state = 0;
    }else{
        if(a * a + b * b == c * c){
            state = 1;
        }else if(a * a + b * b < c * c){
            state = 2;
        }else{
            state = 3;
        }
    }

    if(state = 0){
        cout << "Not a triangle" << endl;
    }else if(state = 1){
        cout << "Right triangle" << endl;
    }else if(state = 2){
        cout << "Obtuse triangle" << endl;
    }else{
        cout << "Acute triangle" << endl;
    }
    return 0;
}