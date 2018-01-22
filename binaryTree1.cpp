#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> a(n+1,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x==0)
			a[i+1].push_back(-1);
			else
			a[x].push_back(i+1);
		}
		
	}
	return 0;
}
