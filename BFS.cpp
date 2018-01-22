#include<stdio.h>
#include<vector>
#include<math.h>
#include<queue>
#include<utility>
#include<algorithm>
#define test int t;scanf("%d",&t);
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[17];
bool visited[9];
void display(queue<int> q)
{
	printf("Elements are :");
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
	}
	printf("\n");
}
int main()
{
	int pos[17][4]={{0,0,0,0},{2,3,5,9},{1,4,6,10},{1,4,7,11},{2,3,8,12},{1,6,7,13},{2,5,8,14},
	{3,5,8,15},{4,6,7,16},{1,10,11,13},{2,9,12,14},{3,9,12,15},{4,10,11,16},{5,9,14,15},
	{6,10,13,16},{7,11,13,16},{8,12,14,15}};
	test
	loop(z,1,t+1)
	{
		vector<int> p,q;
		loop(i,1,17)
		{
			scanf("%d",a+i);
			if(i<=8&&a[i]==1)
			p.push_back(i);
			else if(i>8&&a[i]==0)
			q.push_back(i);
		}
		if(p.size()==0&&q.size()==0)
		{
			printf("Case #%d: 0\n",z);
			continue;
		}
		int temp1,temp2,cnt=0;
		loop(i,0,p.size())
		{
			queue<int> q1,q2,q3,q4;
			q1.push(p[i]);
			q2.push(pos[p[i]][3]);
			cnt++;
			//display(q2);
			if(a[q2.front()]==0)
			{
			//	cnt++;
			//	printf("Continuing 1\n");
				continue;
			}
			while(!q1.empty())
			{
				temp1=q1.front();
				temp2=q2.front();
			//	display(q2);
				q1.pop();q2.pop();
				if(a[temp2]==0&&a[temp1]==0)
				{
					a[temp2]=1;
					a[p[i]]=0;
			//		printf("Breaking 1\n");
					break;
				}
				else
				{
					loop(j,0,3)
					if(!visited[pos[temp1][j]])
					{
			//			printf("%d pushing ",pos[pos[temp1][j]][3]);
						q3.push(pos[temp1][j]);
						visited[pos[temp1][j]]=1;
						q4.push(pos[pos[temp1][j]][3]);
					}
				//	printf("\n");
				}
				if(q1.empty()&&!q3.empty())
				{
					cnt++;
					q1=q3;
					q2=q4;
					queue<int> q5,q6;
					swap(q3,q5);
					swap(q4,q6);
				}
				
				//printf("%d\n",cnt);
				visited[temp2]=visited[temp1]=1;
				if(cnt>3){
			//		printf("Breaking 2\n");
					break;
				}
			}
			
			loop(j,1,9)
			visited[j]=0;
			if(cnt>3){
			//	printf("Breaking 3\n");
				break;
			}
		}
		if(cnt>3)
		printf("Case #%d: more\n",z);
		else
		printf("Case #%d: %d\n",z,cnt);
	}
	return 0;
}
