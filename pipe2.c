    /**********************************************************
   * Author        : Jingyu Sun
    * Email         : sun1705990821@163.com
    * Create time   : 2019-10-31 22:34
    * Last modified : 2019-10-31 22:34
    * Filename      : pipe2.c
    * Description   : 通过匿名管道实现管道符
    * ps -ef | grep ssh
    * ps 进程和grep 进程是兄弟进程，
   * ps进程将结果交给grep进程使用进程间通信-匿名管道 
   * *******************************************************/
  
  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/wait.h>
 
  int main()
  {
          int pipefd[2] ={0};
          int ret = pipe(pipefd);
          if(ret<0){
                  perror("pipe error");
                  return -1;
          }
          int pid1=fork();
         if(pid1==0){
             //进程1实现ps
              execlp("ps","ps","-ef",NULL);
              exit(0);
          }
          int pid2=fork();
          if(pid2==0){
              //进程2实现grep
              execlp("grep","grep","ssh",NULL);
              exit(0);
          }
          waitpid(pid1,NULL,0);
          waitpid(pid2,NULL,0);
          return 0;
  }
