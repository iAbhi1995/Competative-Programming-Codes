#include<stdio.h>
#include<vector>
#include<math.h>
#include<queue>
#include<utility>
#include<algorithm>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int indegree[100001];
vector<int> grph[100001];
void display(priority_queue<int, vector<int>, greater<int> > p)
{
	printf("Priority Queue is: ");
	while(!p.empty()){
		printf("%d ",p.top());
		p.pop();
	}
	printf("\n");
}
int main()
{
	test
	{
		int n1,n2,d,x,y,disc,minVertex=100001;
		scanf("%d%d%d",&n1,&n2,&d);
		while(d--)
		{
			scanf("%d%d",&x,&y);
			indegree[x]++;
			grph[y].push_back(x);
			if(minVertex>y)
			minVertex=y;
		}
		printf("minVertex=%d\n",minVertex);
		priority_queue<int, vector<int>, greater<int> > pQue ,pQue2;
		loop(i,1,n1+n2+1){
			if(indegree[i]==0){
			pQue.push(i);
		}
			printf("%d %d\n",pQue.size(),i);
		}
		printf("\n");
		if(minVertex>n1)
		disc=2;
		else
		disc=1;
		int cnt=1;
		display(pQue);
        while(!pQue.empty())
        {
        	int x=pQue.top();
        	pQue.pop();
        	if(!(x-n1<0&&disc==1))
			{
				printf("In the continuing 1 %d\n",x);
				pQue2.push(x);
        		continue;
        	}
        	else if(!(x-n1>0&&disc==2))
        	{
        		printf("In the continuing 2 %d\n",x);
        		pQue2.push(x);
        		continue;
			}
        	loop(i,0,grph[x].size())
        	{
        		indegree[grph[x][i]]--;
        		if(indegree[grph[x][i]]==0)
        		pQue.push(grph[x][i]);
			}
			if(pQue.empty()&&!pQue2.empty())
			{
				printf("In the increasing condition");
				pQue=pQue2;
				disc=3-disc;
				pQue =priority_queue<int, vector<int>, greater<int> >();
				cnt++;
			}	
		}
		cnt+=1;
		printf("%d\n",cnt);
	}
	return 0;
}
