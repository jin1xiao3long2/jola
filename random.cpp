#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

std::ostream &operator<<(std::ostream &out, vector<string> Vec) {
    int i = 0;
    for (auto const &e: Vec) {
        cout << e << "\t";
        i++;
        if (i == 4) {
            i = 0;
            cout << endl;
        }
    }
    return out;
}


int main() {

    vector<string> number;
    string num;
    int people = 0;
    while (std::getline(cin, num)) {
        if (num == "-1")
            break;
        for (auto const e : number) {
            if (num == e)
                cout << "Same number" << endl;
        }
        number.push_back(num);
        people++;
    }

    srand(time(0));

    int speed = 4;
    system("cls");
    cout << number << endl;
    cout << "Start" << endl;
    auto winner = string("").c_str();
    int del = 0;
    while (true) {
        if (speed <= 64)
            speed *= 2;
        if (_kbhit() && speed >= 64)
            break;
        del = rand() % people;
        winner = number.at(del).c_str();
        printf("\t%s\t\r", winner);

        Sleep(8000 / speed);
    }
    number.erase(number.begin() + del);
    cout << "First prize winner is " << winner << endl;
    cout << number;
    //cout << number;
    system("pause");

    cout << "Sencond prize" << endl;

    auto winner1 = string("").c_str();
    auto winner2 = winner1;
    int del1, del2 = 0;
    while (true) {
        if (speed <= 64)
            speed *= 2;
        if (_kbhit() && speed >= 64)
            break;
        del1 = rand() % (people - 1);
        del2 = rand() % (people - 1);
        if (del1 == del2)
            continue;
        winner1 = number.at(del1).c_str();
        winner2 = number.at(del2).c_str();
        printf("\t%s\tand\t%s\r", winner1, winner2);

        Sleep(8000 / speed);
    }
    cout << "Second prize winners are  " << winner1 << "  and  " << winner2 << endl;
    system("pause");

    return 0;
}