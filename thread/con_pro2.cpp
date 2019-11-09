#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_QUE 10
class RingQueue{
    public:
        std::vector<int> _queue;
        int _capacity;
        int _read_step;
        int _write_step;
        sem_t _sem_lock;
        sem_t _sem_data_space;
        sem_t _sem_idle_space;
    public:
        RingQueue(int max_que = MAX_QUE):_capacity(max_que),
            _queue(max_que), _read_step(0), _write_step(0) {
            sem_init(&_sem_lock, 0, 1);
            sem_init(&_sem_data_space, 0, 0);
            sem_init(&_sem_idle_space, 0, max_que);
        }
        ~RingQueue() {
            sem_destroy(&_sem_lock);
            sem_destroy(&_sem_data_space);
            sem_destroy(&_sem_idle_space);
        }
        bool QueuePush(int &data);
        bool QueuePop(init &data);
};
