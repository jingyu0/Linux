#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("./test.txt", "a+");
    if (fp == NULL) {
        perror("fopen error");
        return -1;
    }
    char *ptr = "天要黑了~~\n";
    //fwrite返回的是块个数，当块大小为1的时候返回的是写入文件
    //的字节长度
    size_t wlen = fwrite(ptr, 1, strlen(ptr), fp);
    if (wlen == 0) {
        printf("end of file or error\n");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);//跳转到文件起始位置

    char buf[1024] = {0};
    size_t rlen = fread(buf, 1024, 1, fp);
    if (rlen == 0) {
        perror("fread");
        printf("end of file or error\n");
        printf("buf:[%s]-%d\n", buf, rlen);
        return -1;
    }
    return 0;
}
