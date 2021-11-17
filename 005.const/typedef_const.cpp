/*
 * @Author: linkenzone
 * @Date: 2021-11-17 10:58:48
 * @Descripttion: Do not edit
 */
#include <iostream>
using namespace std;
// const 试验场
int main()
{
    // tips:
    // 离变量名最近的符号对变量的类型有最直接影响
    char c = 'o';
    char c1 = 'x';

    const char *p = &c;

    typedef char *pstring;  // char * 类型
    const pstring cstr = &c; // cstr 是指向char的 常量指针
    const pstring *ps;      // ps 是一个指针，它的对象是 指向char的常量指针

    const char *cstr1 = &c1; // 是对const pstring cstr 的错误理解

    // 用 char * 重写了声明语句，数据类型变成了 char ，而 * 成为了声明符的一部分
    // 这样改写的结果是，const char 成为了基本数据类型

    // cstr 的值是可以改变的
    *cstr = 'y';

    // 错误 cstr1的值不可改变
    // *cstr1 = 'o';

    cout << "cstr:" << *cstr << endl;
    cout << "cstr1:" << *cstr1 << endl;
}