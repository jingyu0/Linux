#include <stdio.h>
#include <unistd.h>
#include <string.h>

int gval=100;

void func()
{
    char *ptr = NULL;
    memcpy(ptr, "hello", 5);
    printf("----\n");
}
int main()
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("-----%d\n", i);
    }
    if (1>2)
    {
        printf("1>2\n");
    }else
    {
        printf("2>1\n");
    }
    //func();
    while(1) {
        printf("-------------\n");
        sleep(1);
    }
    return 0;
}
