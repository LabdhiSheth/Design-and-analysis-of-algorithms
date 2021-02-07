#include <stdio.h>
#include<limits.h>

char matrixName = 'A';
int sequence[50][50];

void printParenthesis(int l, int r)
{
    if (l == r)
    {
        printf("%c", matrixName);
        matrixName++;
        return;
    }
    else
    {
        printf("(");
        printParenthesis(l, sequence[l][r]);
        printParenthesis(sequence[l][r] + 1, r);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n)
{

    int m[n][n];
    int bracket[n][n];

    // cost is zero when multiplying one matrix.
    for (int i=1; i<n; i++)
    {
        m[i][i] = 0;
    }

    // L is chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n-L+1; i++)
        {
            int j = i+L-1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j-1; k++)
            {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    sequence[i][j] = k;
                }
            }
        }
    }

    printf("\nOptimal Parenthesize is : ");
    printParenthesis(1,n-1);
    printf("\nOptimal Cost is : %d\n",m[1][n-1]);
}

int main()
{
    printf("\t\t\t\t\t\tMatrix chain multiplication");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    int n;
    printf("Enter number of dimensions entries: ");
    scanf("%d",&n);

    int a[n];
    printf("Enter the dimensions in array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    matrixChainOrder(a, n);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    return 0;
}
