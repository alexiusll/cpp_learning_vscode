/*
 * @Author: linkenzone
 * @Date: 2022-03-16 20:29:33
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
    Foo(); // 默认构造函数
    Foo(int a, const string b)
    {
        this->a = a;
        this->b = b;
    }
    Foo(const Foo &foo) // 拷贝构造函数 （第一个参数是自身类型的引用，且任何额外参数都有默认值)
    {
        a = foo.a;
        b = "拷贝构造函数";
    }
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
    void pirnt()
    {
        cout << "打印 ==> " << a << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }

private:
    int a;
    string b;
};
// ! 赋值运算符通常应该返回一个指向其左侧运算对象的引用

int main()
{
    Foo foo_01(1, "233");
    foo_01.pirnt();

    Foo foo_02 = foo_01; // 拷贝构造函数
    foo_02.pirnt();

    Foo foo_03(foo_02); // 拷贝构造函数
    foo_03.pirnt();

    foo_03 = foo_01; // 赋值运算符
    foo_03.pirnt();

    return 0;
}