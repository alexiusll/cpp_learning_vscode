/*
 * @Author: linkenzone
 * @Date: 2022-03-16 22:11:12
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
    // 构造函数分配新的 string 和新的计数器，将计数器置为1
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i), use(p.use) { ++*use; }
    HasPtr &operator=(const HasPtr &rhs)
    {
        // 增加右侧对象的引用计数
        ++*rhs.use;
        if (--*use == 0)
        {
            cout << "赋值:引用计数变为: " << *use << endl;
            cout << "释放对象..." << endl;
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;

        return *this;
    }
    ~HasPtr()
    {
        if (--*use == 0)
        {
            cout << "析构函数:引用计数变为: " << *use << endl;
            cout << "释放对象..." << endl;
            delete ps;
            delete use;
        }
        else
        {
            cout << "析构函数:引用计数变为: " << *use << endl;
        }
    }
    friend void swap(HasPtr &, HasPtr &);
    void print()
    {
        cout << "i: " << i << endl;
        cout << "*ps: " << *ps << endl;
        cout << "*use: " << *use << endl;
    }

private:
    string *ps;
    int i;
    size_t *use; // 用来记录有多少个对象共享 *ps 成员
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // 交换指针，而不是string数据
    swap(lhs.i, rhs.i);   // 交换int成员
}

int main()
{
    HasPtr hp1("hello");
    HasPtr hp2("kizuna ai");

    swap(hp1, hp2);

    hp1.print();
    hp2.print();

    return 0;
}