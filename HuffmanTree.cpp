#include "HuffmanTree.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    char userCommand;
    std::string filename;
    do {
        cout << "Main menu" << endl;
        cout << "1. Encode" << endl;
        cout << "2. Decode" << endl;
        cout << "3. Exit" << endl;
        userCommand = getchar();
        while (cin.get() != '\n');
        if (userCommand == '1') {
            cout << "Please enter the filename: " << endl;
            cin >> filename;
            getchar();
            HuffmanTree(filename, "encode");
        } else if (userCommand == '2') {
            cout << "Please enter the filename: " << endl;
            cin >> filename;
            getchar();
            try {
                HuffmanTree(filename, "decode");
            } catch (std::runtime_error e) {
                std::cerr << e.what();
            }
        } else if (userCommand == '3') {
            cout << "Success exit" << endl;
        } else {
            cout << "Please enter the correct order" << endl;
        }
    } while (userCommand != '3');

    return 0;
}