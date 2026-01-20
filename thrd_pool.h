#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_


typedef struct thrdpool_s thrdpool_t;
// 任务执行的规范 ctx 上下文
typedef void (*handler_pt)(void * /* ctx */);

#ifdef __cplusplus
extern "C" 
{
#endif 

// 对称处理
// 创建线程池
thrdpool_t *thrdpool_create(int thrd_count);

// 暂停线程池
void thrdpool_terminate(thrdpool_t *pool);

// 提交任务到线程池
int thrdpool_post(thrdpool_t *pool, handler_pt func, void *arg);

// 等待线程池任务完成
void thrdpool_waitdone(thrdpool_t *pool);

#ifdef __cplusplus
}
#endif

#endif /* _THREAD_POOL_H_ */