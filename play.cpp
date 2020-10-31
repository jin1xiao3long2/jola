#include <iostream>
#include <map>
#include <string>

using std::map;
class Foo{
private:
    map<int , Foo> _map;

public:
    //Foo() = delete;
    Foo() = default;
    explicit Foo(int i){
        _map[i] = *this;
    }
    ~Foo() = default;

    map<int, Foo> getmap(){
        return _map;
    }
};

int main()
{
//    Foo *t = new Foo(1);
//    std::cout << t->getmap().begin()->second.getmap().begin()->first << std::endl;
    std::string a("");
    if(a)
    {
        std::cout << "123" << std::endl;
    }
    return 0;
}