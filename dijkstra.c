#define MAX 9


#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>

int minDistance(int dist[],bool sptSET[],int vertc)
{
	int min = INT_MAX;
	int min_index,v;
	for ( v = 0; v < vertc; v++)
     if (sptSET[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}

int print(int dist[], int n,int parent[])
{
	int i;
	int src ;
   printf("Vertex  \tDistance \t Path");
   for ( i = 1; i < n; i++)
   {
      	printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
    	printPath(parent, i);
    	printf("\n");
   }
}


void dijkstra(int graph[MAX][MAX],int src,int vertc)
{
	int i;
	int dist[MAX];
	int count,u,v;
	
	bool sptSET[MAX];
	
	int parent[MAX];
	
	for(i = 0;i < vertc;i += 1)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSET[i] = false;
	}
	
	dist[src] = 0;
	
	for(count = 0;count < vertc-1;count += 1)
	{
		u = minDistance(dist,sptSET,vertc);
		
		sptSET[u] = true;
		
		for(v = 0;v < vertc;v += 1)
		{
			if(!sptSET[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
		  		parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
		print(dist,vertc,parent);
	}
}

int main()
{
	 int vertices;
	int graph[MAX][MAX];
	int i,j;
	int source;
	
	printf("\n Enter the vertices of the graph");
	scanf("%d",&vertices);
	
	printf("\n Enter graph:");
	for(i = 0;i < vertices;i += 1)
	{
		for(j = 0;j < vertices;j += 1)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	
	printf("\n Enter the source vertex:");
	scanf("%d",&source);
	
	dijkstra(graph,source,vertices);
	
	return 0;
}

