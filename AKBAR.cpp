#include<vector>
#include<stdio.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define test int t;scanf("%d",&t);while(t--)
using namespace std;
vector<int> grph[1000001];
int protect[1000001],flag,visited[1000001];
void assign_protection(int strng,int node)
{
	printf("Inside assign protection %d  %d\n",node,strng);
	if(strng==0)
	{
		if(protect[node]>1)
		flag=1;
		protect[node]++;
		return;
	}
	loop(i,0,grph[node].size())
	{
		if(visited[node]==0){
			visited[node]=1;
			assign_protection(strng-1,grph[node][i]);
			visited[node]=0;
		}
	}
}
int main()
{
	test
	{
		int n,r,m,k,s;
		scanf("%d%d%d",&n,&r,&m);
		while(r--)
		{
			scanf("%d%d",&k,&s);
			grph[k].push_back(s);
			grph[s].push_back(k);
		}
		for(int i=0;i<n;i++){
		for(int j=0;j<grph[i].size();j++)
		printf("%d ",grph[i][j]);
		printf("\n");
		}
		while(m--)
		{
			scanf("%d%d",&k,&s);
			if(flag==0)
			assign_protection(s,k);
		}
		if(flag==1)
		printf("No\n");
		else
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		printf("%d",protect[i]);
		printf("\n");
		flag=0;
		for(int i=1;i<=n;i++){
		grph[i].clear();
		protect[i]=0;
		}
	}
	return 0;
}
