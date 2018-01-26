#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int v;
	list<int> *adj;
	int* indeg;
	public:	
		Graph(int n)
		{
			v=n;
			adj=new list<int>[n];
			indeg=new int[n];
			for(int i=0;i<n;i++)
			indeg[i]=0;
		}
		void addEdge(int a,int b)
		{
			adj[a].push_back(b);
			indeg[b]++;
		}
		void print(vector<int> res)
		{
			for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
			cout<<endl;
		}
		void print(queue<int> que)
		{
			cout<<"Queue is : ";
			while(!que.empty())
			{
				cout<<que.front()<<" ";
				que.pop();
			}
			cout<<"\n";
		}
		void allTopo(queue<int> que1,vector<int>& res)
		{
			int k=que1.size(),x,y;
			queue<int> que;
		//	print(res);
			while(k--)
			{
				que=que1;
				x=que.front();
				res.push_back(x);
				que.pop();
				indeg[x]=-1;
				list<int>::iterator i;
				for(i=adj[x].begin();i!=adj[x].end();i++)
				{
					indeg[*i]-=1;
					if(indeg[*i]==0)
					que.push(*i);
				}
				//print(que);
				//print(res);
				allTopo(que,res);
				que.push(x);
				if(res.size()==v)
					print(res);
				res.erase(res.end()-1);
				indeg[x]=0;
				for(i=adj[x].begin();i!=adj[x].end();i++)
				{
					indeg[*i]+=1;
				}
				y=que1.front();
				que1.pop();
				que1.push(y);
			}
		}
		void TopologicalSort()
		{
			queue<int> que;
			vector<int> result;
			int x;
			for(int j=0;j<v;j++)
			{
			//	cout<<j<<" "<<indeg[j]<<"\n";
				if(indeg[j]==0)
				que.push(j);
			}
			allTopo(que,result);
		}
};
int main()
{
	Graph grp(6);
	grp.addEdge(5,0);
	grp.addEdge(4,0);
	grp.addEdge(4,1);
	grp.addEdge(3,1);
	grp.addEdge(5,2);
	grp.addEdge(2,3);
	grp.TopologicalSort();
	/*for(int i=0;i<6;i++)
	{
		cout<<sorted.front()<<" ";
		sorted.pop();
	}*/
	return 0;
}
