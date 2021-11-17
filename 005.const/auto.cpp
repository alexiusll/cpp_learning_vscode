/*
 * @Author: linkenzone
 * @Date: 2021-11-17 11:15:26
 * @Descripttion: Do not edit
 */
#include <iostream>
using namespace std;

int main()
{
    float val1 = 1.2f;
    float val2 = 3.498f;

    auto item = val1 + val2; // item 初始化位 val1 和 val2相加的结果

    // 正确：i是整数,p是整型指针
    auto i = 0, *p = &i;

    // 错误: sz 和 pi的类型不一致
    // auto sz = 0, pi = 3.14;

    cout << "item:" << item << endl;

    int i = 0, &r = i;
    auto a = r; // a 是一个整数 （ r 是 i的别名，而i是一个整数）

    // auto 一般会忽略掉顶层const 同时底层 const 则会保留下来
    const int ci = 10, &cr = ci;
    auto b = ci; // b 是一个整数 (ci的顶层const特性被忽略掉了)
    auto c = cr; // c 是一个整数 (cr 是 ci 的别名，ci本身是一个顶层 const)
    auto d = &i; // d 是一个整型指针（整数的地址就是指向整数的指针）
    auto e = &ci; // e 是一个指向整数常量的指针（对常量取对象取地址是一种底层const)

    b = 20;
    c = 30;
    *d = 40;
    // *e = 50; // 错误

    // 如果希望推断出的 auto 类型是一个顶层const , 需要明确指出
    const auto f = ci; //f 是 const int

    // 还可以将引用类型设为auto，此时原来的初始化规则仍然使用
    auto &g = ci; // g 是一个整型常量的引用,绑定到ci
    // auto &h = 42; // 错误：不能位非常量引用绑定字面值
    const auto &j = 42; // 正确：可以为常量引用绑定字面值

    auto k = ci, &l = i; // k是整数，l是整型引用
    auto &m = ci, *p = &ci; // m是对整型常量的引用，p是指向整型常量的指针
    // 错误：i的类型是int 而 &ci 的类型是 const int
    // auto &n = i , *p2 = &ci;
    return 0;
}