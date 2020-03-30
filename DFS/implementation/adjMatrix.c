/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : adjMatrix.c
 * Created on    : Wednesday 25 March 2020 12:05:35 PM IST
 * Last modified : Wednesday 25 March 2020 12:19:59 PM IST
 * Description   : implementtation of Depth First Search using adjacency 
 * 				   matrix. 
 * ***********************************************************************/
	
#include <stdio.h>
#define N 6 // number of vertices

void dfs(int graph[N][N], int start)
{
	int i;
	int static visited[N] = {0};
	visited[start] = 1;
	printf("%d ", start);

	for(i = 0; i < N; i++){
		if(graph[start][i] == 1 && visited[i] == 0){
			visited[i] = 1;
			dfs(graph, i);
		}
	}
}

int main()
{
	int graph[N][N] = {
		{0, 1, 1, 1, 0, 0},
		{1, 0, 0, 0, 1, 0},
		{1, 0, 0, 1, 1, 0},
		{1, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 1, 0}
	};
	
	int start = 3;

	dfs(graph, start);
	printf("\n");	

	return 0;
};
