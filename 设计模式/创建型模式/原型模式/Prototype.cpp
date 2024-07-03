/*
 * @Author: linkenzone
 * @Date: 2022-05-24 15:26:26
 * @Descripttion: 
 * 
 * 原型模式
 * https://refactoringguru.cn/design-patterns/prototype
 * 
 * 让你能够复制已有对象， 而又无需使代码依赖它们所属的类。
 * 原型模式提供一个 clone 接口来创建新的对象，避免了创建相同对象时要编写的重复代码
 * 
 */
#include <cassert>
#include <memory>

class Prototype
{
public:
    virtual std::unique_ptr<Prototype> Clone() = 0;
    virtual ~Prototype() = default;
};

class A : public Prototype
{
public:
    std::unique_ptr<Prototype> Clone() override
    {
        return std::make_unique<A>(*this);
    }
};

int main()
{
    std::unique_ptr<Prototype> p = std::make_unique<A>();
    std::unique_ptr<Prototype> q = p->Clone();
    assert(p != q);
}