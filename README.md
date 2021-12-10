# philosophers

WIP 🚧


:books: [Introduction](#introduction) : Dining philosopher problem
 
:collision: [New concept](#new-concept): Thread + mutex
 
:world_map: [Concept map](#how-it-works)
 
:footprints: [Step by step](#step-by-step)

## Introduction
The Philosophers proyect introduces the basics of threading a process and discover the mutex through a version of the dining philosopher problem.
This version of the dining philosopher problem states that *k* philosophers are seated at a round table either eating spaghetti, sleeping or thinking (once at a time). The table is set so there's a fork/chopstick for every philosopher (i.e. k forks). In order to start eating, they will need 2 forks, one for each hand. Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking.
The simulation stops when then philosophers have eaten a certain amount of time or when a philosopher dies, i.e. when the philo starves.

<!--
| Function       | Description | Return |
| :------------: | :---------: | :-----:|
| ``int usleep(useconds_t usec)`` | Suspends execution of the calling thread for (at least) usec microseconds | Success: 0 ; Failure: -1 |
| ``int gettimeofday(struct timeval *restrict tv,struct timezone *restrict tz)`` |  | |
| ``int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg)`` |  Starts a new thread in the calling process | Succes: 0 ; Failure: error number|
| ``int pthread_detach(pthread_t thread)`` | Marks the thread identified by thread as detached | Succes: 0 ; Failure: error number |
| ``int pthread_join(pthread_t thread, void **retval)`` | Waits for the thread specified by thread to terminate | Succes: 0 ; Failure: error number |
| ``int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr)`` |  Initialize the mutex referenced by mutex with attributes specified by attr | Succes: 0 ; Failure: error number |
| ``int pthread_mutex_destroy(pthread_mutex_t *mutex)`` | Destroy the mutex object referenced by mutex | Succes: 0 ; Failure: error number | 
| ``int pthread_mutex_lock(pthread_mutex_t *mutex)`` | Locks the mutex object reference by mutex | Succes: 0 ; Failure: error number |
| ``int pthread_mutex_unlock(pthread_mutex_t *mutex)`` | Release the mutex object referenced by mutex | Succes: 0 ; Failure: error number |
-->

## New concept
*What is a thread?* 
A thread, known as a lightweight process, is a path of execution within a process, with its own program counter that keeps track of which instruction to execute next, system registers which hold its current working variables, and a stack which contains the execution history.

Threads within the same process run in a shared memory space, while processes run in separate memory spaces. So if one thread alters a code segment memory item, all other threads see that.

*What is mutex?* 
Mutex in a binary variable
