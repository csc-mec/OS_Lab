#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int n, total_move = 0, intial;
    printf("Enter the number of sequences :");
    scanf("%d",&n);
    int rs[n];
    printf("Enter the request string");
    for (int i=0 ; i<n; i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter the initial position :");
    scanf("%d",&intial);

    //FCFS algo

    for(int i=0 ; i<n; i++)
    {
        total_move+= abs(rs[i] - intial);
        intial = rs[i];
    }

    printf("Total movement : %d",total_move);

}