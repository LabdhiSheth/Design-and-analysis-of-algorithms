//iterative and recursive insertion sort

#include <stdio.h>
#include <stdlib.h>

void iterativeInsertionSort(int ar[],int n)
{
    int i,j;

    for(i = 1; i < n; i++)
    {
        int key = ar[i];
        j = i;

        while(j > 0 && ar[j-1] > key)
        {
            ar[j] = ar[j-1];
            j--;
        }
        ar[j] = key;
    }
}

void recursiveInsertionSort(int ar[],int n, int i)
{
    int j = i;
    int key = ar[i];

    while(j > 0 && ar[j-1] > key)
    {
        ar[j] = ar[j-1];
        j--;
    }

    ar[j] = key;
    if(i <= n - 1)
    {
        recursiveInsertionSort(ar,n,i+1);
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
        printf("Do you wish to perform \n1. iterative approach \n2. Recursive approach for insertion sorting \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                iterativeInsertionSort(ar,n);
            break;
            case 2:
                recursiveInsertionSort(ar,n-1,1);
            break;
            default:
                printf("Your have entered an invalid choice \n");
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Sorted array is\n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",ar[i]);
        }

        printf("\n----------------------------------------------------------------------------------\n");
        printf("Do you wish to continue? (1 for yes 0 for no)      ");
        int ans;
        scanf("%d",&ans);
        flag = ans;
        printf("\n----------------------------------------------------------------------------------\n");
    }

}
