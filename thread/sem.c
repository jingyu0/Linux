#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int tickets = 100;
sem_t sem;
void *thr_eat (void *arg)
{
    while(1) {
        sem_wait(&sem);
        if (tickets > 0) {
            usleep(1000);
            printf(" i get tickets:%d\n", tickets--);
            sem_post(&sem);
        }else {
            sem_post(&sem);
            pthread_exit(NULL);
        }
        //sem_wait(&sem);
        //printf("delicious~~~\n");
    }
    return NULL;
}
void *thr_cook(void *arg)
{
    while(1) {
        printf("cook noodle~~\n");
        sleep(1);
        sem_post(&sem);
    }
    return NULL;
}
int main()
{
    int ret;
    pthread_t tid1, tid2;

    sem_init(&sem, 0, 1);
    ret = pthread_create(&tid1, NULL, thr_eat, NULL);
    if (ret != 0) {
        return -1;
    }
    ret = pthread_create(&tid2, NULL, thr_eat, NULL);
    if (ret != 0) {
        return -1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_destroy(&sem);
    return 0;
}
