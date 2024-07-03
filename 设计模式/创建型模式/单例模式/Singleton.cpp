/*
 * @Author: linkenzone
 * @Date: 2022-05-19 16:36:54
 * @Descripttion: Do not edit
 * 
 * 
 */

//! 单例模式
//* 这是一种最佳的方式
//* 局部静态变量不仅只会初始化一次，而且还是线程安全的。

/*
* 这种单例被称为Meyers' Singleton。这种方法很简洁，也很完美，但是注意：
* gcc 4.0之后的编译器支持这种写法。
* C++11及以后的版本（如C++14）的多线程下，正确。
* C++11之前不能这么写。
*/

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Singleton
{
public:
    static T &Instance();
    Singleton(const Singleton &) = delete; // 删除单例的拷贝构造
    Singleton &operator=(const Singleton &) = delete; // 删除单例的赋值构造

private:
    Singleton() = default;
    ~Singleton() = default;
};

template <typename T>
T &Singleton<T>::Instance()
{
    //* 局部静态变量不仅只会初始化一次，而且还是线程安全的。
    cout << "获取实例..." << endl;
    static T instance;
    return instance;
}

class A
{
};

int main()
{
    auto &a = Singleton<A>::Instance();
    auto &b = Singleton<A>::Instance();

    //* assert()相当于一个if ()语句，如果满足断言的执行程序，如果不满足则抛错误。
    assert(&a == &b);
}