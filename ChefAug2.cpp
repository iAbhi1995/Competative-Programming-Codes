#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define pii pair<int,long int>
#define pli pair<long int,int>
#define ll long long int
using namespace std;
int main()
{
	test
	{
		 ll n,d,x,sum=0,factor,sumx=0;
		 scanf("%lld%lld",&n,&d);
		 vector<ll> a;
		 loop(i,0,n)
		 {
		 	scanf("%lld",&x);
		 	sum=sum+x;
		 	a.push_back(x);
		 }
		 if(sum%n!=0)
		 {
		 	printf("-1\n");
		 	continue;
		 }
		 factor=sum/n;
		 x=0;
		 loop(i,0,d)
		 {
		 	ll j=i,cnt=0,score=0;
		 	while(j<n)
		 	{
			 	sumx+=a[j];
			 	a[j]+=score;
			 	score=a[j]-factor;
			 	x+=abs(score);
				j+=d;
				cnt++;
			}
			if(sumx/cnt!=factor)
			{
				printf("-1\n");
				x=-11;
				break;
			}
			sumx=0;
		 }
		 if(x==-11)
		 continue;
		 printf("%lld\n",x);
	}
	return 0;
}
