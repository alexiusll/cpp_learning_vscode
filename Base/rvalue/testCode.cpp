/*
 * @Author: linkenzone
 * @Date: 2024-07-03 14:11:41
 * @Descripttion: Do not edit
 */

// #include <iostream>

#include <stdio.h>
int main(int argc, char *argv[])
{
    int num = 10;
    
    // 左值引用
    int &num1 = num;

    printf("num : %d", num);
}