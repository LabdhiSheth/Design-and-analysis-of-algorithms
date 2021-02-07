#include <stdio.h>
#include <stdlib.h>

#define max +2147483647
#define min -2147483648

int mergeSum(int arr[], int left, int mid, int right)
{
    int sum = 0;
    int leftSum = min;
    int i;

    for(i = mid; i >= left; i--)
    {
        sum += arr[i];

        if(sum > leftSum)
        {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = min;
    for(i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if(sum > rightSum)
        {
            rightSum = sum;
        }
    }

    int temp1;

    if(leftSum > rightSum)
    {
        temp1 = leftSum;
    }
    else
    {
        temp1 = rightSum;
    }

    sum = leftSum + rightSum;

    if(temp1 > sum)
    {
        return temp1;
    }
    else
    {
        return sum;
    }
}

int mergeMaximumSum(int arr[], int left, int right)
{
    if(left == right)
    {
        return arr[left];
    }

    int mid = left + (right - left)/2;

    int ans;
    int temp1 = mergeMaximumSum(arr, left, mid);
    int temp2 = mergeMaximumSum(arr,mid + 1, right);

    if(temp1 > temp2)
    {
        ans = mergeSum(arr,left,mid,right);
        if(temp1 > ans)
        {
            return temp1;
        }
        else
        {
            return ans;
        }
    }
    else
    {
        ans = mergeSum(arr,left,mid,right);
        if(temp2 > ans)
        {
            return temp2;
        }
        else
        {
            return ans;
        }
    }

}

int main()
{
    int n;
    printf("Enter the size of the input array \n");
    scanf("%d",&n);

    int a[n];
    int i;

    printf("\nEnter the values\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    int ans = mergeMaximumSum(a,0 , n-1);

    printf("=========================================================================\n");
    printf("\nMaximum Subarray sum is : %d \n\n",ans);
    printf("=========================================================================\n");
}
