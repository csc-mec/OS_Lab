#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(){
    int shmid;
    key_t key;
    char *shm;

    //Creates the key
    key = ftok("shmfile" , 'R');

    //Create SHM segment
    shmid = shmget(key , SHM_SIZE , IPC_CREAT | 0666);

    //Attach the segment
    shm = shmat(shmid , NULL ,0);

    char str[100];
    printf("Enter data to write : ");
    scanf("%s" , str);

    sprintf(shm , str);
    printf("\nWrote !\n");
    shmdt(shm);

}