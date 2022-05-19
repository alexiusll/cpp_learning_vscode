/*
 * @Author: linkenzone
 * @Date: 2022-03-16 14:03:58
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    size_t n = 3;

    // string *const p = new string[n]; // 构造 n 个空 string
    // string s;
    // string *q = p;
    // while (cin >> s && q!=p+n)
    //     *q++ = s;

    // const size_t size = q - p;

    // // 使用数组
    // cout << p[0] << endl;

    // delete[] p;

    cout << "-- allocator --" << endl;

    allocator<string> alloc; // 可以分配 string 的 allocator 对象
    auto const p = alloc.allocate(n); // 分配 n 个未初始化的 string

    auto q = p; // q 指向最后构造的元素之后的位置
    alloc.construct(q++); // *q 未空字符串
    alloc.construct(q++, 10,'c'); // *q 为 cccccccccc
    alloc.construct(q++ , "h1"); // *q 未空字符串

    for (size_t i = 0; i < n ; i++)
    {
        cout << p[i] << endl;
    }

    return 0;
}