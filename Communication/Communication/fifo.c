/**********************************************************
   * Author        : Jingyu Sun
   * Email         : sun1705990821@163.com
   * Create time   : 2019-11-05 00:16
   * Last modified : 2019-11-05 00:16
   * Filename      : fifo.c
   * Description   : ���demo��ʾ�����ܵ��Ļ�������
   * int mkfifo(const char *pathname,mode_t mode)
   * pathname���ܵ��ļ�·������
   * mode���ܵ��ļ��Ĳ���Ȩ��
   * �ɹ�����0��ʧ�ܷ���-1�� 
   * *******************************************************/
  
  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include <fcntl.h>
  #include <errno.h>
  #include <sys/stat.h>
  
  int main()
  {
      char *file = "./test.fifo";
      int ret = mkfifo(file,0644);
      if(ret<0){
          if(errno != EEXIST){
              perror("mkfifo error");
              return -1;
          }
      }
	  //�������������ܵ������е�
	  //�������ܵ���ֻ����ʽ�򿪣��������ֱ���ܵ��ļ�������������д�ķ�ʽ��
	  //�������ܵ���ֻд��ʽ�򿪣��������ֱ���ܵ��ļ������������Զ��ķ�ʽ��
      int fd = open(file,O_RDWR);
      if(fd<0){
          perror("open error");
          return -1;
      }
	  printf("open success\n");
	  while (1){
		  char buf[1024] = { 0 };
		  int ret = read(fd, buf, 1023);
		  if (ret == 0){
			  printf("�ܵ�û��д�ˣ�����д�˱��ر�\n");
			  return 0;
		  }
		  else if (ret < 0){
			  perror("read error");
			  return -1;
		  }
		  printf("buf:[%s]\n", buf);
	  }
      return 0;
  }
