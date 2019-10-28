/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo体会认识系统调用IO接口的基本使用 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    int fd = -1;

    umask(0);
    fd = open("./test.txt", O_RDWR | O_CREAT | O_APPEND , 0777);
    if (fd < 0) {
        perror("open error");
        return -1;
    }

    //若想要将标准输出，重定向到fd所指向的文件
    dup2(fd, 1);
    printf("fd:%d\n", fd);
    fflush(stdout);

    char ptr[1024] = "下午时光总是如此漫长~~~\n";
    int ret = write(fd, ptr, strlen(ptr));
    if (ret < 0) {
        perror("write error");
        close(fd);
        return -1;
    }

    lseek(fd, 0, SEEK_SET);

    char buf[1024] = {0};
    ret = read(fd, buf, 1023);
    if (ret < 0) {
        perror("read error");
        close(fd);
        return -1;
    }else if (ret == 0) {
        perror("at end of file");
        close(fd);
        return -1;
    }
    printf("buf:[%s]-%d\n", buf, ret);
    close(fd);
    return 0;
}
