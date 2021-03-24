#include <iostream>

using std::cout;
using std::endl;

int main() {

    //要认识表达式, 首先要认识运算符。
    //运算符几个基本概念： 操作数目， 运算对象， 运算结果（返回值）。
    //由运算符与操作数构成的式子即为表达式。
    // +  （2+3） 二目运算符； 运算对象为两个int (该例中）； 结果是获得两个数之和。
    // ！   ！condition  一目运算符； 运算对象为一个bool值（一般情况）； 结果是获得bool值的反

    //而某些运算符在面对不同的运算对象时，可能有不同的操作数以及不同的作用。
    int num = 3;
    int *ptr = &num;
    cout << "Num(*ptr) * Num(*ptr) = " << (*ptr) * (*ptr) << endl;

    //优先级 优先级高的先运算
    cout << "5 + 3 * 2 = " << 5 + 3 * 2 << endl;

    //优先级表（xxx页）
    //不知道优先级，利用括号来解决

    //结合律 同优先级从左至右计算
    cout << "10 - 2 - 1 = " << 10 - 2 - 1 << endl;

//    int Num = 5;
//    int *a = &Num;   //     * 声明指针 , & 取地址
//    int &b = Num;    //     & 引用
//    cout << "The value of Num is " << Num << endl;
//    cout << "The value of '*a' is " <<  *a << endl;  // * 解引用
//    cout << "The value of 'b * b' is " << b * b << endl;  //乘法



    return 0;
}