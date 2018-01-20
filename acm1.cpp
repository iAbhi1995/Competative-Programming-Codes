#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,x;
	cin>>t;
	while(t--)
	{
		vector<int> a,b,c;
		for(int j=0;j<3;j++)
		{
			cin>>x;
			a.push_back(x);
		}
		for(int j=0;j<3;j++)
		{
			cin>>x;
			b.push_back(x);
		}
		for(int j=0;j<3;j++)
		{
			cin>>x;
			c.push_back(x);
		}
		int x,y,z,big1=0,big2=0,big3=0;
		x=a[0]-b[0];
		y=a[1]-b[1];
		z=a[2]-b[2];
		if(x==0&&y==0&&z==0)
		big1=0;
		else if((x==0&&y==0)||(x==0&&z==0)||(y==0&&z==0))
		{
			if(x<0||y<0||z<0)
			big1=2;
			else
			big1=1;
		}
		else if(x==0||y==0||z==0)
		{
			if((x<0&&y<0)||(x<0&&z<0)||(y<0&&z<0))
			big1=2;
			else if((x>0&&y>0)||(x>0&&z>0)||(y>0&&z>0))
			big1=1;
		}
		else if(x<0&&y<0&&z<0)
		{
			big1=2;
		}
		else if(x>0&&y>0&&z>0)
		big1=1;
		
		x=b[0]-c[0];
		y=b[1]-c[1];
		z=b[2]-c[2];
		if(x==0&&y==0&&z==0)
		big2=0;
		else if((x==0&&y==0)||(x==0&&z==0)||(y==0&&z==0))
		{
			if(x<0||y<0||z<0)
			big2=3;
			else
			big2=2;
		}
		else if(x==0||y==0||z==0)
		{
			if((x<0&&y<0)||(x<0&&z<0)||(y<0&&z<0))
			big2=3;
			else if((x>0&&y>0)||(x>0&&z>0)||(y>0&&z>0))
			big2=2;
		}
		else if(x<0&&y<0&&z<0)
		{
			big2=3;
		}
		else if(x>0&&y>0&&z>0)
		big2=2;
		
		x=c[0]-a[0];
		y=c[1]-a[1];
		z=c[2]-a[2];
		if(x==0&&y==0&&z==0)
		big3=0;
		else if((x==0&&y==0)||(x==0&&z==0)||(y==0&&z==0))
		{
			if(x<0||y<0||z<0)
			big3=1;
			else
			big3=3;
		}
		else if(x==0||y==0||z==0)
		{
			if((x<0&&y<0)||(x<0&&z<0)||(y<0&&z<0))
			big3=1;
			else if((x>0&&y>0)||(x>0&&z>0)||(y>0&&z>0))
			big3=3;
		}
		else if(x<0&&y<0&&z<0)
		{
			big3=1;
		}
		else if(x>0&&y>0&&z>0)
		big3=3;
		
		if(big1==0||big2==0||big3==0)
		{
			cout<<"no\n";
		}
		else
		cout<<"yes\n";
	}
	return 0;
}


