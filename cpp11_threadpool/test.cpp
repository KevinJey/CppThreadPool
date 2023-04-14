#include <unistd.h>
#include "threadpool.h"

void mytask(int i) {
    printf("Info: thread %ld is working on task %d\n", (u_int64_t)pthread_self(), i);
    sleep(1);
    return;
}

int main() {
    
    ThreadPool threadpool(20); // threadpool capacity is 20
    // 开了一百个线程在这里
    for (int i = 0; i < 100; ++i) {
        threadpool.enqueue(mytask, i); // task and his args
    }
    return 0;
}