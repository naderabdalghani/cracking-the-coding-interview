#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Graph
{
	int V;
	vector<int>* adj;
	Graph(int V) : V(V) {
		adj = new vector<int>[V];
	}
	void addEdge(int x, int y) {
		adj[x].push_back(y);
	}
};


bool isRoute(Graph G, int x, int y) {
	if (y == x) return true;
	vector<bool> visited;
	for (int i = 0; i < G.V; i++)
	{
		visited.push_back(false);
	}
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		vector<int> neighborNodes = G.adj[q.front()];
		for (int i = 0; i < neighborNodes.size(); i++)
		{
			if (!visited[neighborNodes[i]]) 
			{
				if (neighborNodes[i] == y) return true;
				visited[neighborNodes[i]] = true;
				q.push(neighborNodes[i]);
			}
		}
		q.pop();
	}
	return false;
}


int main() {
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	/*
		Test graph :
		0 <---4---->1
		^ 			^
		|			|
		|			|
		5---->2---->3
	*/
	cout << isRoute(g, 5, 4) << endl; // false
	cout << isRoute(g, 5, 1) << endl; // true
	return 0;
}