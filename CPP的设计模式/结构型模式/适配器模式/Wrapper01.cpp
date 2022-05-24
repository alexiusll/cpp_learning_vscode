/*
 * @Author: linkenzone
 * @Date: 2022-05-24 15:42:41
 * @Descripttion: 
 * 
 * 适配器模式
 * https://refactoringguru.cn/design-patterns/adapter
 * 
 * 适配器提供了源接口到目标接口的转换
 * 
 */

//* 适配器模式在 C++ 代码中很常见。 基于一些遗留代码的系统常常会使用该模式。 在这种情况下， 适配器让遗留代码与现代的类得以相互合作。
//* 适配器可以通过以不同抽象或接口类型实例为参数的构造函数来识别。 
//* 当适配器的任何方法被调用时， 它会将参数转换为合适的格式， 然后将调用定向到其封装对象中的一个或多个方法。

#include <memory>
#include <iostream>

class Target
{ // 提供给用户的类
public:
    virtual void Print() = 0;
    virtual ~Target() = default;
};

class Adaptee
{ // 提供实际功能的类
public:
    virtual void PrintImpl() { std::cout << 1; }
    virtual ~Adaptee() = default;
};

class Adapter : public Target, public Adaptee
{ // 适配器
public:
    void Print() override { Adaptee::PrintImpl(); }
};

int main()
{
    std::unique_ptr<Target> target = std::make_unique<Adapter>();
    target->Print(); // 1
}