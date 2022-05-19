/*
 * @Author: linkenzone
 * @Date: 2022-03-20 22:13:21
 * @Descripttion: Do not edit
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int i = 42;
    int &r = i; // 正确：左值引用
    // int &&rr = i; //! 错误的：无法将右值引用绑定到左值
    // int &r2 = i * 42; // ! 错误地：非常量引用的初始值必须为左值
    const int &r3 = i * 42; //* 正确的！ 我们可以将一个 const 的引用绑定到一个右值上
    int &&rr2 = i * 42;     //* 正确的！ 将 rr2 绑定到乘法结果上

    // * 左值持久 ， 右值短暂

    // * 变量是左值
    int &&rr1 = 42; // 正确的，字面值常量是右值
    // int &&rr2 = rr1; //! 错误的，表达式 rr1 是左值

    // * 标准库 move 函数  #include <utility>
    // * 作用：获得绑定到左值上的右值引用
    int &&rr3 = move(rr1); // * 正确的
    // * 除了对 rr1 赋值或消除它之外，我们将不再使用它。
    // * 在调用 move 之后，我们不能对移后源对象的值做任何假设

    rr3 = 10;
    rr1 = 11;

    cout << rr1 << endl;
    cout << rr2 << endl;

    int a = 10;
    int &rb = a;
    int &&rrb = move(a);
    int &&rrc = move(rrb);
    rrc = 999;
    a = 777;
    cout << "a: " << a << endl;
    cout << "rb: " << rb << endl;
    cout << "rrb: " << rrb << endl;
    cout << "rrc: " << rrc << endl;

    int aa = 50;
    vector<int> int_list({move(aa)});
    int_list.push_back(1);
    // int_list.push_back(move(*aa));
    cout << "aa: " << aa << endl;
    cout << "int_list[0]: " << int_list[0] << endl;
    int_list[0] = 88888;
    aa = 11111;
    cout << "aa: " << aa << endl;
    cout << "int_list[0]: " << int_list[0] << endl;
}