/*
 * @Author: linkenzone
 * @Date: 2022-09-19 10:29:24
 * @Descripttion: Do not edit
 */
#include <iostream>
using namespace std;

int main()
{
    char buffer[512]; // chunk of memory内存池
    int *p1, *p2, *p3, *p4;
    //常规new:
    p1 = new int[10];
    //定位new:
    p2 = new (buffer) int[10];
    for (int i = 0; i < 10; ++i)
        p1[i] = p2[i] = 20 - i;
    cout << "p1 = " << p1 << endl;                 //常规new指向的地址
    cout << "buffer = " << (void *)buffer << endl; //内存池地址
    cout << "p2 = " << p2 << endl;                 //定位new指向的地址
    cout << "p2[0] = " << p2[0] << endl;
    p3 = new (buffer) int[2];
    p3[0] = 1;
    p3[1] = 2;
    cout << "p3 = " << p3 << endl;
    cout << "p2[0] = " << p2[0] << endl;
    cout << "p2[1] = " << p2[1] << endl;
    cout << "p2[2] = " << p2[2] << endl;
    cout << "p2[3] = " << p2[3] << endl;
    return 0;
}