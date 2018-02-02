#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<utility>
#include<algorithm>
#include<string>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) int i;for(i=a;i<b;i++)
using namespace std;
int main()
{
	test
	{
		int cntU=0,cntD=0,cnt=0;
		string s;
		cin>>s;
		loop(i,1,s.length())
		{
			if(s[i-1]=='U'&&s[i]=='D'){
			cntU++;
			cnt=0;
		}	
			else if(s[i-1]=='D'&&s[i]=='U'){
			cnt=0;
			cntD++;
			}
			cnt++;
		}
		if(cnt!=0)
		{
			if(s[i-1]=='D')
			cntD++;
			else
			cntU++;
		}
		cout<<min(cntU,cntD)<<"\n";
	}
	return 0;
}
