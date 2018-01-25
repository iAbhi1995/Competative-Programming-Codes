#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define pii pair<int,int>
#define ll long long int
#define pll pair<ll ,ll>
using namespace std;
ll a[200001];
int main()
{
	test
	{
		ll n;
		scanf("%lld",&n);
		ll index=1;ll sufSum=0,preSum=0,minm=0;
		loop(i,1,n+1)
		{
			scanf("%lld",a+i);
			sufSum=sufSum+a[i];
		}
		preSum=a[1];
		minm=sufSum+preSum;
		loop(i,2,n+1)
		{
			preSum+=a[i];
			sufSum-=a[i-1];
			if(preSum+sufSum<minm)
			{
				minm=preSum+sufSum;
				index=i;
			}	
		}
		printf("%lld\n",index);
	}
	return 0;
}
