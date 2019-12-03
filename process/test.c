#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int main()
{
    uint64_t a = 0;
    char buf[1024] = {0};
    scanf("%s", buf);
    while(1) {
        a++;
        sleep(1);
        //printf("%d\n",a++);
    }
    return 0;
}
