#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("今天的天气好晴朗~~");
    sleep(3);
    _exit(99);
    /*
    pid_t pid = vfork();//创建子进程
    if (pid == 0) { ///打印一句话，5秒中之后向后继续运行
        printf("this is child\n");
        sleep(5);
        exit(99);//退出一个进程，谁调用，谁退出
    }else if (pid > 0) {
        //while(1) {//父进程直接进入死循环
            printf("this is parent\n");
        //}
    }
    */
    return 0;
}
