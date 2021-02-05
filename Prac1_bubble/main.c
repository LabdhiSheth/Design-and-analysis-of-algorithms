//iterative and recursive bubble sort

#include <stdio.h>
#include <stdlib.h>

void swap(int ar[], int i, int j)
{
    int temp = ar[j];
    ar[j] = ar[i];
    ar[i] = temp;
}

void iterativeBubbleSort(int ar[],int n)
{
    int i,j;
    int flag = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                swap(ar,j,j+1);
                flag = 1;
            }
        }

        //if the input array is in ascending order then we break the loop
        if(flag == 0)
        {
            break;
        }
    }
}

void recursiveBubbleSort(int ar[],int n)
{
    int i,j;
    i = n;
    if(i > 0)
    {
        for(j = 0; j < n - 1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                swap(ar,j,j+1);
            }
        }

        recursiveBubbleSort(ar,n-1);
    }
    else
    {
        return;
    }
}

int main()
{
    int flag = 1;
    while(flag)
    {
        int n;
        printf("Enter the length of the array\n");
        scanf("%d",&n);
        int ar[n];

        printf("\nEnter the values \n");
        int i;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&ar[i]);
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Unsorted array is \n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",ar[i]);
        }

        printf("\n----------------------------------------------------------------------------------\n");
        int choice;
        printf("Do you wish to perform \n1. iterative approach \n2. Recursive approach for bubble sorting \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                iterativeBubbleSort(ar,n);
            break;
            case 2:
                recursiveBubbleSort(ar,n);
            break;
            default:
                printf("You have entered a wrong choice \n");
            break;
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Sorted array is\n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",ar[i]);
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Do you wish to continue? (1 for yes 0 for no)     ");
        int ans;
        scanf("%d",&ans);
        flag = ans;
        printf("\n----------------------------------------------------------------------------------\n");
    }

}
