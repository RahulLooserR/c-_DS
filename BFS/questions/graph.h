/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 01_BFS_itr_rec.cpp
 * Created on    : Sunday 18 October 2020 08:10:01 AM IST
 * Last modified : Sunday 18 October 2020 08:12:45 AM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <list> 
#include <iterator> 

struct Edge{
	int src;
	int dest;
};

class Graph{
	public:
		Graph(std::list<Edge> const &edges, int vertex)
		{	this->vertex = vertex;
			adjList = new std::list<int>[vertex];
			for(auto &edge:edges){
				adjList[edge.src].push_back(edge.dest);
				adjList[edge.dest].push_back(edge.src);	
			}
		}
		
		void print()
		{
			for(int i = 1; i < vertex; i++){
				std::cout << i << "->";
				for(auto &item:adjList[i]){
					std::cout << item << "->";
				}
				std::cout << std::endl;
			}
		}
		std::list<int> *adjList;
		int vertex;
};
