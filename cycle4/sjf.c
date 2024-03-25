#include <stdio.h>

struct proc {
    int pid;
    int btime;
    int wtime;
    int ttime;
};

void bubbleSort(struct proc p[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].btime > p[j+1].btime) {
                struct proc temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void main() {
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

    bubbleSort(p, n);

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