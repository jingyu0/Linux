#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[])
{
    int i;
    //打印所有的程序运行参数
    for (i = 0; i < argc; i++) {
        printf("argv[%d]=[%s]\n", i, argv[i]);
    }
    /*
    extern char **environ;
    for (i = 0; environ[i] != NULL; i++) {
        printf("env[%d]=[%s]\n", i, environ[i]);
    }
    */
    char *val = getenv("MYVAL");
    if (val == NULL) {
        printf("There is no such environment variable\n");
        return -1;
    }
    printf("MYVAL:[%s]\n", val);
    return 0;
}
