#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <pthread.h>

typedef struct spinlock {
    pthread_spinlock_t lock;
} spinlock_t;

#ifdef __cplusplus
extern "C" {
#endif

void spinlock_init(spinlock_t *lock);
void spinlock_lock(spinlock_t *lock);
void spinlock_unlock(spinlock_t *lock);

#ifdef __cplusplus
}
#endif

#endif /* SPINLOCK_H */