#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long long int
#define pli pair<ll ,int>
using namespace std;
ll stalls[100007];
int n,c;
int binarySearch(int point)
{
	int start=1,end=n,mid,last=-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(stalls[mid]>point)
		{
			last=mid;
			end=mid-1;
		}
		else if(stalls[mid]<point)
		start=mid+1;
		else
		return mid;
	}
	return last;
}
bool check(ll d)
{
	//printf("    IN CHECK FOR VALUE  : %d\n",d);
	ll nextPoint=stalls[1]+d,cows=c-1,i;
	while(cows!=0)
	{
		i=binarySearch(nextPoint);
		//printf(" <%lld , %lld >,",nextPoint,stalls[i]);
		if(i!=-1)
		{
			cows--;
			nextPoint=stalls[i]+d;
		}
		else
		return false;
	}
	return true;
}

int main()
{
	test
	{
		scanf("%d%d",&n,&c);
		loop(i,1,n+1)
		scanf("%lld",&stalls[i]);
		sort(stalls,stalls+n);
		ll start=1,end=stalls[n]-stalls[1],mid,ans;
		//printf("start = %lld end = %lld\n",start,end);
		while(start<=end)
		{
			mid=(start+end)/2;
			//printf("Checking for mid  = %lld\n",mid);
			if(check(mid))
			{
			//	printf("true for diff = %lld\n",mid);
				ans=mid;
				start=mid+1;
			}
			else
			end=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
