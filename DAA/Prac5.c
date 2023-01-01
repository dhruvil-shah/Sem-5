#include <stdio.h>
#include <stdlib.h>
void prims();
int n=5;
int graph[5][5] = 
{ { 0, 9, 75, 0, 0 },
 { 9, 0, 95, 19, 42 }, 
 { 75, 95, 0, 51, 66 }, 
 { 0, 19, 51, 0, 31 },
    { 0, 42, 66, 31, 0 } }; 
   
void main()
{
    prims();
}
void prims()
{
    int vis[n];
    int min_val[n];
    int parent[n];
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    for (int i = 0; i < n; i++)
        min_val[i] = 100000;
    for (int i = 0; i < n; i++)
        parent[i] = -1;    
    min_val[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int ind = -1, min = 100000;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] != 1 && min_val[j] < min)
            {
                min = min_val[j];
                ind = j;
            }
        }
        vis[ind] = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[ind][j] != 0 && vis[j] != 1 && graph[ind][j] < min_val[j])
            {
                min_val[j] = graph[ind][j];   
                parent[j]=ind;
            }
        }
    }
     
    int final_g[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< n; j++)
        {
            final_g[i][j]=0;
        }
        
    }
    for(int i=1;i<n;i++){
        final_g[i][parent[i]]=graph[i][parent[i]];
        final_g[parent[i]][i]=graph[i][parent[i]];
    }
    printf("\nFinal Graph Obtained is as Follows\n");
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ",final_g[i][j]);
        }
        printf("\n");
    }
        for (int i = 1; i < n; i++)
        printf("%d---->%d==%d \n", parent[i], i, graph[i][parent[i]]);
}
    
    





