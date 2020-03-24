/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : recursion.cpp
 * Created on    : Wednesday 24 July 2019 09:27:49 PM IST
 * Last modified : Wednesday 24 July 2019 09:57:46 PM IST
 * Description   : Depth first search using recursion. 
 * ***********************************************************************/
	
#include <iostream>
#include <vector>

class Graph {
	private:
		std::vector<int> *adjList;
		int v;	// number of vertex

	public:
		Graph (int vertex);
		void addEdge (int src, int dest);
		void print ();
		void DFS (int src);
};

// constructor
Graph::Graph (int vertex):v{vertex}
{
	adjList = new std::vector<int>[v];
}

void Graph::addEdge (int src, int dest)
{
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::print ()
{
	std::cout << "Adjacency list of the graph:\n";

	for (auto i = 0; i < v; i++){
		std::cout << i << "->";

		for (auto temp:adjList[i])
			std::cout << temp << "->";

		std::cout << std::endl;
	}
}

void Graph::DFS (int src)
{
	for (auto temp:adjList[src]){
		DFS(temp);
		std::cout << temp << " ";
	}

}

int main ()
{
	Graph graph(5);
	
	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	graph.addEdge(4, 1);
	graph.addEdge(3, 1);
	graph.addEdge(2, 1);

	graph.print();

	graph.DFS(0);

	return 0;
}
