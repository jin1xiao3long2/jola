#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //输入你的选项，输出你的选择
    char grade;
    cout << "What's your grade?" << endl;
    cout << "A、2017 B、2018" << endl;
    cout << "C、2019 D、2020" << endl;
    cin >> grade;

    switch(grade){
        case 'A':
            cout << "2017" << endl;
            break;
        case 'B':
            cout << "2018" << endl;
            break;
        case 'C':
            cout << "2019" << endl;
            break;
        case 'D':
            cout << "2020" << endl;
            break;
        default:
            "not correct input";
            break;
    }
}