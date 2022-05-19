/*
 * @Author: linkenzone
 * @Date: 2022-03-16 21:26:16
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Foo
{
public:
    Foo() = default; // 拷贝控制成员
    Foo(int a, const string b)
    {
        this->a = a;
        this->b = b;
    }
    Foo(const Foo &foo) = delete; // 拷贝构造函数 （第一个参数是自身类型的引用，且任何额外参数都有默认值)
    Foo &operator=(const Foo &foo) = delete; // 赋值运算符
    ~Foo() // ! 析构函数，但是自身并不直接销毁成员
    {
        cout << "析构函数 " << a << endl;
    }
    void print()
    {
        cout << "打印 ==> " << a << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }

private:
    int a;
    string b;
};

int main()
{
    Foo a(1, "233");
    // Foo b(a); // 错误
    
    return 0;
}