#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int first_day = 3;
    vector<int> dates = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 0, days = 0;
    cin >> month;
    for (int i = 1; i < month; i++) {
        days += dates[i];
    }
    int last_day = (days + first_day - 1) % 7 + 1; //获取该月第一天星期几
    cout << last_day << endl;
    cout << "Mon\tTue\tWed\tThur\tFri\tSat\tSun\t" << endl; //'\t'的作用
    for (int i = 1; i < last_day; i++)
        cout << '\t'; //把前面几天空出来
    for (int i = 1; i <= dates[month]; i++) {
        cout << i << '\t';
        if ((i + last_day - 1) % 7 == 0)         //每次到周日换行
            cout << endl;
    }

    return 0;
}