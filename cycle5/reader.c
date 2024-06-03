#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024

int main(){
    int shmid;
    key_t key;
    char *shm;

    //Generate the key using same shmfile as writer process
    key = ftok("shmfile" , 'R');

    //Locate shmid
    shmid = shmget(key,SHM_SIZE , 0666);

    //Exit if shmid returns negative (NOT_FOUND)
    if(shmid<0){
        perror("Failed to locate shm\n");
        exit(1);
    }

    //Attach shmid
    shm = shmat(shmid,NULL,0);

    //Read the contents of shm
    printf("Message : \n %s \n" , shm);

    if(shmdt(shm) == -1){
        perror("Failed to detach shm\n");
        exit(1);
    }

    if(shmctl(shmid,IPC_RMID,NULL) == -1){
        perror("Failed to remove shmid \n");
        exit(1);
    }

    return 0;
}