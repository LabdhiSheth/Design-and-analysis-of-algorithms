/*
Name Labdhi Sheth
Roll Number - 18BCE101
Aim - Knapsack problem using Branch and bound
*/

#include <stdio.h>

void sort(int num, int *arr)
{

    float ratio[num];
    for (int i = 0; i < num; i++)
    {
        ratio[i] = (*((arr + i * 2) + 1) / (*((arr + i * 2) + 0)));
    }

    int i, j;
    int min;
    for (i = 0; i < num - 1; i++)
    {
        min = i;

        for (j = i + 1; j < num; j++)
        {
            if (ratio[j] > ratio[min])
            {
                min = j;
            }
        }

        ratio[i] = ratio[min];
        ratio[min] = ratio[i];

        int t1, t2;
        t1 = *((arr + i * 2) + 0);
        t2 = *((arr + i * 2) + 1);
        *((arr + i * 2) + 0) = *((arr + min * 2) + 0);
        *((arr + i * 2) + 1) = *((arr + min * 2) + 1);
        *((arr + min * 2) + 0) = t1;
        *((arr + min * 2) + 1) = t2;
    }

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("The input after sorting is :\n\n");
    printf("Item\t\tWeight\t\tProfit");
    for (i = 0; i < num; i++)
    {
        printf("\n%d\t\t%d\t\t%d ", (i + 1),*((arr + i * 2) + 0), *((arr + i * 2) + 1));
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}


int calculate_c(int num, int profit_weight[num][2], int weight, int use_item[num])
{

    int curr_w = weight;
    int curr_p = 0;
    for (int i = 0; i < num; i++)
    {
        if (use_item[i] == 1)
        {
            if (curr_w - profit_weight[i][0] >= 0)
            {
                curr_w = curr_w - profit_weight[i][0];
                curr_p = curr_p + profit_weight[i][1];
            }
            else
            {
                curr_w = 0;
                curr_p = curr_p + (int)(curr_w * (profit_weight[i][1] / profit_weight[i][0]));
            }
        }
    }

    return curr_p;
}

int calculate_u(int num, int profit_weight[num][2], int weight, int use_item[num])
{

    int curr_w = weight;
    int upper_bound = 0;
    for (int i = 0; i < num; i++)
    {
        if (use_item[i] == 1)
        {
            if (curr_w - profit_weight[i][0] >= 0)
            {
                curr_w = curr_w - profit_weight[i][0];
                upper_bound = upper_bound + profit_weight[i][1];
            }
        }
    }

    return upper_bound;
}

void knapsack(int num, int profit_weight[num][2], int weight)
{

    int solution[num];
    int use_item[num];

    for (int i = 0; i < num; i++)
    {
        use_item[i] = 1;
    }

    sort(num, (int *)profit_weight);

    int u = calculate_u(num, profit_weight, weight, use_item);
    int c = calculate_c(num, profit_weight, weight, use_item);

    printf("\nu = %d", u);
    printf("\nc = %d", c);
    printf("\n");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    int u1, u2, c1, c2, max = 0;
    for (int i = 0; i < num; i++)
    {

        //Taking the Item
        u1 = calculate_u(num, profit_weight, weight, use_item);
        c1 = calculate_c(num, profit_weight, weight, use_item);
        printf("\nTaking Item %d : ", (i + 1));
        printf("\nu = %d", u1);
        printf("\nc = %d", c1);

        //Without the Item
        use_item[i] = 0;
        u2 = calculate_u(num, profit_weight, weight, use_item);
        c2 = calculate_c(num, profit_weight, weight, use_item);
        printf("\nNot taking Item %d : ", (i + 1));
        printf("\nu = %d", u2);
        printf("\nc = %d", c2);
        printf("\n");
        if (u1 > u2)
        {
            max = u1;
            printf("\nWe will include item %d\n", (i + 1));
            solution[i] = 1;
            use_item[i] = 1;
        }
        else
        {
            max = u2;
            printf("\nWe will not include Item %d\n", (i + 1));
            solution[i] = 0;
        }
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    }

    printf("\nThe Maximum profit is : %d", max);
    printf("\nThe solution is :");
    for (int i = 0; i < num; i++)
    {
        printf(" %d", solution[i]);
    }
    printf("\nItems ");
    for (int i = 0; i < num; ++i) {
        if (solution[i] == 1) {
            printf("%d", (i + 1));
            if (i != (num - 1))
                printf(", ");
        }
    }
    printf(" are included");
}

void main()
{
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t0/1 Knapsack using branch and bound approach");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    int weight, num;
    printf("\nEnter the no of items : ");
    scanf("%d", &num);

    int profit_weight[num][2];

    for (int i = 0; i < num; i++)
    {
        printf("\nEnter the profit and weight of item %d : ", (i + 1));
        scanf("%d", &profit_weight[i][1]);
        scanf("%d", &profit_weight[i][0]);
    }

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\nEnter capacity : ");
    scanf("%d", &weight);

    knapsack(num, profit_weight, weight);
}
