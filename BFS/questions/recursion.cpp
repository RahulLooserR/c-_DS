/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : recursion.cpp
 * Created on    : Wednesday 24 July 2019 02:36:58 PM IST
 * Last modified : Wednesday 24 July 2019 05:59:01 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <list>


class Graph {
	private:
		int v;          // number of vertices
		std::list<int> *adjList;
		std::list<int> queue;
		bool *visited;

	public:
		Graph (int v);
		void addEdge (int src, int dest);
		void BFS ();
		void bfsTraversal (int src);
		void print ();
};

Graph::Graph (int v):v{v}
{
	adjList = new std::list<int>[v];
	visited = new bool[v];
	visited = {0};
}

void Graph::addEdge (int src, int dest)
{
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::bfsTraversal (int src)
{
	std::cout << "1\n";
	queue.push_back(src);
	std::cout << "2\n";
	BFS();
}

void Graph::BFS ()
{
	std::cout << "inside function call\n";
	std::cout << queue.front();
	if (queue.empty()){
		std::cout << "inside if\n";
		return;
	}

	int front = queue.front();
	for (auto temp:adjList[front]){
		if (visited[temp] != true){
			queue.push_back(temp);
			visited[temp] = true;
			std::cout << temp << " ";

		}
	}
	std::cout << "Exiting for loop\n";
	queue.pop_front();
	BFS ();
}

void Graph::print ()
{
	for (auto i = 0; i < v; i++){
		std::cout << i << "->";
		for (auto temp:adjList[i])
			std::cout << temp << "->";

		std::cout << std::endl;
//		std::cout << "calling queue.empty()\n" << queue.empty();
	}
}

int main ()
{
	Graph graph(6);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 4);
	graph.addEdge(1, 5);
	graph.addEdge(2, 5);
	graph.addEdge(2, 3);

	// graph.queue.push_back(0);

	graph.print();

	graph.bfsTraversal(5);

	return 0;
}

