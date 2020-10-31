#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(){
    double a, b, result;
    cin >> a >> b;
    try{
        if(b == 0)
            throw std::runtime_error("can't devide zero!");
        result = a / b;
    } catch (std::logic_error &e) {
        cerr << e.what() << endl;
        exit(-1);
    } catch (std::runtime_error &e) {
        cerr << e.what() << endl;
        exit(-1);
    }
    cout << "a / b = " << result << endl;
    return 0;
}