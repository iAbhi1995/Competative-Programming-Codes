#include<bits/stdc++.h>
#include<iostream>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll ll
using namespace std;
int BIT[100001][27];
string s;int n;
void update(int x,int val,int pos)
{
	for(;x<=n;x+=x&-x)
		BIT[x][pos]+=val;	
}
int query(int x,int pos)
{
	int sum=0;
	for(;x>0;x-=x&-x)
	sum+=BIT[x][pos];
	return sum;
}
int main()
{
		int q,l,r,type,odd=0;
		scanf("%d%d",&n,&q);
		//loop(i,0,n+1)
		//BIT[i][j]=0;
		cin>>s;
		loop(i,0,s.length())
		{
			update(i+1,1,s[i]-'a');
		}
		char ch;
		while(q--)
		{
			printf("Enter the values: %d\n",q);
			scanf("%c",&ch);
			scanf("%d%d%d",&type,&l,&r);
			if(type==1)
			{
				update(l,-1,s[l]-'a');
				update(l,1,r-97);
			}
			else
			{
				int res=0,odd=0;
				loop(i,0,26)
				{
					res=query(r,i)-query(l-1,i);
					printf("%d ",res);
					if(res%2)
					{
						odd++;
					}
				}
				printf("\n");
				if(odd<=1)
					printf("yes\n");
				else
					printf("no\n");
			}	
		}
	return 0;
}
