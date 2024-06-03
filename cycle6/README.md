### Functions brief

- `sem_wait(Semaphore s)` : Decrement the value of semaphore s by 1. If the value of semaphore is negative, then block the process.
- `sem_post(Semaphore s)` : Increment the value of semaphore s by 1. 

- `sem_init(Semaphore s, int pshare , int value)` : Initialize the semaphore s with the value. If pshare is 0, then semaphore is shared among threads of a process. If pshare is 1, then semaphore is shared among processes.

- `pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)` : Create a new thread and store its id in thread. The new thread starts executing from the function start_routine with argument arg. since we use default attributes and no arguments, we pass NULL.

- `pthread_join(pthread_t thread, void **retval)` : this is used to synchronize the parent and child threads. since we don't need any return value from the child thread, we pass NULL.