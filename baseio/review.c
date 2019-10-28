/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo用于回顾体会标准库IO接口的使用 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("./tmp.txt", "r+");
    if (fp == NULL) {
        perror("fopen error");
        return -1;
    }
    //fseek(fp, 10, SEEK_END);

    char *ptr = "处处好风光~~\n";
    int ret = fwrite(ptr, 1, strlen(ptr), fp);
    if (ret != strlen(ptr)) {
        printf("数据并没有完全写入\n");
        fclose(fp);
        return -1;
    }

    fseek(fp, 0, SEEK_SET);

    char buf[1024] = {0};
    ret = fread(buf, 1, 1023, fp);
    if (!feof(fp)) {
        printf("已经读取到文件末尾\n");
        fclose(fp);
        return -1;
    }
    printf("buf:[%s]-%d\n", buf, ret);

    fclose(fp);
    return 0;
}
