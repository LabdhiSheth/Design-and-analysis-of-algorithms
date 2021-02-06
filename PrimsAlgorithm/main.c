/*18BCE101 - Labdhi Sheth
Aim : Implementation of Prims Algorithm
*/

#include <stdio.h>
#include <stdlib.h>

#define max +2147483647
#define min -2147483648

int totalPrimcost(int n, int adj[n][n], int spanning[n][n])
{
    int distance[n], visited[n], prevNode[n], cost[n][n];
    int i , j;
    int u , v;
    int totCost = 0, minDist = 0, noOfEdges = n - 1;

    //assign weights to cost array
    //initializing spanning array to all zero values
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(adj[i][j] == 0)
            {
                cost[i][j] = max;
            }
            else
            {
                cost[i][j] = adj[i][j];
            }

            spanning[i][j] = 0;
        }
    }

    //assigning weights of 0th node to distance array
    //initializing visited and preNode array to 0
    for(i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        visited[i] = 0;
        prevNode[i] = 0;
    }

    distance[0] = 0;
    visited[0] = 1;

    //visiting all nodes
    while(noOfEdges-- > 0)
    {
        minDist = max;

        //finding minimum weight
        for(i = 1; i < n; i++)
        {
            if(visited[i] == 0)
            {
                if(distance[i] < minDist)
                {
                    minDist = distance[i];
                    v = i;
                }
            }
        }

        u = prevNode[v];
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        visited[v] = 1;

        //finding next minimum weight from prevNode index
        for(i = 1; i < n; i++)
        {
            if(visited[i] == 0 && cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                prevNode[i] = v;
            }
        }

        totCost += cost[u][v];
    }

    return totCost;
}

int main()
{
    /*n vertices - Time complexity - O(n^2)*/
    printf("Enter the total number of vertices: \n");
    int n;
    scanf("%d",&n);

    //weighted undirected graph
    printf("\nEnter the adjacency matrix\n");
    int i,j;
    int adj[n][n];
    int spanning[n][n];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    printf("\n--------------------------------------------------------------------\n");
    int cost = totalPrimcost(n,adj,spanning);
    printf("Minimum cost is : %d\n\n",cost);

    //weights of the undirected spanning tree
    printf("Adjacency matrix of Spanning tree is as follows - \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t",spanning[i][j]);
        }
        printf("\n");
    }
}

