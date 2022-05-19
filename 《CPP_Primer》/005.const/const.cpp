/*
 * @Author: linkenzone
 * @Date: 2021-11-17 10:10:14
 * @Descripttion: Do not edit
 */
#include <iostream>
using namespace std;

// const 试验场

int main()
{
    // tips:
    // 离变量名最近的符号对变量的类型有最直接影响

    // 顶层 const : 指针 本身是个常量
    // 底层 const : 指针 所指的对象是一个常量

    // ---顶层 const---
    // 把 * 放在 const 关键字之前用以说明指针是一个常量
    // 可以改变值，但是不能改变指针的值
    int num = 0;
    int *const p1 = &num; // 不能改变p1的值
    const int ci = 42;    // 不能改变c1的值 , 包括它的地址也不能改变

    cout << "p1:" << p1 << endl;  // 0x61fe14
    cout << "p1:" << *p1 << endl; // 0
    cout << "p1:" << &p1 << endl; // 0x61fe18

    cout << "ci:" << ci << endl;  // 42
    cout << "ci:" << &ci << endl; // 42

    // 这时 对象的值是可以改变的
    *p1 = 10;
    cout << "---修改对象的值后---" << endl;
    cout << "p1:" << *p1 << endl;  // 10
    cout << "num:" << num << endl; // 10

    // ---底层 const---
    // 指针 所指的对象是一个常量，可以改变地址
    const int *p2 = &ci;
    p2 = &num; // 正确：int* 能转换成 const int*
    cout << "---修改指针的值后---" << endl;
    cout << "p2:" << p2 << endl;   // 10
    cout << "*p2:" << *p2 << endl; // 10

    // 靠右的const是顶层const，靠左的是底层const
    const int *const p3 = p2;
    // int *p = p3;  错误：p3 包含底层const的定义，而p没有

    // 用于声明引用的const都是底层 const
    const int &r2 = num; //正确：const int& 可以绑定到一个普通int上
    int &const r2 = num; 

    // r2 = 20; // 错误
    num = 20; // 正确
    cout << "---修改 const int & 的值后---" << endl;
    cout << "num:" << num << endl; // 20
    cout << "r2:" << r2 << endl;   // r2

    return 0;
}