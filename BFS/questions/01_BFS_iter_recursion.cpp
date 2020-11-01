/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : BFS_iter_recursion.cpp
 * Created on    : Sunday 18 October 2020 01:45:27 PM IST
 * Last modified : Sunday 18 October 2020 01:46:04 PM IST
 * Description   : 
 * ***********************************************************************/

#include "graph.h"
#include <queue>
using namespace std;

void BFS_iteration(Graph graph, int start)
{
	queue<int> q;
	int vertex = graph.vertex;
	int visited[vertex+1] = {0};
	visited[start] = 1;
	q.push(start);
	
	while(!q.empty()){
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (auto item : graph.adjList[node]){
			if(visited[item] == 0){
				visited[item] = 1;
				q.push(item);
			}
		}
	}
}
// int *visited = new int[graph.vertex + 1];
// 	for(auto i = 0; i < graph.vertex + 1; i++)
// 		visited[i] = 0;

void BFS_recursion(Graph graph, int start){
	static queue<int> q;
	static int *visited = new int[graph.vertex + 1];
	if(visited[start] == 0){
		q.push(start);
		visited[start] = 1;
	}
	
	// for(auto i = 0; i < graph.vertex + 1; i++)
	// 	visited[i] = 0;

	visited[start] = 1;
	if(q.empty()){
		cout << endl;
		return;
	}
	
	cout << q.front() << " ";
	int node = q.front();
	q.pop();

	for(auto item:graph.adjList[start]){
		if(visited[item] == 0){
			visited[item] = 1;
			q.push(item);
		}
	}

	BFS_recursion(graph, node);
	
}

int main()
{
	 list<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
		// vertex 0, 13 and 14 are single nodes
	};

	Graph graph(edges, 13);
	graph.print();

	BFS_iteration(graph, 7);
	cout << endl;

	BFS_recursion(graph, 7);


	return 0;
}
