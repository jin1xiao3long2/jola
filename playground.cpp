#include <iostream>
#include <vector>

class A{
public:
    int x;
private:
    int y;
public:
    explicit A(int v): x(v){std::cout << "A" << std::endl;}
    explicit A(int i, double d): x(i), y(d) {std::cout << "A+" << std::endl;}
    A ret(){
        return  A(42, 0.1);
    }
    A(A&&){
        std::cout << "Hi" << std::endl;
    }ww
    A(A const &){
        std::cout << "Hello" << std::endl;
    }
};

int main()
{
    A a(3);
    A b(a.ret());
    std::cout << b.x << std::endl;

    return 0;
}