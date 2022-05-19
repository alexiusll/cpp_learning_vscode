/*
 * @Author: linkenzone
 * @Date: 2022-03-21 14:33:42
 * @Descripttion: Do not edit
 */
#include <iostream>

using namespace std;

class Base
{
protected:
    int prot_men;
};

class Sneaky : public Base
{
    friend void clobber(Sneaky &);
    friend void clobber(Base &);
    int j;
};

// * 15.5
// * 派生类的成员或友元只能通过 派生类对象 来访问基类的受保护成员
// * 派生类对于一个 基类对象中 的受保护成员没有任何访问特权

//* 正确的 cobber 能访问 Sneaky 对象的 private 和 protected 成员
void clobber(Sneaky &s)
{
    s.j = s.prot_men = 0;
}

// ! 错误的 cobber 不能访问 Base 的 protected 成员
// void clobber(Base &b)
// {
//     b.prot_men = 0;
// }

// * ------ ------

class Base_02
{
    //* 添加 friend 声明，其他成员与之前的版本一致
    friend class Pal; // pal 在访问Base的派生类时不具有特殊性
protected:
    int prot_mem;
};

class Sneaky_02 : public Base_02
{
    int j;
};

class Pal
{
public:
    int f(Base_02 b) { return b.prot_mem; } //* 正确：Pal 是 Base_02 的友元
    // int f2(Sneaky_02 s) { return s.j; } // ! 错误的 Pal 不是 Sneaky 的友元
    //* 对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
    int f3(Sneaky_02 s) { return s.prot_mem; } //* 正确的！Pal 是 Base 的友元
};

//* D2 对 Base 的 protected 和 private 成员不具有特殊的访问能力
class D2 : public Pal
{
public:
    int mem(Base b)
    {
        // return b.prot_men; // ! 错误的，友元关系不能继承
    }
};

// * ------ 改变个别成员的可访问性 ------
class Base_3
{
public:
    size_t size() const { return n; }

protected:
    size_t n;
};

class Derived3 : private Base_3 //!注意 private 继承
{
public:
    //* 保持对象尺寸相关的成员的访问级别
    using Base_3::size;

protected:
    using Base_3::n;
};
// * 上面使用 using 改变了这些成员的可访问性

// * ------ 默认的继承保护级别 ------
class Base_4
{
};
struct DD1 : Base //* 默认 public 继承
{
    //* 成员默认 public
};
class DD2 : Base //* 默认 private 继承
{
    //* 成员默认 private
};
// ! struct 和 class 的唯一区别：默认 成员访问说明符 和 派生访问说明符

int main()
{
}