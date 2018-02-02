#include<bits/stdc++.h>
using namespace std;
int lazy[300007];
vector<long int> val;
long int tree[300007];
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node]=val[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = min(tree[node*2],tree[node*2+1]);
    }
}

void updateRange(int node, int start, int end, int l, int r, int val,int x)
{
	if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] +=  lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start>r||start>end||end<l)              // Current segment is not within range [l, r]
        return;
    if(tree[node]>x)
    {
        // Segment is fully within range
        tree[node] += val;
       // cout<<"in update range : "<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    if(start==end)
    return;
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val,x);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val,x);   // Updating right child
    tree[node] = min(tree[node*2],tree[node*2+1]);        // Updating root with max value 
}
long int queryRange(int node, int start, int end, int l, int r)
{
	 //cout<<"In Query : "<<start<<end<<l<<r<<endl;
    if(start > end || start > r || end < l)
       { //cout<<"OutofRange "<<start<<end<<l<<r<<endl;
	   return 10000000000007;}         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start>=l&&end<=r)// Current segment is totally within range [l, r]
    {  //cout<"condition met";
	 return tree[node];}
    int mid = (start + end) / 2;
    long int p1 = queryRange(node*2, start, mid, l, r);   // Query left child
    long int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    p1=min(p1,p2);
    return p1;
}
bool comparePair(const pair<long int,int> a,const pair<long int,int> b)
{
	return a.second<b.second;
}
int main()
{
	int n,m,x;
	vector<pair<long int,int > > pr;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		pr.push_back(make_pair(x,i));
		val.push_back(x);
	}
	sort(val.begin(),val.end());
	sort(pr.begin(),pr.end());
	build(1,0,n-1);
	/*for(int i=1;i<2*n+2;i++)
			cout<<tree[i]<<" ";
			cout<<endl;*/
	cin>>m;
	while(m--)
	{
		cin>>x;
		updateRange(1,0,n-1,0,n-1,-1,x);
	/*	for(int i=1;i<2*n+2;i++)
			cout<<tree[i]<<" ";
			cout<<endl;
		for(int i=1;i<2*n+2;i++)
			cout<<lazy[i]<<" ";
			cout<<endl;*/
	}
	for(int i=0;i<n;i++)
		pr[i].first = queryRange(1,0,n-1,i,i);
		
	sort(pr.begin(),pr.end(),comparePair);
	for(int i=0;i<n;i++)
		cout<<pr[i].first<<" ";
	cout<<"\n";
	return 0;
}
