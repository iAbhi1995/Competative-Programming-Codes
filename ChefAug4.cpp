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
	string p,q;
	int a[27],b[27],i,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>p>>q;
	loop(i,0,p.length())
	{
	a[p[i]-'a']++;
	b[q[i]-'a']++;
	}
	loop(i,0,26)
	{
		//printf("%c %d %d\n",97+i,a[i],b[i]);
		if(a[i]>1)
		{
			if(b[i]<1)
			   break;
		}
	}
	bool subset=true,exactly=true;
	loop(j,0,26)
	{
		//printf("%c %d %d\n",97+j,a[j],b[j]);
		if(a[j]>=1&&b[j]>=1)
		subset=true;
		else if(b[j]==0&&a[j]!=0)
		exactly=false;
		else if(a[j]==0&&b[j]!=0)
		{
			//printf("%d",j);
			exactly=false;subset=false;break;
		}
	}
	if(!exactly&&subset)
	{
		printf("A\n");continue;
	}
	if(i==26||exactly)
	printf("B\n");
	else
	printf("A\n");
	}
	return 0;
}

