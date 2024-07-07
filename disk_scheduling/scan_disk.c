#include <stdio.h>
#include <stdlib.h>


void main()
{
    int n, total_move = 0, intial, direction;
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

    printf("Enter the direction for movement :(0-low or 1-high)");
    scanf("%d",&direction);

    //Spliting the array
    int left[n], right[n], left_size=0, right_size=0;

    for (int i=0; i<n; i++)
    {
        if (rs[i] < intial)
        left[left_size++] = rs[i];
        else
        right[right_size++] = rs[i];
    }

    //Sorting both halves

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

    printf("Prining the sorted array's\n");

    for(int i=0 ; i<left_size; i++)
    printf("%d\t",left[i]);

    printf("\n");

    for(int i=0 ; i<right_size; i++)
    printf("%d\t",right[i]);

    //Applying Algorithm

    if (direction==1)
    {
        //Starting from the right array

        for (int i=0 ; i<right_size; i++)
        {
            total_move += abs(right[i]-intial);
            intial = right[i];
        }
        //End of right array
        //Moving towards left array

        for (int i=left_size-1; i>=0; i--)
        {
            total_move += abs(left[i]- intial);
            intial = left[i];
        }

        printf("Total movement : %d",total_move);
    }
    else
    {
        //Starting from the left 
        for (int i=left_size-1 ; i>=0; i--)
        {
            total_move+= abs(left[i]-intial);
            intial = left[i];
        }

        //Reached the end of left array
        //Swapping to the right array

        for (int j=0; j<right_size; j++)
        {
            total_move += abs(right[j]-intial);
            intial = right[j];
        }
        printf("Total movement : %d",total_move);
    }
}