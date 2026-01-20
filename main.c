#include "thrd_pool.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void printabc(void *arg) {
    printf("abc: %d -- %d\n", (unsigned int)pthread_self()%100, (int)arg);
}

void print123(void *arg) {
    printf("123: %d -- %d\n", (unsigned int)pthread_self()%100, (int)arg);
}

handler_pt funcs[2] = {printabc, print123};
int main(int argc, char **argv) {
    thrdpool_t *pool = thrdpool_create(10);
    for (int i = 0; i < 300; i++) {
        if (i % 10 == 0)
            sleep(1);
        thrdpool_post(pool, funcs[i % 2], (void *)i);
    }
    thrdpool_terminate(pool);
    thrdpool_waitdone(pool);
    return 0;
}
