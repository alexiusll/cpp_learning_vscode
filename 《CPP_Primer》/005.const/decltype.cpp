/*
 * @Author: linkenzone
 * @Date: 2021-11-17 14:24:28
 * @Descripttion: Do not edit
 */

#include <iostream>
using namespace std;

int main()
{
    // decltype
    // 作用： 选择并返回操作数的数据类型，编译器分析表达式并得到它的类型，却实际计算表达式的值

    // decltype(f()) sum = x; // sum 的类型就是函数f的返回类型

    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // x 的类型是 const int
    decltype(ci) y = x; // y 的类型是 const int&, y绑定到变量x
    // decltype(ci) z; // 错误：z在是一个引用，必须初始化

    // 因为 cj 是一个引用，decltype(cj)的结果就是引用类型，因此作为引用的z必须被初始化

    // decltype 的结果可以是引用类型
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // 正确：加法的结果是int,因此b是一个（未初始化）int
    // decltype(*p) c; // 错误：c 是int & , 必须初始化
    // 如果表达式是解引用操作，则 decltype 将得到引用类型
    // 因此，decltype(*p)的结果类型就是int&,而非int。

    // 不加括号，得到的结果就是该变量的类型
    // 加上了一层或多层括号，编译器会把它当成是一个表达式

    // decltype((i)) d; //错误：d是int&, 必须初始化
    decltype(i) e; // 正确：e是一个（未初始化）int

    // 练习题 2.37
    int a = 3, bb = 4;
    decltype(a) c = a;
    decltype(a = bb) d = a;
    // c 是 int 类型，值为 3。d 是 int& 类型，绑定到 a。
    cout << "c:" << c << endl; // 3
    cout << "d:" << d << endl; // 3

    return 0;
}