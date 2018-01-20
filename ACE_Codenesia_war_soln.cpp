#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define pii pair<int,int>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	test
	{
		int n,a,b,c,war,ppl;
		scanf("%d",&n);
		vector<pii > grph[n+1];
		int S[n+1],I[n+1];
		loop(i,1,n)
		{
			scanf("%d%d%d",&a,&b,&c);
			grph[a].push_back(make_pair(b,c));
			grph[b].push_back(make_pair(a,c));
		}
		loop(i,1,n+1)
		scanf("%d",&S[i]);
		loop(i,1,n+1)
		scanf("%d",&I[i]);
		scanf("%d %d",&war,&ppl);
		loop(i,1,n+1)
		if(S[i]<S[war])
		I[i]=0;
		int dist[n+1],vertex,cost;
		bool visited[n+1];
		loop(i,0,n+1)
		{
			dist[i]=INT_MAX;visited[i]=false;
		}
		dist[war]=0;
		I[war]=0;
		priority_queue<pii,vector<pii >,greater<pii > > que;
		que.push(make_pair(0,war));
		while(!que.empty()&&ppl>0)
		{
			vertex=que.top().second;
			cost=que.top().first;
			ppl-=I[vertex];
			que.pop();
			visited[vertex]=true;
			loop(i,0,grph[vertex].size())
			{
				if(!visited[grph[vertex][i].first]&&dist[grph[vertex][i].first]>cost+grph[vertex][i].second)
				{
					dist[grph[vertex][i].first]=cost+grph[vertex][i].second;
					que.push(make_pair(grph[vertex][i].second,grph[vertex][i].first));
				}
			}
		}
		loop(i,1,n)
		printf("%d ",dist[i]);
		printf("\n");
		if(ppl<=0)
		{
			int maxm=0;
		    loop(i,1,n+1)
			if(dist[i]!=INT_MAX && dist[i] > maxm && visited[i])
			maxm=dist[i];
			printf("YES %d\n",maxm);	
		}
		else
		printf("NO -1\n");
	}
	return 0;
}
