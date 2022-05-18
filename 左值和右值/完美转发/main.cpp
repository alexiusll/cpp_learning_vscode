/*
 * @Author: linkenzone
 * @Date: 2022-04-09 18:00:34
 * @Descripttion: Do not edit
 *
 * 聊聊C++中的完美转发
 * https://zhuanlan.zhihu.com/p/161039484
 * 
 * C++高阶知识：深入分析移动构造函数及其原理
 * http://avdancedu.com/a39d51f9/
 * 
 * 谈谈完美转发(Perfect Forwarding)：完美转发 = 引用折叠 + 万能引用 + std::forward
 * https://zhuanlan.zhihu.com/p/369203981
 * 
 * 万能引用，引用折叠，移动构造函数，emplace_back及其实现，完美转发及其实现
 * https://zhuanlan.zhihu.com/p/260508149
 */

/*
* std::forward被称为完美转发，它的作用是保持原来的值属性不变。
* 啥意思呢？通俗的讲就是，如果原来的值是左值，经std::forward处理后该值还是左值；如果原来的值是右值，经std::forward处理后它还是右值。
*/

#include <iostream>

template <typename T>
void print(T &t)
{
    std::cout << "左值" << std::endl;
}

template <typename T>
void print(T &&t)
{
    std::cout << "右值" << std::endl;
}

template <typename T>
void testForward(T &&v)
{
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}

int main(int argc, char *argv[])
{
    testForward(1);

    std::cout << "======================" << std::endl;

    int x = 1;
    testForward(x);
}