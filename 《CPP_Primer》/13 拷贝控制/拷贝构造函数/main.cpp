/*
 * @Author: linkenzone
 * @Date: 2022-03-16 19:56:41
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
    Foo();            // 默认构造函数
    Foo(const Foo &); // 拷贝构造函数 （第一个参数是自身类型的引用，且任何额外参数都有默认值)
};

void f(vector<int> a){
    cout << a[0] << endl;
}

int main()
{
    // 直接初始化
    string dots(10, '.');
    string s(dots);

    // 拷贝初始化
    // ! 使用拷贝构造函数来完成
    string s2 = dots;
    string null_book = "9-999-99999-9";
    string nines = string(100, '9');

    //* 拷贝初始化的限制
    vector<int> v1(10); // 正确：直接初始化
    // vector<int> v2 = 10; // 错误：接受大小的参数的构造函数是 explicit 的
    // void f(vector<int>); // f 的参数进行拷贝初始化
    // f(10); //  错误：不能用一个 explicit 的构造函数拷贝一个实参
    f(vector<int>(10)); // 正确：从一个 int 直接构造一个临时 vector

    //* 编译器可以绕开拷贝构造函数
    string null_book_01 = "9-999-99999-9"; // 拷贝初始化
    string null_book_02("9-999-99999-9"); // 编译器略过了拷贝构造函数

    return 0;
}