/*
 * @Author: linkenzone
 * @Date: 2022-03-16 20:57:20
 * @Descripttion: Do not edit
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    // HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    // HasPtr &operator=(const HasPtr &hp)
    // {
    //     std::string *new_ps = new std::string(*hp.ps);
    //     delete ps;
    //     ps = new_ps;
    //     i = hp.i;
    //     return *this;
    // }
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;

    return ret; // ret 和 hp 被销毁
}

class numbered
{
public:
    numbered()
    {
        mysn = unique++;
    }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f (const numbered &s) { cout << s.mysn << endl; }

int main()
{
    // HasPtr p("2333");
    // f(p);
    // HasPtr q(p);

    numbered a, b = a, c = b;
    // cout << "a: " << a.mysn << endl;
    // cout << "b: " << b.mysn << endl;
    // cout << "c: " << c.mysn << endl;
    f(a), f(b), f(c);

    return 0;
}