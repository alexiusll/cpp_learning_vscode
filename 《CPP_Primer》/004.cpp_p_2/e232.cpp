/*
 * @Author: linkenzone
 * @Date: 2021-11-12 10:54:23
 * @Descripttion: Do not edit
 */
#include <iostream>
using namespace std;

int main()
{
    int *null = 0;
    int *p = null;

    // 溢出测试
    unsigned short level = 1;
    level -= 2;
    cout << level << endl;

    return 0;
}