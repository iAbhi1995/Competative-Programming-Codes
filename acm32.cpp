#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> a[3],temp;
		int big1=0,big2=0,big3=0,x;
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			cin>>x;
			a[i].push_back(x);
		}
		for(int j=0;j<2;j++)
		for(int i=0;i<2-j;i++)
		{
			if(a[i][0]<a[i+1][0])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		
		for(int i=0;i<3;i++)
		{
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
		
		if(a[0][1]>=a[1][1]&&a[0][2]>=a[1][2])
		if(a[1][1]>=a[2][1]&&a[1][2]>=a[2][2])
		big1=1;
		
		for(int j=0;j<2;j++)
		for(int i=0;i<2-j;i++)
		{
			if(a[i][1]<a[i+1][1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		if(a[0][0]>=a[1][0]&&a[0][2]>=a[1][2])
		if(a[1][0]>=a[2][0]&&a[1][2]>=a[2][2])
		big2=1;
		for(int j=0;j<2;j++)
		for(int i=0;i<2-j;i++)
		{
			if(a[i][2]<a[i+1][2])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		if(a[0][1]>=a[1][1]&&a[0][0]>=a[1][0])
		if(a[1][1]>=a[2][1]&&a[1][0]>=a[2][0])
		big3=1;
		
		if(big1==0||big2==0||big3==0)
		cout<<"no\n";
		else
		cout<<"yes\n";
		
	}
	return 0;
}
