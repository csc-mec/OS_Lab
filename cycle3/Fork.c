#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main() {

  pid_t proc_id=fork();

  if(proc_id<0){

    printf("No Child Created\n");
    return;

    }

else{
    printf("Child created:%d", getpid());
    }

pid_t w=wait(NULL);
printf("%d\n",w);
execlp("ls", NULL);
return;
}
