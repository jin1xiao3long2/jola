#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

class Foo {

public:
    friend class const_Foo;

private:
    int data;

public:
    Foo(int data) : data(data) {}

    Foo() = delete;

    int getData() const {
        return data;
    }
};

class const_Foo {


private:
    int data;

public:
    const_Foo(int data) : data(data) {}

    const_Foo() = delete;

    const_Foo(const Foo &var) : data(var.data) {};

    int getData() const {
        return data;
    }
};


void fun1(Foo &var) {
    cout << var.getData() << endl;
}

void fun2(const Foo &var) {
    cout << var.getData() << endl;
}

void fun3(const const_Foo &var) {
    cout << var.getData() << endl;
}

constexpr int get1()
{
    return 1;
}

int main() {
    Foo a(1);
    const Foo b(2);
    fun1(a);

    fun2(b);
    //fun1(b);
    fun2(a);
    const_Foo c(3);
    fun3(c);
    fun3(a);

    int v = 3;
    int *pv = &v;
    const int g = v;
    cout << v << endl;
    cout << g << endl;
    v = 4;
    constexpr int m = get1();
    cout << g << endl;
    const int cv = 3;
    const int *pcv = &cv;
    const int *const pcvc = &cv;
    const int acv = 4;
    pcv = &acv;
    //pcvc = &acv;
    std::shared_ptr<Foo> f = std::make_shared<Foo>(a);
    cout << f.use_count() << endl;
    std::shared_ptr<Foo> u(f);
    cout << f.use_count() << "   " << u.use_count() << endl;

    return 0;
}