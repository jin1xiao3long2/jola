#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
    string text;
    cin >> text;
    int chars[5] = {0};  //a, e, i, o, u

    for(auto const e : text){
        switch (e) {
            case 'A':
            case 'a':
                chars[0]++;
                break;
            case 'E':
            case 'e':
                chars[1]++;
                break;
            case 'I':
            case 'i':
                chars[2]++;
                break;
            case 'O':
            case 'o':
                chars[3]++;
                break;
            case 'U':
            case 'u':
                chars[4]++;
                break;
            default:
                break;
        }
    }

    cout << "The nums of 'A'/'a' is " << chars[0] << endl;
    cout << "The nums of 'E'/'e' is " << chars[1] << endl;
    cout << "The nums of 'I'/'i' is " << chars[2] << endl;
    cout << "The nums of 'O'/'o' is " << chars[3] << endl;
    cout << "The nums of 'U'/'u' is " << chars[4] << endl;
    return 0;
}