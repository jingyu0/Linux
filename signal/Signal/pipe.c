////创建一个demo体会匿名管道的基本使用
//#include<unistd.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	int pid = 0;
//	int pipefd[2];
//	int ret = pipe(pipefd);
//	if (ret < 0){
//		//出错
//		perror("pipe error\n");
//		return -1;
//	}
//	pid = fork();
//	if (pid == 0){
//		//子进程从管道读取数据【0】
//		char buf[1024] = { 0 };
//		int ret = read(pipefd[0], buf, 1023);
//		//read三个参数：文件描述符；写入数据；写入长度
//		if (ret < 0)
//		{   //读取出错
//			perror("read error\n");
//			return -1;
//		}
//		printf("child get data:[%s]\n", buf);
//	}
//	else{
//		//父进程向管道写入数据【1】
//		char *ptr = "今天真的好冷啊~";
//		int ret = write(pipefd[1], ptr, strlen(ptr));
//		if (ret < 0){
//			perror("write error\n");
//			return -1;
//		}
//	}
//	return 0;
//}
