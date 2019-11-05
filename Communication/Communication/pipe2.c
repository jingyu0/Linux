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
	int pipefd[2] = { 0 };
	int ret = pipe(pipefd);
	if (ret < 0){

		perror("pipe error");
		return -1;
	}
	int pid1 = fork();
	if (pid1 == 0){
		//进程1实现ps
		//管道不用那段手动关闭
		close(pipefd[0]);
		//将原本写到标准输出端的命令重定向到管道输入端
		dup2(pipefd[1], 1);
		execlp("ps", "ps", "-ef", NULL);
		exit(0);

	}
	int pid2 = fork();
	if (pid2 == 0){
		//进程2实现grep
		close(pipefd[1]);
		//将写到标准输入端的数据重定向到管道读取端
		dup2(pipefd[0], 0);
		//execlp:从PATH环境变量中查找文件并执行
		execlp("grep", "grep", "ssh", NULL);
		exit(0);

	}
	//代码运行后手动关闭父进程的读写端
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
