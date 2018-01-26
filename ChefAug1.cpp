#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(i=a;i<b;i++)
#define pii pair<int,long int>
#define pli pair<long int,int>
using namespace std;
int main()
{
	test
	{
		int n,i;
		scanf("%d",&n);
		int a[n],freq[10];
		memset(freq,0,sizeof(freq));
		loop(i,0,n)
			scanf("%d",&a[i]);
		int d=n-n/2-1;
		loop(i,n/2,n)
		{
			if(a[i]!=a[d])
			{
				d=-11;
				break;
			}
			freq[a[i]]=1;
			d--;
		}
		if(d==-11){
			printf("no\n");
			continue;
		}
		loop(i,1,8)
		if(freq[i]!=1)
		{
			break;
		}
		if(i==8)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
