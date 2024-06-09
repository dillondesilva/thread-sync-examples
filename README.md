# thread-sync-examples

Contains basic C code demonstrating how to use **condition variables** and **pthread barriers** for thread synchronization.

## Mutexes vs Semaphores vs Condition Variables vs Barriers
The following dot points are quick descriptions of different thread synchronization techniques:
- Mutexes: Great for binary state locking of a critical sections used by threads. Threads will be blocked until the mutex has been acquired
- Semaphores: Act as counters for how many threads are using a critical section. Useful for allowing a specified amount of threads to access a critical section at once
- Condition variables: Used for signalling when a thread's execution should be stopped/started
- Barriers: Used to block threads until a certain amount are waiting at the barrier
- Livelock vs Deadlock: Deadlocks occur when a thread is never able to acquire a mutex lock (consequently blocked indefinitely). Livelocks occur when threads continue swapping locks in such a way that they repeatedly block each other
