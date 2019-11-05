/**********************************************************
   * Author        : Jingyu Sun
   * Email         : sun1705990821@163.com
   * Create time   : 2019-11-05 00:16
   * Last modified : 2019-11-05 00:16
   * Filename      : fifo.c
   * Description   : 这个demo演示命名管道的基本操作
   * int mkfifo(const char *pathname,mode_t mode)
   * pathname：管道文件路径名称
   * mode：管道文件的操作权限
   * 成功返回0，失败返回-1； 
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
	  //打开特性是命名管道所独有的
	  //若命名管道以只读方式打开，则会阻塞直到管道文件被其他进程以写的方式打开
	  //若命名管道以只写方式打开，则会阻塞直到管道文件被其他进程以读的方式打开
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
			  printf("管道没人写了，所有写端被关闭\n");
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
