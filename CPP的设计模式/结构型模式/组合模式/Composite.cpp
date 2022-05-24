/*
 * @Author: linkenzone
 * @Date: 2022-05-24 16:28:54
 * @Descripttion: 
 * 
 * 组合模式
 * https://refactoringguru.cn/design-patterns/composite
 * 你可以使用它将对象组合成树状结构， 并且能像使用独立对象一样使用它们。
 * 
 */
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

//* 组合模式为组合对象提供了与单体对象一致的处理方式，从而使得用户可以忽略两者的差异并以统一方式使用

class Shape
{
public:
    virtual void Display() = 0;
    virtual void Append(const std::shared_ptr<Shape> &) {}
    virtual void Remove(const std::shared_ptr<Shape> &) {}

    virtual std::shared_ptr<Shape> Child(std::size_t) { return nullptr; }

    virtual ~Shape() = default;
};

class Line : public Shape
{
public:
    void Display() override { std::cout << 1; }
};

class Rect : public Shape
{
public:
    void Display() override { std::cout << 2; }
};

class Picture : public Shape
{
public:
    void Display() override
    {
        for (auto &&x : shapes_)
        {
            x->Display();
        }
    }

    void Append(const std::shared_ptr<Shape> &s) override
    {
        shapes_.emplace_back(s);
    }

    void Remove(const std::shared_ptr<Shape> &s) override
    {
        if (const auto it = std::find(std::begin(shapes_), std::end(shapes_), s);
            it != std::end(shapes_))
        {
            shapes_.erase(it);
        }
    }

    std::shared_ptr<Shape> Child(std::size_t n) override { return shapes_.at(n); }

private:
    std::vector<std::shared_ptr<Shape>> shapes_;
};

int main()
{
    std::unique_ptr<Shape> picture = std::make_unique<Picture>();
    const auto line = std::make_shared<Line>();
    const auto rect = std::make_shared<Rect>();

    picture->Append(line);
    picture->Append(rect);
    picture->Display(); // 12

    picture->Remove(line);
    picture->Display(); // 2
}