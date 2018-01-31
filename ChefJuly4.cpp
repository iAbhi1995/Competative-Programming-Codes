#include<bits/stdc++.h>
#include<iostream>
#define test int t;scanf("%d",&t);fflush(stdin);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll ll
using namespace std;
int main()
{
	test
	{
		string s;int space=0,space_arr[2];
		getline(cin,s);
		loop(i,0,s.length())
		{
			char ch=s[i];
			if(s[i]==' ')
			{
				space_arr[space++]=i;
			    continue;
			}
			if(i==0||s[i-1]==' ')
			s[i]=toupper(s[i]);
			else
			s[i]=tolower(s[i]);
		}
		if(space==0)
		cout<<s<<"\n";
		else if(space==1)
		{
			cout<<s[0]<<". ";
			loop(i,space_arr[0]+1,s.length())
			cout<<s[i];
			cout<<"\n";
		}
		else
		{
			cout<<s[0]<<". ";
			cout<<s[space_arr[0]+1]<<". ";
			loop(i,space_arr[1]+1,s.length())
			cout<<s[i];
			cout<<"\n";
		}
	}	
	return 0;
}
