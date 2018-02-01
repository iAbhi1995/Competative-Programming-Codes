#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
using namespace std;
int findsteps(int coin[],int value,int n)
{
	int T[value+1],loc[value+1];T[0]=loc[0]=0;
	loop(i,1,value+1)
	T[i]=MOD;
	loop(j,0,n)
	{
		loop(i,1,value+1)
		{
			//printf("%d ",i);
			if(i>=coin[j]&&T[i-coin[j]]+1<T[i])
			{
				T[i]=T[i-coin[j]]+1;
				loc[i]=j;
			}
		}
		loop(i,0,value+1)
		cout<<T[i]<<" ";
		printf("\n");
	}

	return T[value];
}
int main()
{
	int y=10,m=2;
	y-=m<3;
	printf("%d \n",y);
	int n,value;
	cin>>n;
	int coin[n];
	loop(i,0,n)
	scanf("%d",&coin[i]);
	scanf("%d",&value);
	printf("%d",findsteps(coin,value,n));
	return 0;
}
