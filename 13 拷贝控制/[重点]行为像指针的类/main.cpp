/*
 * @Author: linkenzone
 * @Date: 2022-03-16 21:49:05
 * @Descripttion: 
 * 
 * shared_ptr 的实现
 * 
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

int main()
{

    HasPtr hp("hello");
    HasPtr hp2 = HasPtr(hp);
    HasPtr hp3 = HasPtr(hp2);

    hp.print();
    hp2.print();

    HasPtr sp("hello2");
    sp = HasPtr("lol");
    sp.print();

    return 0;
}