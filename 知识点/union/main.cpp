/*
 * @Author: linkenzone
 * @Date: 2022-03-15 16:09:48
 * @Descripttion: Do not edit
 */
#include <iostream>

using namespace std;

union myUnion
{
    char c;
    int a;
};

int main()
{
    myUnion m;
    m.a = 1;

    cout << "m.a:" << m.a << endl;
    cout << "m.c:" << m.c << endl;
}

