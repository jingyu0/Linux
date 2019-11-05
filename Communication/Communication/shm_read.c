1 /**********************************************************
  2  * Author        : Jingyu Sun
  3  * Email         : sun1705990821@163.com
  4  * Create time   : 2019-11-05 03:33
  5  * Last modified : 2019-11-05 03:33
  6  * Filename      : shm.c
  7  * Description   : 这个demo体会共享内存的基本操作
  8  * int shmget(key_t key,size_t size,int shmfig);
  9  * 功能：创建共享内存
  10  * 参数：
  11  *      key:共享内存在内核中的标识，其他进程通过相同的标识打开同一个内存
  12  *      size:共享内存的大小
  13  *      shmflg:IPC_CREAT|IPC_EXCL|mode
  14  *  返回值：成功返回共享内存的操作句柄，失败返回-1
  15  * *******************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define IPC_KEY 0x12345678
#define SHM_SIZE 4096

  int main()
{
	  int shmid = shmget(IPC_KEY, SHM_SIZE, IPC_CREAT | 0664);
	  if (shmid < 0){
		  perror("shmget error");
		  return -1;
	  }
	  void *shm_start = shm(shmid, NULL, 0);
	  if (shm_start == (void*)-1) {
		  perror("shmat error");
		  return -1;
	  }
	   int i=0;
      while(1){   
		  printf("%s", (char*)shm_start);
         // sprintf(shm_start,"%s-%s\n","今天天气暖洋洋~",i++);
          sleep(1);
      }
      shmdt(shm_start);
      shmctl(shmid,IPC_RMID,NULL);
	  return 0;
  }

		  sleep(1);
	  }
	  shmdt(shm_start);
	  shmctl(shmid, IPC_RMID, NULL);
	  return 0;
  }
