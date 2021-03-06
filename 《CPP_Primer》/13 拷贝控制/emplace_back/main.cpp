/*
 * @Author: linkenzone
 * @Date: 2022-03-20 18:23:54
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <vector>
using namespace std;
class testDemo
{
public:
    testDemo(int num) : num(num)
    {
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo &other) : num(other.num)
    {
        std::cout << "调用拷贝构造函数" << endl;
    }
    // testDemo(testDemo&& other) :num(other.num) {
    //     std::cout << "调用移动构造函数" << endl;
    // }
private:
    int num;
};

int main()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(move(2));

    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
}