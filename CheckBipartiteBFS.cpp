#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int v;
	vector<int>* adj;
	public:
		Graph(int n)
		{
			v=n;
			adj=new vector<int>[v];
		}
		void addEdge(int a,int b)
		{
			adj[a].push_back(b);
			adj[b].push_back(a);				
		}
		bool checkBipartite();
};

bool Graph::checkBipartite()
{
	queue<int> que;
	que.push(0);
	cout<<"pushed : 0\n";
	int color[v];
	for(int i=0;i<v;i++)
	color[i]=-1;
	color[0]=1;	
	while(!que.empty())
	{
		
		int x=que.front();
		que.pop();
		for(int i=0;i<adj[x].size();i++)
		{
			if(color[adj[x][i]]==color[x])
			return false;
			if(color[adj[x][i]]!=-1)
			continue;
			que.push(adj[x][i]);
			cout<<"pushed : "<<adj[x][i]<<"\n";
			color[adj[x][i]]=(color[x]+1)%2;
		}
	}
	return true;
}
int main()
{
	cout<<"Enter number of vertices and the number of edges: \n";
	int n,m,a,b;
	cin>>n>>m;
	Graph grp(n);
	cout<<"Enter the edge co-ordinates(in form of 'x' 'y' pair) :\n";
	while(m--)
	{
		cin>>a>>b;
		grp.addEdge(a,b);
	}
	if(grp.checkBipartite())
	cout<<"Bipartite\n";
	else
	cout<<"Not Bipartite\n";
	return 0;
}
