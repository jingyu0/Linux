/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo体会匿名管道的基本使用 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int pid = 0; 
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret < 0) {
        perror("pipe error\n");
        return -1;
    }
    pid = fork();
    if (pid == 0) {
        //子进程从管道读取数据
        close(pipefd[0]);
        sleep(5);
        char buf[1024] = {0};
        int ret = read(pipefd[0], buf, 1023);
        if (ret < 0) {
            perror("read error\n");
            return -1;
        }
        printf("child get data:[%s]\n", buf);
    }else {
        close(pipefd[0]);
        sleep(3);
        //父进程向管道写入数据
        int pipe_size = 0;
        while(1) {
            char *ptr = "今天好冷啊~";
            int ret = write(pipefd[1], ptr, strlen(ptr));
            if (ret < 0) {
                perror("write error\n");
                return -1;
            }
            pipe_size += ret;
            printf("write data:%d\n", pipe_size);
        }
    }
    return 0;
}
