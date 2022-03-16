/*
 * @Author: linkenzone
 * @Date: 2022-03-16 15:23:51
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;

    return 0;
}

template <typename T>
T foo(T *p)
{
    T tmp = *p; // tmp 的类型将是指针 p 指向的类型
    // ...
    return tmp;
}

template <unsigned N, unsigned M>
int compare_str(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

int main()
{
    cout << compare(1, 0) << endl;
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl;

    cout << compare_str("hi", "mom") << endl;

    return 0;
}