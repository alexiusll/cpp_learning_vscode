/*
 * @Author: linkenzone
 * @Date: 2022-03-31 14:30:11
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    A()
    {
        test();
    }

    virtual void test()
    {
        cout << "test A" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        test();
    }

    virtual void test()
    {
        cout << "test B" << endl;
    }
};

int main()
{
    B b;
}