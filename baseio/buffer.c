/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo体会缓冲区的位置 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("printf");
    fprintf(stdout , "fprintf");
    fwrite("fwrite", 6, 1, stdout);
    write(1, "write", 5);

    sleep(3);

    return 0;
}
