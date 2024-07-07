#include <stdio.h>
#include <stdlib.h>

void main()
{
    int block_no, process_no;
    printf("Enter the number of blocks and the number of processes");
    scanf("%d%d",&block_no,&process_no);
    int block[block_no],process[process_no], allocation[process_no];

    printf("Enter the size of the blocks \n");
    for (int i=0; i<block_no; i++)
    {
        scanf("%d",&block[i]);
    }

    printf("Enter the size of the process \n");
    for (int i=0; i<process_no; i++)
    {
        scanf("%d",&process[i]);
        allocation[i] = -1;
    }

    //Allocation algorithm (firstfit)

/*
    for (int i=0; i<process_no; i++)
    {
        for (int j=0; j<block_no; j++)
        {
            if (process[i]<=block[j] && allocation[i] == -1)
            {
                allocation[i] = j;
                block[j] = block[j] - process[i];
                break;
            }
        }
    }
*/

/* //WorstFit

int worstIndex = -1;
for(int i=0; i<process_no; i++)
{
    worstIndex = -1;
    for (int j=0 ; j<block_no; j++)
    {
        if (block[j]> process[i])
        {
            if (worstIndex==-1||block[worstIndex]<block[j])
            {
                worstIndex = j;
            }
        }
    }
    allocation[i] = worstIndex;
    block[worstIndex] -= process[i];
}
*/

//BestFit
/*
int BestIndex = -1 ;
for (int i=0 ;i <process_no; i++)
{
    BestIndex = -1;
    for (int j=0 ; j<block_no; j++)
    {
        if (block[j] >= process[i])
        {
            if (BestIndex == -1 || block[j]<block[BestIndex])
            {
                BestIndex = j;
            }
        }
    }
    allocation[i] = BestIndex;
    block[BestIndex] -= process[i];
}
*/



    printf("\nResult\n");

    for (int i=0; i<process_no; i++)
    {
        printf("%d",allocation[i]);
    }
}