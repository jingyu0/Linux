/**********************************************************
* Author        : Jingyu Sun
* Email         : sun1705990821@163.com
* Create time   : 2019-10-31 22:34
* Last modified : 2019-10-31 22:34
* Filename      : pipe2.c
* Description   : ͨ�������ܵ�ʵ�ֹܵ���
* ps -ef | grep ssh
* ps ���̺�grep �������ֵܽ��̣�
* ps���̽��������grep����ʹ�ý��̼�ͨ��-�����ܵ�
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
		//����1ʵ��ps
		//�ܵ������Ƕ��ֶ��ر�
		close(pipefd[0]);
		//��ԭ��д����׼����˵������ض��򵽹ܵ������
		dup2(pipefd[1], 1);
		execlp("ps", "ps", "-ef", NULL);
		exit(0);

	}
	int pid2 = fork();
	if (pid2 == 0){
		//����2ʵ��grep
		close(pipefd[1]);
		//��д����׼����˵������ض��򵽹ܵ���ȡ��
		dup2(pipefd[0], 0);
		//execlp:��PATH���������в����ļ���ִ��
		execlp("grep", "grep", "ssh", NULL);
		exit(0);

	}
	//�������к��ֶ��رո����̵Ķ�д��
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
