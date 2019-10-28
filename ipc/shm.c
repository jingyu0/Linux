/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo体会共享内存的基本操作
*   int shmget(key_t key, size_t size, int shmflg);
*   功能：创建共享内存
*   参数：
*       key：共享内存在内核中的标识，其它进程通过相同的标识打开同一个内存
*       size：共享内存大小
*       shmflg：IPC_CREAT|IPC_EXCL|mode
*   返回值：成功返回共享内存的操作句柄， 失败返回-1； 
================================================================*/

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
    if (shmid < 0) {
        perror("shmget error");
        return -1;
    }
    shmctl(shmid, IPC_RMID, NULL);
    return 0;

    void *shm_start = shmat(shmid, NULL, 0);
    if (shm_start == (void*)-1) {
        perror("shmat error");
        return -1;
    }
    int i = 0;
    while(1) {
        sprintf(shm_start, "%s-%d\n", "今天天气暖洋洋~", i++);
        sleep(1);
    }
    shmdt(shm_start);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
