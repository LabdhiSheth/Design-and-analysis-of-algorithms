/*Labdhi Sheth - 18BCE101
Aim - To perform Median of Median algorithm
*/

#include <stdlib.h>
#include <stdio.h>

int find_median(int a[], int groupsize)
{
    printf("\nThe group is: ");

    for (int f = 0; f < groupsize; ++f)
    {
        printf("%d ", a[f]);
    }

    int i, k, j;
    for(i = 1;i < groupsize;i++)
    {
        k = a[i];
        j = i - 1;

        while(j >= 0 && k < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }

    int temp = groupsize/2;
    printf("\nMedian for this group is : %d \n", a[temp]);
    return a[temp];
}

void swap(int num[], int a, int b)
{
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

int partition(int nums[], int beg, int end, int num)
{
    int i;

    for(i = beg;i < end; i++)
    {
        if (nums[i] == num)
        {
            break;
        }
    }

    //swapping
    swap(nums,i,end);

    i = beg;
    for(int j = beg; j <= end - 1; j++)
    {
        if (nums[j] <= num)
        {
            swap(nums, i, j);
            i++;
        }
    }

    swap(nums, i, end);
    return i;
}

int smallest(int a[], int low, int high, int size, int groupsize)
{
    int temp = high - low + 1;

    if (size > 0 && size <= temp)
    {
        int t_size = high - low + 1;
        int median[(t_size + groupsize - 1) / groupsize];
        int i;

        for (i = 0; i < (t_size / groupsize); ++i)
        {
            median[i] = find_median(a + low + (i * groupsize), groupsize);
        }

        if (i * 5 < t_size)
        {
            median[i] = find_median(a + low + (i * groupsize), t_size % groupsize);
        }

        int median_of_median;

        if (i == 1)
        {
            median_of_median = median[i - 1];
        }
        else
        {
            median_of_median = smallest(median, 0, i - 1, i/2, groupsize);
        }

        int pos = partition(a, low, high, median_of_median);

        if (pos - low == temp - 1)
        {
            return a[pos];
        }

        if (pos - low > temp - 1)
        {
            return smallest(a, low, pos - 1, temp, groupsize);
        }

        return smallest(a, pos + 1, high, temp - pos + low - 1, groupsize);
    }
    return 1000;
}

void sort(int a[], int low, int high, int groupsize)
{
    if (low < high)
    {
        int size = high - low + 1;
        int mid = size/2;

        int med = smallest(a, low, high, mid, groupsize);

        int p = partition(a, low, high, med);
        sort(a, low, p - 1, groupsize);
        sort(a, p + 1, high, groupsize);

    }
}

void main()
{
    printf("\t\t\t\t\t\t\tMedian of medians");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    int n,p,i;
    printf("\nEnter the number of elements :");
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; ++i)
    {
        printf("Enter the element %d: \t",i+1);
        scanf("%d", &a[i]);
    }

    int groupsize;
    printf("\nEnter the size of the group:");
    scanf("%d", &groupsize);
    printf("\n--------------------------------------------------------------\n");

    printf("Enter the value of i where i is the element you wish to find: \t");
    scanf("%d",&p);
    printf("\n");

    printf("\n--------------------------------------------------------------\n");
    sort(a, 0, n - 1, groupsize);

    for (int i = 0; i < n; ++i)
    {
        if(i == p)
        {
            printf("\n--------------------------------------------------------------\n");
            printf("\n%d element is:%d\n",i,a[i-1]);
            printf("\n--------------------------------------------------------------\n");
        }

    }
}
