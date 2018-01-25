#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long long int
#define pll pair<ll ,ll>
#define MOD 100000000
using namespace std;
int main()
{
	test
	{
		int cost[27],freq[26];
		loop(i,0,26)
		scanf("%d",&cost[i]);
		loop(j,0,26)
		freq[j]=0;
		string s;
		cin>>s;
		loop(i,0,s.length())
		{
			freq[s[i]-'a']++;
		}
		ll price=0;
		loop(i,0,26)
		{
			if(freq[i]==0)
			price=price+cost[i];
		}
		printf("%lld\n",price);
	}
	return 0;
}
