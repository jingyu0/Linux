#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    extern char **environ;
    char *env[32] = {NULL};
    env[0] = "MYVAL=1000";
    env[1] = "TESTVAL=2000";
    env[2] = NULL;

    char *argv[32] = {NULL};
    argv[0] = "./env";
    argv[1] = "-l";
    argv[2] = "-a";
    argv[3] = NULL;
    //execl("/bin/ls", "ls", "-l", NULL);
    //execlp("./env", "ls", "-l", NULL);
    //execle("./env", "env", "-l", "-a", NULL, environ);
    execv("./env", argv);
    printf("hello bit~~\n");
    return 0;
}
