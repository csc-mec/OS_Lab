#include <stdio.h>

struct proc{
    int pid;
    int wtime;
    int btime;
    int ttime;
};

void main(){
    int n;
    float totalwtime = 0;
    float combinedwait = 0;
    printf("Enter number of process : ");
    scanf("%d" , &n);
    struct proc p[n];

    for(int i=0 ; i<n ;i++){
        printf("Process %d burst time : " , i);
        scanf("%d" , &p[i].btime);
        p[i].pid = i+1; 
    }

    for(int i=0 ; i<n ; i++){
        p[i].wtime = totalwtime;
        combinedwait += totalwtime;
        totalwtime += p[i].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
    }

    printf("\nPID\tBURST TIME\tWAIT TIME\tTURNAROUND TIME\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t%d\t\t%d\t\t%d\n" , p[i].pid , p[i].btime , p[i].wtime , p[i].ttime);
    }
    printf("Average Wait Time : %.2f\n" , combinedwait/n);
    return;
}