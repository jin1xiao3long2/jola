#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    "Please input 10 numbers";
    int i = 10;
    vector<int> Vec;
    while (i > 0) {
        int num = 0;
        cin >> num;
        Vec.push_back(num);
        i--;
    }

    int sum = 0;
    do {
        sum += Vec[i];
        i++;
    } while (i < 10);

    cout << "sum is " << sum << endl;

//    int start = 0, odd = 0;
//    while (true) {
//        if (start == 100) { break; }      //终止循环
//        if (start % 2 == 0) { continue; }   //跳过循环
//        odd += start;
//        start++;
//    }
//    cout << "odd numbers of 1 - 100 is " << odd << endl;

    return 0;
}