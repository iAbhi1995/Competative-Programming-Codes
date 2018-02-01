#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define ll long long int
#define pll pair<ll ,ll>
#define MOD 1000000007
using namespace std;
ll tree[200007],lazy[200007];
void build(int node, int start, int end)
{
    if(start == end)
    {
        //tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void updateRange(int node, int start, int end, int l, int r)
{
    if(lazy[node] != 0)
    { 
        tree[node] += (end - start + 1) * lazy[node];  
        if(start != end)
        {
            lazy[node*2] += lazy[node];                
            lazy[node*2+1] += lazy[node];              
        }
        lazy[node] = 0;                                
    }
    if(start > end or start > r or end < l)            
        return;
    if(start >= l and end <= r)
    {
        tree[node] += (end - start + 1);
        if(start != end)
        {
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r); 
    updateRange(node*2 + 1, mid + 1, end, l, r);  
    tree[node] = tree[node*2] + tree[node*2+1];       
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;       
    if(lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];            
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
   }
    if(start >= l and end <= r)        
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);     
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int main()
{
	test
	{
		memset(tree,0,sizeof(tree));
		int t,n,m,l,r,z=0;
		scanf("%d%d",&n,&m);
		vector<pii > query[m];
		while(m--)
		{
		//	printf("Enter the values t l r %d",m);
			scanf("%d%d%d",&t,&l,&r);
			if(t==1)
			{
				updateRange(1,1,n,l,r);
				query[z].push_back(make_pair(l,r));
			}
			else
			{
				loop(i,l-1,r)
				{
					loop(j,0,query[i].size())
					{
						query[z].push_back(make_pair(query[i][j].first,query[i][j].second));
						updateRange(1,1,n,query[i][j].first,query[i][j].second);
					}
				}
			}
			z++;
		}
		loop(i,1,n+1)
			printf("%lld ",queryRange(1,1,n,i,i)%MOD);
		printf("\n");
	}
	return 0;
}
