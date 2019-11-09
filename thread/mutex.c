/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：通过黄牛抢票的例子体会线程安全的重要性以及认识互斥锁 
================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THR 4
int tickets = 100;
pthread_mutex_t mutex;

void *cattle(void *arg)
{
    while(1) {
        //pthread_mutex_lock    阻塞加锁
        //pthread_mutex_trylock 非阻塞加锁
        //pthread_mutex_timedlock 限制阻塞时长的阻塞加锁
        pthread_mutex_lock(&mutex);
        if (tickets > 0) {
            printf("%p i get a ticket:%d\n", pthread_self(), tickets);
            usleep(1000);
            tickets--;
            pthread_mutex_unlock(&mutex);
        }else  {
            printf("have no tickets\n");
            //加锁之后，需要在任意有可能退出线程的地方都要进行解锁
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }
    }
    return NULL;
}
int main (int argc, char *argv[])
{
    pthread_t tid[MAX_THR];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < MAX_THR; i++) {
        int ret = pthread_create(&tid[i], NULL, cattle, NULL);
        if (ret != 0) {
            printf("thread create error\n");
            return -1;
        }
    }
    for (int i = 0; i < MAX_THR; i++) {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
