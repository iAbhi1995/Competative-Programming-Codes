#include<bits/stdc++.h>
#include<iostream>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
using namespace std;
int main()
{
	test
	{
		//fflush(stdin);
		int cnt=1,maxm=1,x=0;
		string s;
		cin>>s;
		char prev=s[0];
		loop(i,1,s.length())
		{
			if(s[i]=='='){
			x++;continue;}
			//printf("%c %c\n",s[i],prev);
			if(s[i]!=prev)
			{
			//		printf("CNT: %d\n",cnt);
				if(cnt>maxm)
				maxm=cnt;
				cnt=0;
			}
			cnt++;
			prev=s[i];
		}
	//	printf("%d %d",x,s.length());
		if(s.length()==x+1&&s[0]=='=')
		maxm=0;
		else if(cnt>maxm)
			maxm=cnt;
		printf("%d\n",maxm+1);
	}
	return 0;
}
