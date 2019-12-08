#include <stdio.h>
#include <string.h>

/*
 * 在linux系统中errno.h这个头文件中有两个全局变量
 * int errno;            用于保存每次系统调用的错误编号
 * char *sys_errlist[]   系统调用的错误原因描述
 *
 * perror(char *info)  打印上一次系统调用的错误原因在info之后
 * strerror(int errno) 根据给定的errno来获取错误描述信息
 */
int main()
{
    perror("nihao");
    for (int i = 0; i < 256; i++) {
        //printf("err:%d-%s\n",i, strerror(i));
    }
    return 256;
}
