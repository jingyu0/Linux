/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo演示命名管道的基本操作 
*   int mkfifo(const char *pathname, mode_t mode);
*   pathname: 管道文件路径名称
*   mode：管道文件的操作权限
*   成功返回0，失败返回-1；
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    char *file = "./test.fifo";
    int ret = mkfifo(file, 0664);
    if (ret < 0) {
        if (errno != EEXIST) {
            perror("mkfifo error");
            return -1;
        }
    }
    int fd = open(file, O_WRONLY);
    if (fd < 0 ) {
        perror("open error");
        return -1;
    }
    printf("open success\n");
    while(1) {
        char buf[1024] = {0};
        scanf("%s", buf);
        int ret = write(fd, buf, strlen(buf));
        if (ret == 0) {
            printf("管道没人读了~~所有写端被关闭\n");
            return 0;
        }else if (ret < 0) {
            perror("write error");
            return -1;
        }
    }
    return 0;
}
