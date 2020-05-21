/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : clusters.c
 * Created on    : Wednesday 25 March 2020 11:52:14 PM IST
 * Last modified : Thursday 26 March 2020 12:11:38 AM IST
 * Description   : find number of clusters or island in 2-d array
 *                 1 is represented as land
 *                 0 is represented as water
 *                 using DFS
 * ***********************************************************************/

#include <stdio.h>
#define N 6

int visited[N][N] = {0};
void printVisited()
{
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}  
}

void dfs(int graph[N][N], int row, int col)
{
	if(row < 0 || col < 0 || row > N || col > N || visited[row][col] == 1){
		printf("returning\n");
		return;
	}
	visited[row][col] = 1;
	dfs(graph, row, col + 1);
	dfs(graph, row, col - 1);
	dfs(graph, row + 1, col);
	dfs(graph, row - 1, col);	
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
	int i, j;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(graph[i][j] == 1){
				dfs(graph, i, j);
				printVisited();
			}
		}
	}


	return 0;
}
