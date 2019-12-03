#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    while(1) {
        printf("-------\n");
        sleep(1);
    }
    return 0;
}
