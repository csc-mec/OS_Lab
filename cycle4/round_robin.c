#include <stdio.h>

struct process{
	int pid;
	int wtime;
	int ttime;
	int btime;
    int btime_copy;
	int occur;
};

void main(){
	int totaltime = 0;
	float twaittime = 0;
	int timeslice = 0;
	int totalbursttime = 0;
	int iterator = 0;
	int n;
	int currentproc = 0;
	printf("Enter number of process : ");
	scanf("%d",&n);
	printf("Enter timeslice : ");
	scanf("%d",&timeslice);
	iterator = timeslice ;
	struct process p[n];

	for(int i=0 ; i<n ; i++){
		printf("Process %d burst time : ",i+1);
		scanf("%d",&p[i].btime);
        p[i].btime_copy = p[i].btime;
		p[i].pid = i+1;
		totalbursttime += p[i].btime;
		p[i].occur = 0;
	}
	
	for(int i=0 ; i<totalbursttime ; i++){
        //Checks if a single process is ran a full timeslice
        //If true change the process to next one and reset the iterator
        if((iterator % timeslice == 0 && i != 0)){
            currentproc = (currentproc + 1)%n;
            iterator = timeslice ;
        }
        //Check whether the process ended before full timeslice
        //If true reset the timeslice and change process to next one
        while(p[currentproc].btime_copy == 0){
                currentproc = (currentproc + 1)%n;
                iterator = timeslice ;
        }
        p[currentproc].occur ++ ;
        totaltime++;
        p[currentproc].btime_copy--;
        // use this line to print the table thingy to see working
        // printf(" %d ",p[currentproc].pid);
        iterator--; 
        p[currentproc].wtime = i - (p[currentproc].occur);
        p[currentproc].wtime +=  1;
	}
	printf("\n");
    printf("\nPID\tBURST TIME\tWAIT TIME\tTURNAROUND TIME\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t%d\t\t%d\t\t%d\n" , p[i].pid , p[i].btime , p[i].wtime , p[i].btime + p[i].wtime);
        twaittime += p[i].wtime;
    }
	printf("Average wait time : %.2f \n",twaittime/n);
}