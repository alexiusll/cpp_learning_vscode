/*
 * @Author: linkenzone
 * @Date: 2022-03-21 12:15:39
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <string>

using namespace std;
class Quote;

// * 15.2 定义基类
class Quote /* final */ // ! 如果加了 final 则不能成为基类
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; };
    virtual double net_price(size_t n) const // * const 代表不可以修改class的成员
    {
        return n * price;
    };
    virtual ~Quote() = default; //* 对析构函数进行动态绑定
    void debug() const
    {
        std::cout << "data members of this class:\n"
                  << "bookNo= " << this->bookNo << " "
                  << "price= " << this->price << " ";
    }

private:
    string bookNo; // 书籍的ISBN号

protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};

// * 15.4 纯虚函数
// * 用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote : public Quote // * 含有纯虚函数的类 是 抽象基类
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0; // 纯虚函数
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
    double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main()
{
    // Disc_quote discounted; // ! 错误的，不允许使用抽象类类型 "Disc_quote" 的对象:

    Bulk_quote bq("233", 100, 10, 0.3);
    cout << bq.net_price(20) << endl;
}