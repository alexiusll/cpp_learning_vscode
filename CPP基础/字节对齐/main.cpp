/*
 * @Author: linkenzone
 * @Date: 2022-09-19 10:20:00
 * @Descripttion: Do not edit
 */

#include <cstring>
#include <stdio.h>
#include <iostream>

typedef struct student
{
    char a;           // 默认4个字节对齐，char           是1个字节，以4字节对齐，按4个字节处理
    short b;          // 默认4个字节对齐，short          是2个字节，以4字节对齐，按4个字节处理
    int c;            // 默认4个字节对齐，int            是4个字节，以4字节对齐，按4个字节处理
    float d;          // 默认4个字节对齐，float          是4个字节，以4字节对齐，按4个字节处理
    double e;         // 默认4个字节对齐，double         是8个字节，以4字节对齐，按8个字节处理
    long f;           // 默认4个字节对齐，long           是4个字节，以4字节对齐，按4个字节处理
    unsigned char g;  // 默认4个字节对齐，unsigned char  是1个字节，以4字节对齐，按4个字节处理
    unsigned short h; // 默认4个字节对齐，unsigned short 是2个字节，以4字节对齐，按4个字节处理
    unsigned int i;   // 默认4个字节对齐，unsigned int   是4个字节，以4字节对齐，按4个字节处理
} student;

#pragma pack(4) /*1字节对齐*/
struct a
{
    int a; // 8
    char c;   // 1
    char d;   // 1
} test;
#pragma pack() /*还原默认对齐*/

struct tagABC
{
    char name[10];  // 12
    char se;        // 4
    long sno;       // 4
    float score[4]; // 4*4 = 12
} *pAbc;

#pragma pack(4) /*1字节对齐*/
typedef struct tagAAA
{
    unsigned char ucId : 1;
    unsigned char ucPara0 : 2;
    unsigned char ucState : 6;
    unsigned char ucTail : 4;
    unsigned char ucAvail; // 1字节
    unsigned char unTail2 : 4;
    unsigned long ulData; // 4字节
} AAA_S;
#pragma pack() /*还原默认对齐*/

struct A
{
    int i; // 4
    char c1; // 1
    char c2; // 1
};

struct B
{
    char c1; // 1
    int i; // 4
    char c2; // 1
};

int main()
{
    std::cout << sizeof(A) <<std::endl; // 有效对齐值为4, output : 8
    std::cout << sizeof(B) << std::endl; // 有效对齐值为4, output : 12

    printf("%d \n", sizeof(student));
    printf("%d \n", sizeof(test));

    pAbc = NULL;
    pAbc += 2;
    printf("%d \n", sizeof(*pAbc));
    printf("%d \n", pAbc);

    printf("%d \n", sizeof(tagAAA));

    //* 下面的内容是某些试题中的内容

    int *p1, *p2;
    int value;
    p1 = (int *)0x400;
    p2 = (int *)0x408;
    value = p2 - p1;
    printf("%d \n", value);

    char acNew[20] = "\\0\0";
    printf("%d \n", strlen(acNew));
    printf("%s \n", acNew);

    int y = 3, x = 3, z = 1;
    printf("%d%d\n", (++x, y++), z + 2);

    int a = 1, b = 2, c = 3, d = 4, m = 2, n = 2;
    (m = a > b) && (n = c > d);
    printf("%d \n", n);

    return 0;
}