////����һ��demo��������ܵ��Ļ���ʹ��
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
//		//����
//		perror("pipe error\n");
//		return -1;
//	}
//	pid = fork();
//	if (pid == 0){
//		//�ӽ��̴ӹܵ���ȡ���ݡ�0��
//		char buf[1024] = { 0 };
//		int ret = read(pipefd[0], buf, 1023);
//		//read�����������ļ���������д�����ݣ�д�볤��
//		if (ret < 0)
//		{   //��ȡ����
//			perror("read error\n");
//			return -1;
//		}
//		printf("child get data:[%s]\n", buf);
//	}
//	else{
//		//��������ܵ�д�����ݡ�1��
//		char *ptr = "������ĺ��䰡~";
//		int ret = write(pipefd[1], ptr, strlen(ptr));
//		if (ret < 0){
//			perror("write error\n");
//			return -1;
//		}
//	}
//	return 0;
//}
