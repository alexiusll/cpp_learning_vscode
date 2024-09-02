/*
 * @Author: linkenzone
 * @Date: 2022-09-28 11:13:34
 * @Descripttion: Do not edit
 */


#include <pthread.h>
#include <stdio.h>

void *mythread(void *arg)
{
    printf("%s: begin\n", (char *)arg);
    int i;
    for (i = 0; i < 1e7; i++)
    {
        counter = counter + 1;
    }
    printf("%s: done\n", (char *)arg);
    return NULL;
}