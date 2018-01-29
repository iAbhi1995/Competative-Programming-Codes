#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
using namespace std;
void display(priority_queue<pii > que)
{
	while(!que.empty())
	{
		printf("%d %d, ",que.top().first,que.top().second);
		que.pop();
	}
	printf("\n");
}
int main()
{
	test
	{
		int n,d,n1,d1,s1;
		long long int total=0;
		scanf("%d%d",&n,&d);
		vector<pii > teacher[d+1];
		loop(i,0,n)
		{
			scanf("%d%d%d",&d1,&n1,&s1);
			teacher[d1].push_back(make_pair(s1,n1));
		}
		priority_queue<pii > que;
		loop(i,1,d+1)
		{
			loop(j,0,teacher[i].size())
				que.push(teacher[i][j]);
			if(que.empty())
			continue;
			s1=que.top().first;
			n1=que.top().second;
			que.pop();
			n1-=1;
			if(n1)
			que.push(make_pair(s1,n1));
		}
	//	display(que);	
		while(!que.empty())
		{
			total+=que.top().first*que.top().second;
			que.pop();
		}
		printf("%lld\n",total);
	}
	return 0;
}
