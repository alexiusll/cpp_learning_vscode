/*
 * @Author: linkenzone
 * @Date: 2022-05-24 16:36:52
 * @Descripttion: 
 * 
 * https://refactoringguru.cn/design-patterns/iterator
 * 让你能在不暴露集合底层表现形式 （列表、 栈和树等） 的情况下遍历集合中所有的元素。
 */

#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
class List;

template <typename T>
class Iterator
{
public:
    Iterator(List<T> &list) : list_(list) {}

    void operator++() { ++index_; }

    bool IsDone() { return index_ >= list_.Size(); }

    T &operator*() { return list_[index_]; }

private:
    List<T> &list_;
    std::size_t index_ = 0;
};

template <typename T>
class List
{
public:
    Iterator<T> Begin() { return Iterator<T>{*this}; }

    void Append(T &&x) { data_.emplace_back(std::forward<T>(x)); }

    std::size_t Size() { return std::size(data_); }

    T &operator[](std::size_t n) { return data_.at(n); }

private:
    std::vector<T> data_;
};

int main()
{
    List<std::int32_t> list;
    list.Append(2);
    list.Append(3);
    list.Append(1);

    for (auto it = list.Begin(); !it.IsDone(); ++it)
    {
        std::cout << *it; // 231
    }
}