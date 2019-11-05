1 /**********************************************************
  2  * Author        : Jingyu Sun
  3  * Email         : sun1705990821@163.com
  4  * Create time   : 2019-11-05 03:33
  5  * Last modified : 2019-11-05 03:33
  6  * Filename      : shm.c
  7  * Description   : ���demo��Ṳ���ڴ�Ļ�������
  8  * int shmget(key_t key,size_t size,int shmfig);
  9  * ���ܣ����������ڴ�
  10  * ������
  11  *      key:�����ڴ����ں��еı�ʶ����������ͨ����ͬ�ı�ʶ��ͬһ���ڴ�
  12  *      size:�����ڴ�Ĵ�С
  13  *      shmflg:IPC_CREAT|IPC_EXCL|mode
  14  *  ����ֵ���ɹ����ع����ڴ�Ĳ��������ʧ�ܷ���-1
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
         // sprintf(shm_start,"%s-%s\n","��������ů����~",i++);
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
