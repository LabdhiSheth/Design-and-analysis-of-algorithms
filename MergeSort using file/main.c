#include <stdio.h>
#include <stdlib.h>

int arr[500];
void createFile()
{
    FILE *file;
    file = fopen("DAAPracInput_numbers.txt","w");

    int i;
    for(i=0; i < 500; i++)
    {
        int num = (int)rand();
        fprintf(file,"%d\n",num);
    }
    fclose(file);
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
          arr[k] = leftArray[i];
          i++;
        }
        else
        {
          arr[k] = rightArray[j];
          j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
  if (left < right)
    {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}


int main()
{
    createFile();
    int num;

    FILE *file;
    file = fopen("DAAPracInput_numbers.txt","r");

    int i,j,k=0,count = 0;
    for(i = 0; i <= 500; i += 50)
    {
        for(j = 0; j < 50; j++)
        {
            fscanf(file,"%d",&num);
            arr[k++] = num;
        }

        mergeSort(arr,0, i - 1);
        printf("After %d iteration array is: \n",count);
        for(j = 0; j < i; j++)
        {
            printf("%d ",arr[j]);
        }
        printf("\n----------------------------------------------------------------------------------\n\n");
        count++;
    }

    FILE *fout1;
    fout1=fopen("DAAoutputFile.txt","w");

    for(i = 0;i < 500; i++)
    {
        fprintf(fout1,"%d\n",arr[i]);
    }

    printf("Completed");
    fclose(fout1);
    fclose(file);
    return 1;
}
