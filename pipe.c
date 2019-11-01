 /**********************************************************
    * Author        : Jingyu Sun
    * Email         : sun1705990821@163.com
    * Create time   : 2019-10-31 19:46
    * Last modified : 2019-10-31 19:46
    * Filename      : pipe.c 
    * Description   : ���demo��������ܵ��Ļ���ʹ��  
    * *******************************************************/
   
  #include<unistd.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  int main()
  {
          int pid = 0;
          int pipefd[2];
          int ret = pipe(pipefd);
          if (ret < 0){
                  //����
                  perror("pipe error\n");
                  return -1;
          }
          pid = fork();
          if (pid == 0){
	                  //�ӽ��̴ӹܵ���ȡ���ݡ�0��
                  close(pipefd[0]);
                  sleep(5);
                  char buf[1024] = { 0 };
                  int ret = read(pipefd[0], buf, 1023);
                  //read�����������ļ���������д�����ݣ�д�볤��
                  if (ret < 0)
                  {   //��ȡ����
                          perror("read error\n");
                          return -1;
                  }
                  printf("child get data:[%s]\n", buf);
          }
          else{
                  close(pipefd[0]);
                  //��������ܵ�д�����ݡ�1��
                  sleep(3);
                  int pipe_size = 0;
                  while(1){
                          char *ptr = "������ĺ��䰡~";
                          int ret = write(pipefd[1], ptr, strlen(ptr));
                          if (ret < 0){
                                  perror("write error\n");
                                  return -1;
 
 }
                          pipe_size += ret;
                          printf("write data:%d\n", pipe_size);
 
 }
 
 }
          return 0;
  }
