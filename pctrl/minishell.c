#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{
    while(1) {
        printf("[username@localhost ]$ ");
        fflush(stdout);//手动刷新缓冲区
        char buf[1024] = {0};
        fgets(buf, 1024, stdin);//从标准输入读取数据
        //将最后的换行符修改为字符串结尾标志
        buf[strlen(buf) - 1] = '\0';
        printf("cmd:[%s]\n", buf);


        //[   ls     -a    -l    ]
        char *ptr = buf;
        char *argv[32] = {NULL};
        int argc = 0;
        while(*ptr != '\0') {
            if (!isspace(*ptr)) {
                //每一个非空白字符处，都是参数的起始位置
                argv[argc++] = ptr;
                while(*ptr != '\0' && !isspace(*ptr)) ptr++;
                *ptr = '\0';
            }
            ptr++;
        }
        argv[argc] = NULL;//最后一个参数以NULL结尾
        for (int i = 0; i < argc; i++) {
            printf("argv[%d]=[%s]\n", i, argv[i]);
        }

        //不是直接对shell进行程序替换，因为替换后就没有shell
        pid_t pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv);//子进程进行程序替换
            exit(0);
        }
        waitpid(pid, NULL, 0);//阻塞等待子进程命令执行完毕
    }
    return 0;
}
