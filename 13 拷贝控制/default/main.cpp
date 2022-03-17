/*
 * @Author: linkenzone
 * @Date: 2022-03-16 21:16:48
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
    Foo(const Foo &foo) = default; // 拷贝构造函数 （第一个参数是自身类型的引用，且任何额外参数都有默认值)
    // {
    //     a = foo.a;
    //     b = "拷贝构造函数";
    // }
    Foo &operator=(const Foo &foo) // 赋值运算符
    {
        a = foo.a;
        b = "赋值运算符";

        return *this; // 返回一个此对象的引用
    }
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
    Foo foo01(1, "233");
    foo01.print();

    Foo foo02 = Foo(foo01);
    foo02.print();

    Foo *foo03 = new Foo(2, "33333");
    foo03->print();

    return 0;
}