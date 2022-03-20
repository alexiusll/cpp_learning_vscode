/*
 * @Author: linkenzone
 * @Date: 2022-03-20 15:03:05
 * @Descripttion:
 *
 * vector 类的一个简化版本
 */

#include <iostream>
#include <string>

#include <memory>

#include <vector>

using namespace std;

class StrVec
{
public:
    StrVec() : // allocator 成员进行默认初始化
               elements(nullptr), first_free(nullptr), cap(nullptr)
    {
        cout << "--- 成员进行默认初始化... ---" << endl;
    }
    StrVec(initializer_list<string>);  // 列表初始化
    StrVec(const StrVec &);            // 拷贝构造函数
    StrVec &operator=(const StrVec &); // 拷贝赋值运算符
    ~StrVec();                         // 析构函数
    void push_back(const string &);    // 拷贝元素
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

    //* 自己来实现的函数
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string &);

    // 调试用
    void print()
    {
        cout << "--- print ---" << endl;
        cout << "size: " << size() << endl;
        cout << "capacity: " << capacity() << endl;
        for (string *it = begin(); it < end(); it++)
            cout << *it << " + ";
        cout << endl;
    }

private:
    static allocator<string> alloc; // 分配元素
    // 被添加元素的函数所使用
    void chk_n_alloc()
    {
        if (size() == capacity())
        {
            cout << "空间不够了，分配新的空间..." << endl;
            reallocate();
        }
    }
    // 工具函数，被拷贝构造函数，赋值运算符和析构函数所使用
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();       // 销毁元素并释放内存
    void reallocate(); // 获得更多内存并拷贝已有元素
    //* 补充函数
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string *, const string *);

    string *elements;   // 指向数组首元素的指针
    string *first_free; // 指向数组第一个空闲元素的指针
    string *cap;        // 指向数组尾后位置的指针
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc(); // 确保有空间容纳新元素
    // 在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // 分配空间保存给范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个 pair, 该 pair 由 data 和 uninitialized_copy 的返回值构成
    // 从迭代器 b 和 e 给定的输入范围中拷贝元素到迭代器 data 指定的未构造的原始内存中。
    // data 指向的内存必须足够大，能够容纳输入序列中元素的拷贝。
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // 不能传递给 deallocate 一个空指针，如果 elements 位 0，函数什么也不做
    if (elements)
    {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements; /* 空 */)
        {
            alloc.destroy(--p); // 此算法对p指向的对象执行析构函数。
        }
        //* 另外一种写法
        //* for_each(elements, first_free, [this](std::string &rhs){ alloc.destroy(&rhs); });
        alloc.deallocate(elements, cap - elements); // 释放从T* 指针 elements 中地址开始的内存，这块内存保存了 cap - elements 个类型为T的对象
    }
}

StrVec::StrVec(const StrVec &s)
{
    cout << "--- 调用拷贝构造函数 --- " << endl;
    // 调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    cout << "--- 调用拷贝赋值运算符 ---" << endl;
    // 调用 alloc_n_copy 分配内存，大小与 rhs 中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); // 这里需要销毁这个对象中 原本存储的 string
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    cout << "--- reallocate ---" << endl;
    // 我们将分配当前大小两倍的内存空间
    auto newCapacity = size() ? 2 * size() : 1;

    // cout << "newCapacity: " << newCapacity << endl;
    // cout << "size() : " << size() << endl;

    // // 分配新内存
    // auto newdata = alloc.allocate(newCapacity);

    // // 将数据从旧内存移动到新内存
    // auto dest = newdata;  // 指向新数组中下一个空闲位置
    // auto elem = elements; // 指向旧数组中下一个元素

    // for (size_t i = 0; i != size(); ++i)
    // {
    //     alloc.construct(dest++, move(*elem++)); // 移动构造函数
    // }
    // free(); // 一旦我们移动完元素就释放旧内存空间

    // // 更新我们的数据结构，执行新元素
    // elements = newdata;
    // first_free = dest;
    // cap = elements + newCapacity;

    alloc_n_move(newCapacity);
}

//* 自己实现的
void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity())
        return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, string());
}

void StrVec::resize(size_t count, const string &s)
{
    if (count > size())
    {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if (count < size())
    {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

// * 列表初始化

void StrVec::range_initialize(const std::string *first, const std::string *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il)
{
    range_initialize(il.begin(), il.end());
}

int main()
{
    StrVec str;
    str.push_back("kizuna ai");
    str.push_back("hello");
    str.push_back(" world 2022!");
    // str.push_back(" 2022!");
    str.print();

    StrVec str2 = str;
    str2.print();

    StrVec str3;
    str3 = str2;
    str3.print();

    str3.reserve(100);
    str3.print();

    str3.resize(2);
    str3.print();

    str2.resize(10, "233");
    str2.print();

    str2.resize(2, "233");
    str2.print();

    StrVec str4 = {"kizuna", "ai", "vtb"}; // initializer_list 对象只能用大括号{}初始化
    str4.print();

    StrVec str5({"kizuna", "ai", "vtb", "!!!"}); // 2 种 写法都可以
    str5.print();

    vector<int> vec;

    return 0;
}