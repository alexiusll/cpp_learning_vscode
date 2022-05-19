/*
 * @Author: linkenzone
 * @Date: 2022-03-20 22:35:10
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <vector>

// Test reference to http://coolshell.cn/articles/10478.html

#include <string.h>
#include <utility>

class String
{
public:
    String()
        : data_(new char[1])
    {
        *data_ = '\0';
    }

    String(const char *str)
        : data_(new char[strlen(str) + 1])
    {
        std::cout << "执行拷贝构造函数 char" << std::endl;
        strcpy(data_, str);
    }

    String(const String &rhs)
        : data_(new char[rhs.size() + 1])
    {
        std::cout << "执行拷贝构造函数 String" << std::endl;
        strcpy(data_, rhs.c_str());
    }
    /* Delegate constructor in C++11
    String(const String& rhs)
      : String(rhs.data_)
    {
    }
    */

    ~String()
    {
        delete[] data_;
    }

    /* Traditional:
    String& operator=(const String& rhs)
    {
      String tmp(rhs);
      swap(tmp);
      return *this;
    }
    */
    String &operator=(String rhs) // yes, pass-by-value
    {
        std::cout << "执行赋值运算符 String" << std::endl;
        swap(rhs);
        return *this;
    }

    // C++ 11
    String(String &&rhs)
        : data_(rhs.data_)
    {
        std::cout << "执行移动构造函数 String" << std::endl;
        rhs.data_ = nullptr;
    }

    String &operator=(String &&rhs)
    {
        std::cout << "执行移动赋值运算符 String" << std::endl;
        swap(rhs);
        return *this;
    }

    // Accessors

    size_t size() const
    {
        return strlen(data_);
    }

    const char *c_str() const
    {
        return data_;
    }

    void swap(String &rhs)
    {
        std::swap(data_, rhs.data_);
    }

private:
    char *data_;
};

void foo(String x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String &x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1;

    std::cout << "--- foo ---" << std::endl;
    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();

    std::cout << "--- svec ---" << std::endl;
    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    // auto temp_str = baz();
    // svec.push_back(temp_str);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec)
    {
        std::cout << s.c_str() << std::endl;
    }

    std::cout << "--- my ---" << std::endl;
    String str_01("kizuna ai");
    String str_02(std::move(str_01));
    // std::cout << "str_01: " << str_01.c_str() << std::endl; //! 出现错误
    std::cout << "str_02: " << str_02.c_str() << std::endl;
}