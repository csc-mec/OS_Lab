#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    key_t key; int shmid; char *shm, *ptr;
    key = ftok("shmfile",'R');
    shmid = shmget(key, 1024, IPC_CREAT|0666);
    pid_t child;
    child = fork();

    if (child ==-1)
    {
        printf("Failed to create child.");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        //Child Process (Reader task)
        wait(NULL);
        shm = shmat(shmid , NULL, 0);
        ptr  = shm ;
        printf("\nStarting the reader process");
        printf(ptr);
        shmdt(shm);
        exit(EXIT_SUCCESS);

    }
    else{
        //Parent Process
        shm = shmat(shmid, NULL, 0);
        ptr = shm;
        sprintf(ptr, "\nHello, World!\n");
        printf("\nWriting process completed.");
        shmdt(shm);
        
    }





}