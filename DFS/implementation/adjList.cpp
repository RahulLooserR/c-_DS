/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : adjList.cpp
 * Created on    : Wednesday 24 July 2019 08:47:31 PM IST
 * Last modified : Wednesday 24 July 2019 08:56:42 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <list>


class Graph {
	private:
		int v;          // number of vertices
		std::list<int> *adjList;

	public:
		Graph (int v);
		void addEdge (int src, int dest);
		void DFS (int src);
		void print ();
};

Graph::Graph (int v):v{v}
{
	adjList = new std::list<int>[v];
}

void Graph::addEdge (int src, int dest)
{
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::DFS (int src)
{
	bool visited[v] = {0};
	std::list<int> stack;

	visited[src] = true;    // marking source vertex, visited
	stack.push_front(src);   // adding source in the queue
	std::cout << "Depth first traversal for the graph: \n";

	while (!stack.empty()){
		int front = stack.front();    // storing front element
		stack.pop_front();          // deque first element

		std::cout << front << " ";

		// exploring adjacent vertex and pushing in the queue
		// and marking visited node
		for (auto temp:adjList[front]){
			if (visited[temp] != true){
				visited[temp] = true;
				stack.push_front(temp);
			}
		}
	}

	std::cout << std::endl;
}

void Graph::print ()
{
	for (auto i = 0; i < v; i++){
		std::cout << i << "->";
		for (auto temp:adjList[i])
			std::cout << temp << "->";

		std::cout << std::endl;
	}
}

int main ()
{
	Graph graph(5);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(2, 4);
	//graph.addEdge(2, 3);

	graph.print();
	graph.DFS(0);

	return 0;
}

