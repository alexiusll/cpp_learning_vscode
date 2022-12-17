/*
 * @Author: linkenzone
 * @Date: 2022-10-08 17:19:41
 * @Descripttion: Do not edit
 */

#include <stdio.h>

void main()
{
    int a[5] = {10,20,30,40,50};
    int *p = a;
    p = &a[1];

    printf("%d", *++p);
}
