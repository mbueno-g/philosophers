# philosophers

WIP 🚧


:books: [Introduction](#introduction) : Dining philosopher problem
 
:collision: [New concept](#new-concept): Thread + mutex
 
:footprints: [Step by step](#step-by-step)

## Introduction
The Philosophers proyect introduces the basics of threading a process and discover the mutex through a version of the dining philosopher problem.

This version of the dining philosopher problem states that *N* philosophers are seated at a round table either eating spaghetti, sleeping or thinking (once at a time). The table is set so there's a fork/chopstick for every philosopher (i.e. k forks). In order to start eating, they will need 2 forks, one for each hand. Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking.
The simulation stops when the philosophers have eaten n times or when a philosopher dies, i.e. when the philo starves.

Philosophers are numbered from 1 to *N*. This way philosopher number *k* is seated between philosopher *k-1* and philosopher *k+1*.
 
 <div align=center>
<img src="https://user-images.githubusercontent.com/71781441/145614999-38c05b91-04fa-4ecc-afb2-9819502da815.jpg" height="350">
</div>


This program takes the following arguments:

```
./philo <num_philos> <time_to_die> <time_to_eat> <time_to_sleep> <num_of_times_philo_eats>
```
| Argument  | Description |
| :-------: | :---------: |
| `num_philo`  | number of philosophers and also the number of forks|
| `time_to_die`| maximum miliseconds that can go by after a philosophers' last meal or the beginning of the simulation |
| `time_to_eat`| miliseconds that takes a philosopher to eat
| `time_to_sleep`| miliseconds that a philosopher spends sleeping
| `num_of_times_philo_eats`| (optional argument) the simulation stops if all philosophers eat at least this number of times

The logs of this program must be shown as follows:
```
{timestamp_in_ms} ➤ <philosopher_number> <philosopher_status>
```
where the status are:
- has taken a fork 🥢
- is eating 🍣
- is sleeping 💤
- is thinking 💫
- died ⚰️ 


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
### Thread
A thread, known as a lightweight process, is a path of execution within a process, with its own program counter that keeps track of which instruction to execute next, system registers which hold its current working variables, and a stack which contains the execution history.

Threads within the same process run in a shared memory space, while processes run in separate memory spaces. So if one thread alters a code segment memory item, all other threads see that.

### Mutex
Mutex (mutual exclusion object) is a program object that is created so that multiple threads can take turns sharing the same resource (variables, piece of code...). When a thread accesses a share resource a lock is set and it is release after using it, leaving this resource available for other threads.
This works as follows:
1. Thread 1 locks a region of code using mutex and executes a piece of code.
2. Thread 2 tries to execute this same piece of code but it is locked by thread 1 so thread 2 is on pause waiting.
3. Once thread 1 releases the mutex lock this region of code can be execute by thread 2.

This system ensures synchronization among the threads while working on shared resources. Let's see a simple example with two threads (a thread starts working once the previous one has finished):

```
int thread;

void    *status(void *arg)
{
    pthread_mutex_lock(&mutex);
    thread += 1;
    printf("Thread %d started working\n", thread);
    printf("Thread %d finished working\n", thread);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Creating a mutex
pthread_mutex_t mutex;

int main()
{
    // Initializing mutex
    pthread_mutex_init(&mutex, NULL);
    
    // Threads id
    pthread_t id[2];
    
    // Creating two threads
    int i = 0;
    while (i < 2)
    {
        pthread_create(&id[i], NULL, &status, NULL);
        i++;
    }
    pthread_join(id[0], NULL);
}
```
The output using mutex is:
```
Thread 1 started working
Thread 1 finished working
Thread 2 started working
Thread 2 finished working
```
However, if we don't use mutex we would get this output:
```
Thread 1 started working
Thread 2 finished working
Thread 2 started working
Thread 2 finished working
```
