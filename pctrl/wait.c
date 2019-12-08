#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0) {
        sleep(5);
        exit(99);
    }
    //wait(NULL);//pid_t wait(int *status);
    //waitpid第三个参数0为默认阻塞等待, WNOHANG则非阻塞
    //waitpid返回值为0则表示当前没有子进程退出，-1则出错
    int status;
    while(waitpid(pid, &status, WNOHANG) == 0) {
        printf("还没放学，打一桌麻将~\n");
        sleep(1);
    }
    if (!(status & 0x7f)) {
        printf("child exit code:%d\n", (status>>8)&0xff);
    }
    if (WIFEXITED(status)) {
        printf("child exit code:%d\n", WEXITSTATUS(status));
    }
    while(1) {
        printf("打一桌麻将~\n");
        sleep(1);
    }
    return 0;
}
