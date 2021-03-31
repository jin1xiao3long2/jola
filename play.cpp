#include "play.hpp"
#include <string>
#include <iostream>

int main() {

    std::string s;
    s = "3qwe.asd";
    int n = s.rfind('.');
    std::cout << n << std::endl;
    std::string d = s.substr(n + 1, s.size() - 1);
    std::cout << d << std::endl;

}