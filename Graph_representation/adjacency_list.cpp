/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : adjacency_list.cpp
 * Created on    : Monday 22 July 2019 06:12:38 PM IST
 * Last modified : Monday 22 July 2019 06:35:04 PM IST
 * Description   : graph representation using adjacency list. 
 * ***********************************************************************/


#include <iostream>
#include <vector>

void addEdge (std::vector<int> adjList[], int src, int dest)
{
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void printList (std::vector<int> adjList[], int v)
{
	std::cout << "Adjacency List for the given graph: \n";

	for (auto i = 0; i < v; i++){ 
		std::cout << i << "->";
		for (auto temp : adjList[i]){
			std::cout << temp << "->";
			}
		std::cout << std::endl;
	}
	
}

int main()
{	
	int v = 6; 						// total number of vertices
	std::vector<int> adjList[v];	// adjacency list for each vertex

	addEdge (adjList, 0, 1);
	addEdge (adjList, 0, 2);
	addEdge (adjList, 0, 4);

	addEdge (adjList, 1, 5);
	addEdge (adjList, 2, 5);
	addEdge (adjList, 3, 2);

	printList (adjList, v);

	return 0;
}
