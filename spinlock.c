#include "spinlock.h"
#include <stdlib.h>


void spinlock_init(spinlock_t *lock) {
    pthread_spin_init(&lock->lock, PTHREAD_PROCESS_PRIVATE);
}

void spinlock_lock(spinlock_t *lock) {
    pthread_spin_lock(&lock->lock);
}

void spinlock_unlock(spinlock_t *lock) {
    pthread_spin_unlock(&lock->lock);
}