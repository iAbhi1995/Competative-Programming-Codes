#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define ll long int
#define pll pair<ll ,ll>
using namespace std;
int main()
{
	test
	{
		int n,k=0,front,rear;
		printf("Enter the number\n");
		scanf("\n%d",&n);
		int a[n+1],cnt=0;
		loop(i,0,n)
		{
			scanf("%d",a+i);
			if(a[i]==1)
			k++;
		}
		printf("%d\n",n);
		loop(i,0,k)
		{
			if(a[i]==1)
			cnt++;
		}
		printf("cnt = %ld\n",cnt);
		front=0;rear=n;ll minm=k-cnt;
		loop(i,k,n)
		{
			if(k-cnt<minm)
			{
				minm=k-cnt;
			}
			if(a[i-k]==1)
			cnt--;
			if(a[i]==1)
			cnt++;
			if(cnt<0)
			cnt=0;
		}
		printf("minm = %ld\n",minm);
	}
	return 0;
}
