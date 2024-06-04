#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
    key_t  key = ftok("shmfile",'R');
    int shmid;
    int n;

    shmid = shmget(key, (n+1)*sizeof(int), IPC_CREAT|0666);

    pid_t child = fork();
    if (child == -1)
    {
        printf("Failed to create a child.");
        exit(EXIT_FAILURE);
    }
    else if(child > 0)
    {
        //Parent Process (Hardcoding the array.)
        int *arr = (int *)shmat(shmid, NULL, 0);
        arr[0] =0;
        arr[1] = 2;
        arr[2] = 2;
        arr[3] = 2;
        arr[4] = 2;
        shmdt(arr);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
    else 
    {
        //Child Process
        int sum =0; 
        int *arr = (int *)shmat(shmid, NULL, 0);
        for (int i = 0; i<=4; i++)
        {
            sum+=arr[i];
        }
        printf("The sum of elements is %d\n",sum);
        shmdt(arr);
        exit(EXIT_SUCCESS);
    }
}