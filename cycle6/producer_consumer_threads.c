#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define MAX_PRODUCE 20

int buffer[BUFFER_SIZE];

int in   = 0 ;
int out  = 0 ;

int produced  = 0;
int consumed  = 0;

sem_t empty ;
sem_t full;
sem_t mutex;

void* producer(void* args){
    int item = 1;

    while(produced < MAX_PRODUCE){
        sem_wait(&empty);
        sem_wait(&mutex);
        
        //Critical Section
            printf("Produced    : %d\n" , item);
            buffer[in] = item++;
            in = (in+1)%BUFFER_SIZE;
        //End Critical section
        produced++;

        sem_post(&mutex);
        sem_post(&full);
    }    

    pthread_exit(NULL);
}

void* consumer(void* args){
    int item = 1;

    while(consumed < MAX_PRODUCE){
        sem_wait(&full);
        sem_wait(&mutex);
        
        //Critical Section
            printf("\tConsumed    : %d\n" , buffer[out]);
            out = (out+1)%BUFFER_SIZE;
        //End Critical section
        consumed++;

        sem_post(&mutex);
        sem_post(&empty);
    }

    pthread_exit(NULL);    
}

int main(){
    pthread_t producerThread , consumerThread;

    sem_init(&mutex , 0 , 1);
    sem_init(&full , 0 , 0);
    sem_init(&empty , 0 , BUFFER_SIZE);

    pthread_create(&producerThread , NULL , producer , NULL);
    pthread_create(&consumerThread , NULL , consumer , NULL);

    pthread_join(producerThread,NULL);
    pthread_join(consumerThread,NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}