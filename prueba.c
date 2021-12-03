#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int hilo;
pthread_mutex_t mutex;



void    *do_something(void *nada)
{
    pthread_mutex_lock(&mutex);
    hilo += 1;
    printf("Hilo %d started working\n", hilo);
    printf("Hilo %d finished working\n", hilo);
    pthread_mutex_unlock(&mutex);
     // Lock y unlock del mutex
    // para proteger una variable
    //pthread_mutex_lock(&mutex);
    //Sección crítica

    //pthread_mutex_unlock(&mutex);
    return NULL;
}



int main()
{
    //Creación e inicializacion del mutex
    //pthread_mutex_t mutex;
    //pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex, NULL);

    // Creación de hilos
    int i = 0;
    int err;
    pthread_t id[2];
    while (i < 2)
    {
        err = pthread_create(&id[i], NULL, &do_something, NULL);
        if (err != 0)
            printf("can't create a thread\n");
        i++;
    }

    pthread_join(id[0], NULL);
    //pthread_join(id[1], NULL);

}