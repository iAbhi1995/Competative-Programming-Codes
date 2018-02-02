#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<utility>
#include<cstring>
#include<algorithm>
#include<string>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	int source,goal,n,temp;
	test
	{
		scanf("%d",&n);
		int a[n][n];
		loop(i,0,n)
			loop(j,0,n)
				scanf("%d",&a[i][j]);
		int dist[n]={-1},newDis=0;
		queue<int> que;
		que.push(source);
		dist[source]=0;
		while(!que.empty()&&temp!=goal)
		{
			temp=que.front();
			que.pop();
			loop(i,0,n)
			{
				if(a[temp][i]!=0)
				{
					newDis=dist[temp]+a[temp][i];
					if(newDis<dist[i])
					dist[i]=newDis;	
				}
			}
		}
		printf("%d\n",dist[goal]);
	}
	return 0;
}
