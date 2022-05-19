/*
 * @Author: linkenzone
 * @Date: 2022-03-21 15:30:00
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <string>

class Base
{
public:
    void pub_mem(); // public member
protected:
    int prot_mem; // protected member
private:
    char priv_mem; // private member
};

struct Pub_Derv : public Base
{
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
    void memfcn(Base &b)
    {
        b = *this;
        // priv_mem = 'c';
        prot_mem = 1;
    }
};
struct Prot_Derv : protected Base
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv
{
    // void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Base *p = &d1;

    Priv_Derv d2;
    // p = &d2;

    Prot_Derv d3;
    // p = &d3;

    Derived_from_Public dd1;
    p = &dd1;

    Derived_from_Private dd2;
    // p =& dd2;

    Derived_from_Protected dd3;
    // p = &dd3;

    return 0;
}