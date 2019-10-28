/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：实现一个简单的迷你shell
*       1. 获取标准输入
*       2. 对数据进行解析-得到要运行的所有命令参数信息
*           [   ls   -l  ]   ->  [ls] [-l]
*       3. 创建子进程，进行程序替换，让子进程运行ls
*       4. 父进程进行进程等待
===============================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main()
{
    while(1) {
        printf("[san@localhost]# ");
        fflush(stdout);
        char buf[1024] = {0};
        fgets(buf, 1023, stdin);//从标准输入获取用户敲击的命令
        buf[strlen(buf) - 1] = '\0';
        printf("cmd:[%s]\n", buf);

        //ls >> a.txt  
        int redirect_flag = 0;
        char *ptr = buf;
        char *file = NULL;
        while(*ptr != '\0') {
            if (*ptr == '>') {
                redirect_flag++;
                *ptr = '\0';
                ptr++;
                if (*ptr == '>') {
                    redirect_flag++;
                    ptr++;
                }
                while(*ptr == ' ' && *ptr != '\0') {
                    ptr++;
                }
                file = ptr;
                while(!isspace(*ptr) && *ptr != '\0') {
                    ptr++;
                }
                *ptr = '\0';
            }
            ptr++;
        }

        //命令解析
        int argc = 0;
        char *argv[32] = {NULL};
        ptr = buf;
        while(*ptr != '\0') {
            if (!isspace(*ptr)) {
                argv[argc] = ptr;
                argc++;
                while(!isspace(*ptr) && *ptr != '\0') {
                    ptr++;
                }
                *ptr = '\0';
            }
            ptr++;
        }
        argv[argc] = NULL;
        int i;
        for (i = 0; i < argc; i++) {
            printf("[%s]\n", argv[i]);
        }


        int pid = fork();
        if (pid == 0) {
            if (redirect_flag == 1) {
                int fd = open(file, O_RDWR|O_CREAT|O_TRUNC, 0664);
                dup2(fd, 1);
            }else if (redirect_flag == 2){
                int fd = open(file, O_RDWR|O_CREAT|O_APPEND, 0664);
                dup2(fd, 1);
            }
            execvp(argv[0], argv);
            exit(0);
        }
        waitpid(-1, NULL, 0);
    }
    return 0;
}
