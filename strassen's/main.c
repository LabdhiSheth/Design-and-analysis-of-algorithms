/*18BCE101 - Labdhi Sheth
Aim - Implementation of Strassen's Matrix Multiplication for 2X2 matrix*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\t\t\t\t\t\t\tStrassen's Matrix Multiplication for 2X2 matrix");

    int a[2][2], b[2][2], ans[2][2];
    int i,j;
    int p1,p2,p3,p4,p5,p6,p7;

    printf("\nEnter the elements of the first matrix\n");
    for(i = 0;i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter the elements of the second matrix\n");
    for(i = 0;i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
           scanf("%d",&b[i][j]);
        }
    }

    printf("\n-------------------------------------------------------------\n");
    //calculating the seven products
    p1 = a[0][0] * (b[0][1] - b[1][1]);
    printf("\nP1 = %d",p1);

    p2 = (a[0][0] + a[0][1]) * b[1][1];
    printf("\nP2 = %d",p2);

    p3 = (a[1][0] + a[1][1]) * b[0][0];
    printf("\nP3 = %d",p3);

    p4 = a[1][1] * (b[1][0] - b[0][0]);
    printf("\nP4 = %d",p4);

    p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    printf("\nP5 = %d",p5);

    p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    printf("\nP6 = %d",p6);

    p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);
    printf("\nP7 = %d",p7);

    //storing the result in ans matrix
    ans[0][0] = p5 + p4 + p6 - p2;
    ans[0][1] = p1 + p2;
    ans[1][0] = p3 + p4;
    ans[1][1] = p1 - p3 + p5 - p7;

    //printing the result

    printf("\n-------------------------------------------------------------\n");
    printf("\nFirst matrix is - \n");
    for(i = 0;i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
           printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    printf("\n-------------------------------------------------------------\n");
    printf("\nSecond matrix is - \n");
    for(i = 0;i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
           printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    printf("\n-------------------------------------------------------------\n");
    printf("\nAnswer matrix is - \n");
    for(i = 0;i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
           printf("%d\t",ans[i][j]);
        }
        printf("\n");
    }
}
