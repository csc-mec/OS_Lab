#include <stdio.h>
#include <stdlib.h>

void main ()
{
     int n, total_move = 0, initial, direction, disk_size;
    printf("Enter the number of sequences :");
    scanf("%d",&n);
    int rs[n];
    printf("Enter the request string");
    for (int i=0 ; i<n; i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter the initial position and the disk size:");
    scanf("%d%d",&initial,&disk_size);

    int left[n], right[n], left_size=0, right_size=0;

    //Spliting the array

    for (int i=0; i<n; i++)
    {
        if (rs[i]<initial)
        {
            left[left_size++] = rs[i];
        }
        else
        right[right_size++] = rs[i];
    }

    //Sorting the arrays

    for(int i=0 ; i<left_size-1; i++)
    {
        for (int j=0 ; j<left_size-1-i; j++)
        {
            if (left[j]>left[j+1])
            {
                int temp = left[j+1];
                left[j+1] = left[j];
                left[j] = temp;
            }
        }
    }

    for(int i=0 ; i<right_size-1; i++)
    {
        for (int j=0 ; j<right_size-1-i; j++)
        {
            if (right[j]>right[j+1])
            {
                int temp = right[j+1];
                right[j+1] = right[j];
                right[j] = temp;
            }
        }
    }

    printf("Printing the sorted array's\n");

    for(int i=0 ; i<left_size; i++)
    printf("%d\t",left[i]);

    printf("\n");

    for(int i=0 ; i<right_size; i++)
    printf("%d\t",right[i]);

    //CSCAN Algorithm


    //Considering the head moves from lower to higher cylinder
    //Starting from the right subarray

    for(int i=0 ; i< right_size; i++)
    {
        total_move+= abs(right[i]- initial);
        initial = right[i];
    }
    
    //Last request reached.
    //Moving to the end of disk and then back to start of the disk. (Cost from 199 to 0 is not considered.)

    total_move += abs(disk_size-1-initial);
    initial = 0;

    //Servicing the left subarray

    for (int i=0 ; i<left_size; i++)
    {
        total_move+= abs(left[i]-initial);
        initial = left[i];
    }


    printf("The total head movement is : %d", total_move);

}