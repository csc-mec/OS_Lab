#include<stdio.h>
int main(){
    int n,m;
    printf("Enter no. of Processes:");
    scanf("%d",&n);
    printf("Enter no. of resources:");
    scanf("%d",&m);
    int Allocation[n][m],Max[n][m],Available[m],Need[n][m],Work[m],Finish[n],safesequence[n],ind=0,completed=0;
    printf("Enter Allocation matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&Allocation[i][j]);
        }
    }
    printf("Enter Maximum matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&Max[i][j]);
        }
    }
    printf("Enter Available Resources:");
    for(int i=0;i<m;i++){
        scanf("%d",&Available[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Need[i][j]=Max[i][j]-Allocation[i][j];
        }
    }
    for(int i=0;i<n;i++){
        Finish[i]=0;
    }
    for(int i=0;i<m;i++){
        Work[i]=Available[i];
    }
while(completed!=n){
    for(int i=0;i<n;i++){
        if(Finish[i]==0){
            int flag=0;
            for(int j=0;j<m;j++){
                if(Need[i][j]>Work[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                safesequence[ind++]=i;
                for(int k=0;k<m;k++){
                    Work[k]+=Allocation[i][k];
                }
                Finish[i]=1;
                completed++;
            }
        }
    }
}
    printf("Need Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",Need[i][j]);
        }
        printf("\n");
    }
    printf("Safe Sequence:");
    for(int i=0;i<n;i++){
        printf("%d\t",safesequence[i]);
    }
}
