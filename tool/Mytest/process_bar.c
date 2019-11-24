#include <stdio.h>
#include <unistd.h>

int main()
{
    int i = 0;

    for (i = 0; i < 10; i++) {
        //针对标准输出，\n换行符不仅有换行的左右，还有刷新缓冲区的作用
        //\r是回车符：将光标移动到行首
        printf("-");
        //fflush 刷新文件缓冲区
        fflush(stdout);
        sleep(1);
    }
    return 0;
}
