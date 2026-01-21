#include "thrd_pool.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*
 * 测试程序
 g++ -Wl,-rpath=./ main.cc -o ./build/main-test -I./ -L./ -lthrdpool -lpthread
*/
#define MAX_SIZE 300

void printabc(void *arg) {
    printf("abc: %d -- %d\n", (unsigned int)pthread_self()%10, *(int *)arg);
}

void print123(void *arg) {
    printf("123: %d -- %d\n", (unsigned int)pthread_self()%10, *(int *)arg);
}

handler_pt funcs[2] = {printabc, print123};
int main(int argc, char **argv) {
    thrdpool_t *pool = thrdpool_create(6);
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = i;
        // if (i % 10 == 0)
        //     usleep(1000);
        thrdpool_post(pool, funcs[i % 2], static_cast<void *>(&arr[i]));
    }
    usleep(10000);
    thrdpool_terminate(pool);
    thrdpool_waitdone(pool);
    return 0;
}
