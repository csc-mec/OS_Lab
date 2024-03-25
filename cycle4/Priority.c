#include<stdio.h>

struct Process{
    int bt,wt,tt,pid,priority;
};

int main(){
    int n,waitingtime,totaltime=0,twait=0, tturnaround=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    struct Process p[n];
    for(int i=0;i<n;i++){
        printf("Enter burst time and priority of Process%d: ",i);
        scanf("%d %d",&p[i].bt, &p[i].priority);
        p[i].pid=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].priority>p[j+1].priority){
                struct Process temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }		
    for(int i=0;i<n;i++){
        p[i].wt=totaltime;
        totaltime+=p[i].bt;
        twait+=p[i].wt;
        p[i].tt=p[i].bt+p[i].wt;
        tturnaround+=p[i].tt;
    }
    printf("------------------------------------------\n");
    printf(" Process\t BT \t WT \t TT \t Priority\n");
    for(int i=0;i<n;i++){
        printf(" %d\t\t%d \t %d \t %d \t %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt,p[i].priority);
    }
    printf("------------------------------------------\n");
    twait=twait/n;
    tturnaround=tturnaround/n;
    printf("Average Wait time:%d\n",twait);
    printf("Average TurnAround time:%d\n",tturnaround);
    return 0;
}
/* Output
Enter number of process:4
Enter burst time and priority of Process0: 5
4
Enter burst time and priority of Process1: 4
1
Enter burst time and priority of Process2: 3
2
Enter burst time and priority of Process3: 6
3
------------------------------------------
 Process	 BT 	 WT 	 TT 	 Priority
 2		     4 	   0 	   4 	       1
 3		     3 	   4 	   7 	       2 
 4		     6 	   7 	   13 	     3
 1		     5 	   13 	 18 	     4
------------------------------------------
Average Wait time:6
Average TurnAround time:10
*/  
