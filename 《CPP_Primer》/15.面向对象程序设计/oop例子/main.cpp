/*
 * @Author: linkenzone
 * @Date: 2022-03-21 10:43:34
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <string>

using namespace std;

class Quote;
class Bulk_quote;

double print_total(std::ostream &os, const Quote &item, size_t n);

// * 15.2 定义基类
class Quote /* final */ // ! 如果加了 final 则不能成为基类
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; };
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣和计算算法
    virtual double net_price(size_t n) const // * const 代表不可以修改class的成员
    {
        // price = 1000; //! 错误的！表达式必须是可修改的左值
        return n * price;
    };
    // * 基类通过都应该定义一个虚析构函数，即使该函数不执行任何实际操作也是如此
    virtual ~Quote() = default; //* 对析构函数进行动态绑定
    void debug() const; // 调试函数

    void test()
    {
        cout << "Quote" << endl;
    }
    // * 不论从基类派生出多少个派生类，对于每个静态成员来说都只存在唯一的实例
    static int test_static;

private:
    string bookNo; // 书籍的ISBN号
protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};

void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo= " <<this->bookNo << " "
              << "price= " <<this->price<< " ";
}

// * 15.2.2 定义派生类
class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    // * 由 Quote 的构造函数负责初始化 Bulk_quote 的基类部分
    Bulk_quote(const string &book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}
    // 覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(size_t) const override;
    // * override 显式地注明它使用某个成员函数覆盖了它继承的虚函数
    // * override 可以认为是一种标记，如果你没有覆盖已存在的虚函数，编译器报错
    // * 使用“override”声明的成员函数不能 重写 基类成员
    // * 如果使用 final, 之后任何尝试覆盖该函数的操作都将引发错误

    void test(int n)
    {
        cout << "Bulk_quote" << endl;
    }

private:
    size_t min_qty = 0;    // 适用折扣政策的最低购买量
    double discount = 0.0; // 以小数表示的折扣额
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main()
{
    Quote book_01("c++ 程序设计", 100);
    print_total(cout, book_01, 20);

    // * 练习题 15.6
    cout << "--- 练习题 15.6 ---" << endl;
    Quote q("textbook", 10);
    Bulk_quote bq("textbook", 10, 10, 0.3);
    print_total(cout, q, 10);
    print_total(cout, bq, 10);

    q.test();
    bq.test(1);

    // * 15.2.3
    // * 我们可以将基类的指针或引用绑定到派生类对象上
    // * 1.但是，不存在从基类向派生类的隐式类型转换
    Quote base;
    // Bulk_quote* bulkP = &base; //! 错误的！"Quote *" 类型的值不能用于初始化 "Bulk_quote *" 类型的实体
    // Bulk_quote& bulkRef = base; //! 错误的！无法用 "Quote" 类型的值初始化 "Bulk_quote &" 类型的引用(非常量限定)
    // ! 如果上述赋值是合法的，则我们可能会使用 bulkP 或 bulkRef 访问 base 中本不存在的成员

    Bulk_quote bulk;
    Quote *itemP = &bulk; //* 正确的，动态类型是 Bulk_quote
    Quote &itemP2 = bulk;
    // Bulk_quote *bulkP = itemP; //! 错误的！"Quote *" 类型的值不能用于初始化 "Bulk_quote *" 类型的实体
    // ! 编译器在编译时无法确定某个特定的转换在运行时是否安全

    // * 2. 在对象之间不存在类型转换
    // * 派生类向基类的自动类型转换只对指针或引用类型有效
    Bulk_quote bulk_02;  // 派生类对象
    Quote item(bulk_02); // 使用 Quote::Quote(const Quote&) 构造函数
    item = bulk_02;      // 调用 Quote::operator=(const Quote&)
    // ! 此时，bulk 的 Bulk_quote 部分被切掉了

    return 0;
}

#pragma region 辅助函数
double print_total(std::ostream &os, const Quote &item, size_t n)
{
    //* item 的静态类型是 Quote& , 而在此例中它的动态类型是 Bulk_quote
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
#pragma endregion