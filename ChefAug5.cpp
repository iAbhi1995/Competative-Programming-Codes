#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long long int
#define pli pair<ll ,int>
using namespace std;
class Node
{
	public:
	int data;int index;
	Node()
	{
		data=0;index=-1;
	}	
};
Node tree[500005];int lazy[500005];

void build(int node, int start, int end,int* A)
{
    if(start == end)
    {
        tree[node].data = A[start];
        tree[node].index = start;
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid,A);
        build(2*node+1, mid+1, end,A);
        tree[node]=(tree[node*2].data > tree[node*2+1].data)?tree[node*2]:tree[node*2+1];
    }
}
void display(int n)
{
	loop(i,1,2*n)
	{
		printf("Node %d : data : %d at index : %d\n",i,tree[i].data,tree[i].index);
	}
}
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        tree[node].data += lazy[node];    
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  
            lazy[node*2+1] += lazy[node];               
        }
        lazy[node] = 0;                                 
    }
    if(start > end || start > r || end < l)             
        return;
    if(start >= l && end <= r)
    {
        tree[node].data +=  val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node]= (tree[node*2].data > tree[node*2+1].data)?tree[node*2]:tree[node*2+1];        // Updating root with max value 
}

Node queryRange(int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l)
	return Node();
	else
	{         
	    if(lazy[node] != 0)
	    {
	        tree[node].data+= (end - start + 1) * lazy[node];            // Update it
	        if(start != end)
	        {
	            lazy[node*2] += lazy[node];         
	            lazy[node*2+1] += lazy[node];    
	        }
	        lazy[node] = 0;                
	    }
	    if(start >= l && end <= r)
		{
			printf("Entering this conditon %d %d  %d \n",tree[node].data,tree[node].index,node);
			return tree[node];
		}
	    int mid = (start + end) / 2;
		printf("start = %d  end = %d mid =%d  l= %d r= %d \n",start,end,mid,l,r);
	    Node p1 = queryRange(node*2, start, mid, l, r);         // Query left child
	    Node p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
	   // printf("P1  : %d %d    P2:  %d %d\n",p1.data,p1.index,p2.data,p2.index);
	    return (p1.data > p2.data)?p1:p2;
	}
}
int main()
{
	int n,q,i,k,L,R,X;
	scanf("%d%d",&n,&q);
	int a[n+1];
	loop(i,1,n+1)
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n,a);
//	display(n);
	while(q--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			Node query;
			scanf("%d%d",&i,&k);
			int j=1;
			while(k&&i+j<=n&&j<100)
			{
				query = queryRange(1,1,n,i,i+j);
				//printf("i = %d j= %d\n",i,i+j);
				printf("%d  at index : %d\n",query.data,query.index);
				if(query.data > a[i] && i!=query.index)
				{
					k--;
					i=query.index;
					j=1;
				}
				else
				j++;
		//		display(n);
			}
		}
		else
		{
			scanf("%d%d%d",&L,&R,&X);
			updateRange(1,1,n+1,L,R,X);
		}
	}
}
