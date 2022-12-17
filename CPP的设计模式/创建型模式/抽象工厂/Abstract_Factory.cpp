/*
 * @Author: linkenzone
 * @Date: 2022-05-19 16:48:25
 * @Descripttion:
 *
 * 抽象工厂模式
 * 我们可以通过方法来识别该模式——其会返回一个工厂对象。 接下来， 工厂将被用于创建特定的子组件。
 */
#include <memory>

//* 抽象工厂
//* 抽象工厂能生成一系列相关的局部产品
class Door
{
public:
    virtual ~Door() = default;
};
class Window
{
public:
    virtual ~Window() = default;
};
class House
{
public:
    virtual void SetDoor(const Door &) {}
    virtual void SetWindow(const Window &) {}
    virtual ~House() = default;
};
class HouseFactory
{
public:
    virtual std::unique_ptr<Door> MakeDoor() { return std::make_unique<Door>(); }

    virtual std::unique_ptr<Window> MakeWindow()
    {
        return std::make_unique<Window>();
    }

    virtual std::unique_ptr<House> MakeHouse()
    {
        return std::make_unique<House>();
    }

    virtual ~HouseFactory() = default;
};

//* 具体工厂
//* 继承这个抽象工厂，即可对局部产品进行修改

class WoodDoor : public Door
{
};
class WoodWindow : public Window
{
};
class WoodHouse : public House
{
};
class WoodHouseFactory : public HouseFactory
{
public:
    std::unique_ptr<Door> MakeDoor() override
    {
        return std::make_unique<WoodDoor>();
    }

    std::unique_ptr<Window> MakeWindow() override
    {
        return std::make_unique<WoodWindow>();
    }

    std::unique_ptr<House> MakeHouse() override
    {
        return std::make_unique<WoodHouse>();
    }
};

//* 客户端代码
//* 用这个抽象工厂生成的局部产品即可组合成一个完整的产品
class Life
{
public:
    std::unique_ptr<House> CreateHouse(HouseFactory &factory)
    {
        std::unique_ptr<Door> door = factory.MakeDoor();
        std::unique_ptr<Window> window = factory.MakeWindow();
        std::unique_ptr<House> house = factory.MakeHouse();
        house->SetDoor(*door);
        house->SetWindow(*window);
        return house;
    }
};

int main()
{
    Life life;
    WoodHouseFactory factory;

    std::unique_ptr<House> house = life.CreateHouse(factory);
}