#pragma once

struct A final{
    int a;
};

class C{

private:
    void show(){
        A *a = new A;
    }
};