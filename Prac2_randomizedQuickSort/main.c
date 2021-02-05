#include<stdio.h>
#include<stdlib.h>

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

//to shuffle the array if the entered array is in ascending order or descending order
void shuffle_array(int a[], int n)
{
    srand(time(NULL));
    int i, random_index;

    for(i = n - 1; i > 0; i--)
    {
        random_index = rand()%(i+1);
        swap(a,i,random_index);
    }
}

int partition(int a[], int left, int right)
{
    int random_pivot = left + rand()%(right - left + 1);
    int pivot;
    int i = left - 1;
    int j;
    pivot = a[random_pivot];
    swap(a,random_pivot,right);

    for(j = left; j < right; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a,i,j);
        }
    }

    swap(a, i+1,right);
    return i+1;
}

void quickSort(int a[], int left, int right)
{
    int partition_index;

    if(left < right)
    {
        partition_index = partition(a, left, right);
        quickSort(a, left, partition_index - 1);
        quickSort(a, partition_index + 1, right);
    }
}
int main()
{
    printf("Randomized Quick Sort \n");
    printf("\n----------------------------------------------------------------------------------\n\n");

    int n;
    printf("Enter the size of the array \n");
    scanf("%d",&n);

    int a[n];
    int i;
    printf("Enter the elements of the array \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    //check if array is sorted
    int flag = 0;
    for(i = 0; i < n-1 ; i++)
    {
        if(a[i] > a[i+1])
        {
            flag = 1;
        }
    }

    if(flag == 1)
    {
        printf("\n----------------------------------------------------------------------------------\n\n");
        printf("Elements before shuffling \n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",a[i]);
        }
        printf("\n");

        shuffle_array(a,n);

        printf("\n----------------------------------------------------------------------------------\n\n");
        printf("Elements after shuffling \n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",a[i]);
        }
        printf("\n");

        printf("\n----------------------------------------------------------------------------------\n\n");
        quickSort(a, 0, n-1);
        printf("Elements after sorting \n");
        for(i = 0; i < n; i++)
        {
            printf("%d \t",a[i]);
        }
        printf("\n----------------------------------------------------------------------------------\n\n");
    }
    else
    {
        printf("\nInput array is already sorted\n");
    }


}
