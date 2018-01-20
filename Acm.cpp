#include<bits/stdc++.h>
#include<iostream>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,hrs=0,crs=0;
		cin>>n>>m;
		if(n==1){cout<<"0\n";continue;}
		ll prod=(n-1)*m,cnt=1,prod1=0;int k=0;
		//cout<<prod<<endl;
		while(true)
		{
			hrs+=1;
			prod1+=cnt;
			crs+=k;
			k=(k+1)%2;
			if(k==0&&cnt<n/2&&crs<m)
			{
				cnt++;
			}
			if(prod1==prod/2)
			{
				//cout<<"abhi"<<prod1<<prod<<prod/2<<cnt<<endl;
				break;
			}
			if(prod1>prod/2)
			{
				hrs-=1;
				break;
			}
		}
		hrs=hrs*2;
		if(prod%2!=0)
		hrs+=1;
		cout<<hrs<<endl;
	}
	return 0;
}
