#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long long int
#define pli pair<ll ,int>
using namespace std;
int a[100001];
int main()
{
	int n,q,i,k,L,R,X;
	scanf("%d%d",&n,&q);
	loop(j,1,n+1)
	{
		scanf("%d",&a[j]);
	}
	while(q--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d",&i,&k);
			loop(p,i+1,i+101)
			{
			    if(p>n||k==0)
			    break;
				if(a[p]>a[i])
				{
					i=p;
					k--;
				}
			}
			printf("%d\n",i);
		}
		else
		{
			scanf("%d%d%d",&L,&R,&X);
			loop(j,L,R+1)
			{
				a[j]=a[j]+X;
			}
		}
	}
}
