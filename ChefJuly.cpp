#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define pli pair<long int,int>
using namespace std;
int main()
{
	test
	{
		long long int n,b,x1,x2,total=0,total1=0;
		scanf("%lld%lld",&n,&b);
		int start=0,end=n,mid=0,t2,t1,t3;
		if(n<=b)
		{
			printf("0\n");
			continue;
		}
		x1=n/2;
		x2=n-n/2;
		//printf("%ld %ld\n",x1,x2);
		if(x2>=b)
		{
			total=(x1+(x2%b))*(x2-(x2%b))/b;
			total1=(n-(x2/b+1)*b)*(x2/b+1);
			if(total1>total)
			total=total1;
		}
		else
		total=(n-b);
		printf("%lld\n",total);
	}
	return 0;
}
/*
3
10 2
8 5
6 1
*/
