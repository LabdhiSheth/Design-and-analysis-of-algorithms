
//iterative and recursive Selection sort

#include <stdio.h>
#include <stdlib.h>

void swap(int ar[], int i, int j)
{
    int temp = ar[j];
    ar[j] = ar[i];
    ar[i] = temp;
}

void iterativeSelectionSort(int ar[],int n)
{
    int i,j;

    for(i = 0; i < n; i++)
    {
        int minval = ar[i];
        int minindex = i;

        for(j = minindex; j < n; j++)
        {
            if(ar[j] < minval)
            {
                minindex = j;
                minval = ar[j];
            }
        }

        swap(ar, i, minindex);
    }
}

void recursiveSelectionSort(int ar[],int n,int i,int j)
{
    if(i < n-1)
    {
        if(j < n)
        {
            if(ar[i] > ar[j])
            {
                swap(ar, i , j);
            }

            recursiveSelectionSort(ar,n,i,j+1);
        }
        else
        {
            recursiveSelectionSort(ar,n,i+1,i+1);
        }
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
        printf("Do you wish to perform \n1. iterative approach \n2. Recursive approach for Selection sorting \n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            iterativeSelectionSort(ar,n);
        break;
        case 2:
            recursiveSelectionSort(ar,n,0,0);
        break;
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Sorted array is\n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",ar[i]);
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Do you wish to continue? (1 for yes 0 for no)         ");
        int ans;
        scanf("%d",&ans);
        flag = ans;
        printf("\n----------------------------------------------------------------------------------\n");
    }

}
