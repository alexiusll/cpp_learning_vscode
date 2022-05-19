/*
 * @Author: linkenzone
 * @Date: 2022-03-16 21:32:49
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
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}
    HasPtr &operator=(const HasPtr &rhs)
    {
        auto newp = new string(*rhs.ps);
        delete ps; // 释放旧内存
        ps = newp; // 从右侧运算对象拷贝数据到本对象
        i = rhs.i;
        return *this;
    }
    ~HasPtr() { delete ps; }
    void print()
    {
        cout << "i: " << i << endl;
        cout << "*ps: " << *ps << endl;
    }

private:
    string *ps;
    int i;
};

int main()
{
    string s = "233";
    string s2(s);
    string *s3 = new string("1111");

    HasPtr hp("hello");
    hp.print();
    hp = HasPtr("aabb");
    hp.print();

    return 0;
}