#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i+=2)
#define pii pair<int,long int>
#define ll unsigned long long int
#define pll pair<ll ,ll>
#define MOD 100000000
using namespace std;
int main()
{
	test
	{
		int n;
		ll k,index,z;
		scanf("%d%lld",&n,&k);
		if(n==1)
		{
			if(k==0)
			printf("0\n");
			else
			printf("1\n");
			
		}
		else if(n==2)
		{
			if(k==0)
			printf("0\n");
			else if(k==2)
			printf("1\n");
			else if(k==3)
			printf("3\n");
			else
			printf("2\n");
		}
		else
		{
			index=k%(1<<n-2);
		//		printf("index = %lld\n",index);
			z=index;
			if(k%2==0)
			index=index/2;
			else
			index=index/2+(1<<n-3);
		//	printf("index = %lld\n",index);
			//if(n==3&&k%2!=0)
			//index-=1;
			if(index>0)
			index=(index)*4;
			if(k==z)
			index=index;
			else if(k==z+(1<<n-1))
			index=(index+1);
			else if(k==z+(1<<n-2))
			index=(index+2);
			else
			index=(index+3);
			printf("%lld\n",(index));
		}
	}
}
