#include<bits/stdc++.h>
#include<iostream>
#define test int t;scanf("%d",&t);fflush(stdin);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll ll
using namespace std;
int chainNo=0,parent[10001],chainHead[10001],chainPos[10001],chainInd[10001],chainSize[10001],count=0;
bool visited[10001];

void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=a[start].first;
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
}
void Postorder(int node)
{
	visited[node]=true;
	loop(i,0,grph[node].size())
	{
		if(!visited[grph[node][i].first])
		{
			parent[grph[node][i].first]=node;
			Postorder(grph[node][i].first);
		}
	}
	count++;
	subtree_size[node]=count;	
}
void hld(int cur)
{
	if(chainHead[chainNo]==-1) 
	chainHead[chainNo]=cur;
	chainInd[cur]=chainNo;
	chainPos[cur]=chainSize[chainNo];
	chainSize[chainNo]++;
	int ind=-1,mai=-1;
	visited[cur]=true;
	loop(i=0;i<grph[cur].size();i++){
		if(!visited[grph[cur][i].first]&&subtree_size[grph[cur][i].first] >mai)
		{
			mai=subtree_size[grph[cur][i].first];
			ind=i;
		}
	}
	if(ind>=0)
	hld(adj[cur][ind].first);
	loop(i=0;i<grph[cur].size();i++)
	{
		if(i!=ind)
		{
			chainNo++;
			hld(grph[cur][i].first);
		}
	}
}
int query_tree(int u,int v)
{
	int lca=LCA(u,v);
}
int query(int u,int v)
{
	int uchain=chainInd[u],vchain=chainInd[v],cur=0,ans=-1;
	while(1)
	{
		if(uchain==vhain)
		{
			cur=query_tree(u,v);
			if(cur>ans)
			ans=cur;
			break;
		}
		cur=query_tree(u,chainHead[uchain]);
		if(cur>ans)
		ans=cur;
		u=chainHead[uchain];
		u=parent[u];
		uchain=chainInd[u];
	}
	return ans;
}
/*int query_up(int u,int v)
{
	int uchain=chainInd[u],vchain=chainInd[v],ans=-1;
	while(1)
	{
		if(uchain==vchain)
		{
			int cur=query_tree(1,0,ptr,posInBase[v]+1,posInBase[u]+1);
			if(cur>ans)
			ans=cur;
			break;
		}
		int cur=query_tree(1,0,ptr,posInBase[chainHead[uchain]],posInBase[u]+1);
		if(cur>ans)
		ans=cur;
		u=chainHead[uchain];
		u=parent[u];
	}
	return ans;
}*/
int main()
{
	test
	{
		string s;
		int n;scanf("%d",&n);
		loop(i,0,n-1)
		{
			scanf("%d%d%d",&a,&b,&c);
			grph[a].push_back(make_pair(b,c));
			grph[b].push_back(make_pair(a,c));
			chainHead[i]=-1;
		}
		chainHead[n-1]=-1;
		cin>>s;
		do
		{
			scanf("%d%d",&a,&b);
			if(s.equals("QUERY"))
			{
				
			}
			else
			{
				
			}	
			cin>>s;
		}while(!s.equals("DONE"));
	}
	return 0;
}
