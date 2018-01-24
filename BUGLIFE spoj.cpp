#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<utility>
#include<algorithm>
#include<string>
#define test int t;scanf("%d",&t);int temp=t;while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
bool visited[2001];
int cnt[2001];
vector<int> grph[2002];
bool DFScycle(int x,int parent,int length)
{
	visited[x]=1;
	cnt[x]=length;
	loop(i,0,grph[x].size())
	{
		if(!visited[grph[x][i]]){
			//printf("%d %d %d %d %d\n",x,grph[x][i],parent,length,grph[x].size());
			if(DFScycle(grph[x][i],x,length+1))
			return true;
		}
		else if(grph[x][i]!=parent&&parent!=-1&&(length+1-cnt[grph[x][i]])%2!=0)
		{
			//printf("%d %d %d %d %d In else if\n",x,grph[x][i],parent,length);
			return true;
		}
		
	}
	loop(i,0,2001)
	cnt[i]=0;
	return false;
}

int main()
{
	test
	{
		int bugs,intrct,x,y;
		scanf("%d%d",&bugs,&intrct);
		while(intrct--)
		{
			scanf("%d%d",&x,&y);
			grph[x].push_back(y);
			grph[y].push_back(x);
		}
		/*loop(i,1,bugs+1)
		{
			
			loop(j,0,grph[i].size())
				printf("%d ",grph[i][j]);
			printf("\n");
		}*/
		int i;
		for(i=1;i<bugs+1;i++)
		{
			if(visited[i]!=1)
			{
			//	printf("Not visited%d\n",i);
			if(DFScycle(i,-1,0))
			{
				printf("Scenario #%d:\nSuspicious bugs found!\n",temp-t);
				break;
			}
			}
		}
		if(i==bugs+1)
		printf("Scenario #%d:\nNo suspicious bugs found!\n",temp-t);
		loop(j,1,bugs+1)
		{
			grph[j].clear();
			visited[j]=false;
		}
	}
	return 0;
}
