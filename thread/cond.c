/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：通过吃面的demo体会临界资源访问的时序合理性以及条件变量的基本              使用 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int is_have_noodle = 0;
pthread_cond_t cond_foodie;
pthread_cond_t cond_chef;
pthread_mutex_t mutex;

void *foodie(void *arg)
{
    while(1){
        pthread_mutex_lock(&mutex);
        while(is_have_noodle == 0) {
            //pthread_mutex_unlock(&mutex);
            //pause();
            //pthread_mutex_lock(&mutex);
            //若没有面，吃面的人应该解锁，让做面的去做面，但是解锁和休眠
            //必须是一个原子操作，因为若解锁和休眠之间被打断，厨师做面唤醒
            //吃面的人的时候，吃面的人还没有休眠，就白唤醒了，但是因为没有
            //第二次唤醒，吃面的人就有可能会永久休眠
            pthread_cond_wait(&cond_foodie, &mutex);
        }
        printf("eat noodles, delicious~~!\n");
        is_have_noodle--;
        pthread_mutex_unlock(&mutex);
        //至少唤醒一个
        pthread_cond_signal(&cond_chef);
        //pthread_cond_broadcast  广播唤醒所有人
    }
    return NULL;
}
void *chef(void *arg)
{
    while(1){
        pthread_mutex_lock(&mutex);
        while(is_have_noodle == 1) {
            pthread_cond_wait(&cond_chef, &mutex);
        }
        printf("cook noodles~~\n");
        is_have_noodle++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond_foodie);
    }
    return NULL;
}
#define MAX_FOODIE 4
int main (int argc, char *argv[])
{
    pthread_t foodie_tid, chef_tid;
    int ret = 0;

    pthread_cond_init(&cond_foodie, NULL);
    pthread_cond_init(&cond_chef, NULL);
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < MAX_FOODIE; i++) {
        ret = pthread_create(&foodie_tid, NULL, foodie, NULL);
        if (ret != 0) {
            printf("thread create error\n");
            return -1;
        }
    }
    ret = pthread_create(&chef_tid, NULL, chef, NULL);
    if (ret != 0) {
        printf("thread create error\n");
        return -1;
    }

    pthread_join(foodie_tid, NULL);
    pthread_join(chef_tid, NULL);
    pthread_cond_destroy(&cond_chef);
    pthread_cond_destroy(&cond_foodie);
    pthread_mutex_destroy(&mutex);
    return 0;
}
