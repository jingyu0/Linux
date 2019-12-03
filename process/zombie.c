#include <stdio.h>
#include <unistd.h>

int val = 100;
int main()
{
    //getpid 这个接口用于获取当前调用进程的pid
    pid_t pid = getpid();
    //fork  -  创建一个子进程
    pid_t child_pid = fork();
    if (child_pid == 0) {
        //只有子进程运行这个判断
        val = 10;
        printf("this is child:%d---%d-%p\n", getpid(), val, &val);
    }else if (child_pid > 0) {
        //只有父进程运行这个判断
        sleep(1);
        printf("this is parent:%d---%d-%p\n", getpid(), val, &val);
    }
    while(1) {
        printf("--------%d---ppid:%d\n", getpid(), pid);
        sleep(1);
    }
    return 0;
}
