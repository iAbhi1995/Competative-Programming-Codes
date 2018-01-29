#include<bits/stdc++.h>
#include<iostream>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long int
using namespace std;
int main()
{
	test
	{
		int n,u,v,m,temp,lca;
		ll c,k,number,xor_value;
		scanf("%d",&n);
		vector<pii > grph[n+1];
		loop(i,0,n-1)
		{
			scanf("%d%d%ld",&u,&v,&c);
			grph[u].push_back(make_pair(v,c));
			grph[v].push_back(make_pair(u,c));
		}
		bool visited[n+1];
		memset(visited,0,n+1);
		ll xor_parent[n+1];
		queue<int> que;int parent[n+1];
		que.push(1);parent[1]=-1;
		while(!que.empty())
		{
			temp=que.front();
			que.pop();
			visited[temp]=1;
			loop(i,0,grph[temp].size())
			{
				number=grph[temp][i].first;
				xor_value=grph[temp][i].second;
				if(!visited[number])
				{
					xor_parent[number]=xor_value;
					que.push(number);
					parent[number]=temp;
				}
			}
		}
		/*loop(i,1,n+1)
		printf("%d, ",parent[i]);
		printf("\n");
		loop(i,1,n+1)
		printf("%d, ",xor_parent[i]);
		printf("\n");
		loop(i,1,n+1)
		printf("%d, ",xor_arr[i]);
		printf("\n");*/
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%ld",&u,&v,&k);
			memset(visited,0,n+1);
			temp=u;
			while(temp!=-1)
			{
				visited[temp]=1;
				temp=parent[temp];
			}
			temp=v;
			c=0;
			while(!visited[temp])
			{
				if(xor_parent[temp]<=k)
				c=c^xor_parent[temp];
				temp=parent[temp];
			}
			number=0;
			lca=temp;
			if(temp==-1)
			lca=1;
			temp=u;
		//	printf("LCA : %d\n",lca);
			while(temp!=lca)
			{
				if(xor_parent[temp]<=k)
				number=number^xor_parent[temp];
				temp=parent[temp];
			}
			xor_value=number^c;
			printf("%ld\n",xor_value);
		}
	}
	return 0;
}
