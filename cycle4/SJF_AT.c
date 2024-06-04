#include<stdio.h>
#define max 20
struct sjf{
    int pid;
    int BT;
    int WT;
    int AT;
    int TAT;
}
p[max];
int main(){
    int totTAT=0,totWT=0,n,shortest;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Burst time of P%d:",i);
        scanf("%d",&p[i].BT);
        printf("Arrival time of P%d:",i);
        scanf("%d",&p[i].AT);
        p[i].pid=i;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].AT>p[j].AT){
                struct sjf temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    int completed=0;
    int time=0;
    int isCompleted[max]={0};
    while(completed<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(p[i].AT<=time&&!isCompleted[i]){
                found=1;
                shortest=i;
                for(int j=0;j<n;j++){
                    if(!isCompleted[j]&&p[j].AT<time&&p[j].BT<p[shortest].BT){
                        shortest=j;
                    }
                }
                p[shortest].WT=time-p[shortest].AT;
                p[shortest].TAT=p[shortest].WT+p[shortest].BT;
                time+=p[shortest].BT;
                isCompleted[shortest]=1;
                totWT+=p[shortest].WT;
                totTAT+=p[shortest].AT;
                completed++;
            }
            if(!found){
                time++;
            }
        }
    }
    float avgTAT=(float)totTAT/n;
    float avgWT=(float)totWT/n;
    printf("==================Gantt Chart==================\n");
    printf("    Process     BT       AT         WT        TAT     \n");
    for(int i=0;i<n;i++){
        printf("    %d          %d         %d         %d          %d      \n",p[i].pid,p[i].BT,p[i].AT,p[i].WT,p[i].TAT);
    }
    printf("Average WT:%.2f\n",avgWT);
    printf("Average TAT:%.2f\n",avgTAT);
    return 0;
}
