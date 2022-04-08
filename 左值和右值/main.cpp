/*
 * @Author: linkenzone
 * @Date: 2022-04-08 11:22:05
 * @Descripttion: Do not edit
 */

#include <iostream>
#include <cstring>

using namespace std;

int &GetValue()
{
    static int value = 10;
    return value;
}

void SetValue(int &value)
{
}

void _SetValue(const int &value)
{
}

//! 这样做主要和优化有关
void PrintName(const string &name)
{
    cout << "左值引用" << endl;
    cout << name << endl;
}

//* 这样做代表这个 name 是个临时的
void PrintName(string &&name)
{
    cout << "右值引用" << endl;
    cout << name << endl;
}

class myString
{
public:
    myString() = default;
    myString(const char *string)
    {
        cout << "普通构造函数..." << endl;
        m_size = strlen(string);
        m_data = new char[m_size];
        //* C 库函数 : 从存储区 str2 复制 n 个字节到存储区 str1。
        memcpy(m_data, string, m_size);
    }

    //* 拷贝构造函数
    myString(const myString &other)
    {
        cout << "拷贝构造函数..." << endl;
        m_size = other.m_size;
        m_data = new char[m_size];
        //* C 库函数 : 从存储区 str2 复制 n 个字节到存储区 str1。
        memcpy(m_data, other.m_data, m_size);
    }

    //* 移动构造函数
    // 不应该抛出异常
    myString(myString&& other) noexcept 
    {

    }

    ~myString()
    {
        cout << "析构函数..." << endl;
        delete m_data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_size; i++)
        {
            printf("%c", m_data[i]);
        }
        printf("\n");
    }

private:
    char *m_data;
    uint32_t m_size;
};

class Entity
{
public:
    Entity(const myString &name) : m_Name(name)
    {
    }

    void PrintName()
    {
        m_Name.Print();
    }

private:
    myString m_Name;
};

int main()
{
    GetValue() = 5;

    //! 左值 只能接受 左值 引用
    // SetValue(10);
    // int& a = 10;
    const int &a = 10; // * 这是一种特殊规则

    //* 实际做的事情
    // int temp = 10;
    // const int& a = temp;

    // * 这样是可以的
    _SetValue(10);

    //! const 修饰引用是什么意思？
    //*  常量引用表示不能通过引用改变绑定对象的值,但是对象的值可以通过别的方式改变。
    int _a = 10;
    const int &_b = a;
    cout << _a << endl; // 10
    cout << _b << endl; // 10
    //但是可以通过别的方式改变a
    _a = 20;
    cout << _a << endl; // 20
    cout << _b << endl; // 10

    //* ---- 其他的例子 ----
    string firstName = "Yan ";
    string lastName = "Chen";

    string fullName = firstName + lastName; // 右边的是右值

    PrintName(fullName);
    PrintName(firstName + lastName);

    //* ---- 移动转发的例子 ----
    //* 这里即调用了 普通构造函数 又调用了 拷贝构造函数
    Entity entity(myString("23333"));
    entity.PrintName();
}