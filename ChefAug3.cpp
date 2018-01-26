#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long long int
#define pli pair<ll ,int>
using namespace std;
int main()
{
	test
	{
		int n,m,y,placed=0,notTaken=0;
		ll x,totalSal=0;
		scanf("%d%d",&n,&m);
		vector<ll> minSal,offeredSal,maxJobOffer;
		bool visited[m];
		memset(visited,false,m);
		loop(i,0,n)
		{
			scanf("%lld",&x);
			minSal.push_back(x);
		}
		loop(i,0,m)
		{
			scanf("%lld%d",&x,&y);
			offeredSal.push_back(x);
			maxJobOffer.push_back(y);
		}
		priority_queue<pli > qual[n];
		string s;
		loop(i,0,n)
		{
			cin>>s;
			loop(j,0,m)
			{
				if(s[j]=='1')
				qual[i].push(make_pair(offeredSal[j],j));
			}
		}
		loop(i,0,n)
		{
			while(!qual[i].empty())
			{
				y=qual[i].top().second;
			//	printf("%lld %lld\n",offeredSal[y],minSal[i]);	
				if(maxJobOffer[y]>0&&qual[i].top().first>=minSal[i])
				{
					totalSal+=qual[i].top().first;
					placed++;
					visited[y]=true;
					maxJobOffer[y]--;
				//	printf("%d placed in %d with package %lld and now MAxJOBOffer =%lld\n",
						//	i,y,qual[i].top().first,maxJobOffer[y]);
					break;
				}
				qual[i].pop();
			}
		}
		loop(i,0,m)
		if(!visited[i])
		notTaken++;
		printf("%d %lld %d\n",placed,totalSal,notTaken);
	}
	return 0;
}
