#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int v;
	list<int>* adj;
	bool DFS(int u,bool* visited,int parent);
	public:
		Graph(int n);
		void addEdge(int a,int b);
		bool isCyclic();
};

Graph::Graph(int n)
{
	v=n;
	adj=new list<int>[v];
}

bool Graph::DFS(int u,bool* visited,int parent)
{
	visited[u]=true;
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		if(!visited[*i]&&DFS(*i,visited,u))
		return true;
		else if(*i!=parent)
		return true;
	}
	return false;
}

bool Graph::isCyclic()
{
	bool visited[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	for(int i=0;i<v;i++)
	{
		if(!visited[i]&&DFS(i,visited,-1))
		return true;
	}
	return false;
}

void Graph::addEdge(int a,int b)
{
	adj[a].push_back(b);
	cout<<"adding edge"<<endl;
	adj[b].push_back(a);
}

int main()
{
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
	cout<<g1.isCyclic();
	return 0;
}
