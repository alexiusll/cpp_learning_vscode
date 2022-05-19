/*
 * @Author: linkenzone
 * @Date: 2022-03-16 13:26:04
 * @Descripttion: Do not edit
 */

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // 动态分配 一个空数组是合法的
    cout << "-- 动态分配数组 --" << endl;
    size_t n = 3;
    int *p = new int[n]{1, 2, 3};
    for (int *q = p; q != p + n; ++q)
    {
        cout << *q << endl;
    }

    // 可以设置为 0
    // n = 0;
    // int *p2 = new int[n];
    // for (int *q = p2; q != p2 + n; ++q)
    // {
    //     cout << *q << endl;
    // }

    // delete p; // p必须指向一个动态分配的对象或为空

    // cout << p << endl;

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << p[i] << endl;
    // }

    delete[] p; // pa 必须指向一个动态分配的数组或为空

    // 此时就真的释放了
    for (size_t i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }

    // 指针
    cout << "-- 智能指针 --" << endl;
    unique_ptr<int[]> up(new int[3]);
    up.release(); // 自动用 delete[] 销毁其指针

    unique_ptr<int[]> up2(new int[3]);
    for (size_t i = 0; i < 3; i++)
    {
        up2[i] = i;
    }
    for (size_t i = 0; i < 3; i++)
    {
        cout << up2[i] << endl;
    }

    // 为了使用 shared_ptr，必须提供一个删除器
    shared_ptr<int> sp(new int[3], [](int *p)
                       { delete[] p; });
    // sp.reset(); // 使用 lambda 表达式来释放

    for (size_t i = 0; i < 3; i++)
    {
        *(sp.get() + i) = i;
    }
    for (size_t i = 0; i < 3; i++)
    {
        cout << *(sp.get() + i) << endl;
    }

    return 0;
}