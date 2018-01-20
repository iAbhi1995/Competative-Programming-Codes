#include<iostream>
using namespace std;
int c[1000003],lazy[200007];
void updateInterval(int node,int start,int end,int l,int r)
{
    cout<<"Update Interval "<<start<<" "<<end<<" "<<l<<" "<<r<<"\n";
	if(lazy[node]!=0)
	{
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
			cout<<"Updated value of "<<2*node<<" to "<<lazy[2*node]<<" ";
			cout<<"Updated value of "<<2*node+1<<" to "<<lazy[2*node+1]<<"\n";
		}
		else
    	{
        	c[start]+=lazy[node];
        cout<<"Updating ?^%  value to "<<c[start]<<" at "<<start<<"\n";
        	lazy[node]=0;
    	}
    	lazy[node]=0;
	}
    if(start>end||start>r||end<l){
    return;
    }
    if(start>=l&&end<=r)
    {
    	if(start!=end)
		{
			lazy[2*node]+=1;
			lazy[2*node+1]+=1;
			cout<<"Updated value of "<<2*node<<" to "<<lazy[2*node]<<" ";
			cout<<"Updated value of "<<2*node+1<<" to "<<lazy[2*node+1]<<"\n";
		}
		else
    	{
        	c[start]+=1;
        		cout<<"Updating value to "<<c[start]<<" at "<<start<<"\n";
        	lazy[node]=0;
    	}
    return;
	}
    int mid=(start+end)/2;
    updateInterval(node*2,start,mid,l,r);
    updateInterval(node*2+1,mid+1,end,l,r);
}
int queryRange(int node,int start,int end,int l,int r)
{
	if(start>end||start>r||end<l)
	return 0;
	if(lazy[node]!=0)
	{
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		else{
		 c[start]+=lazy[node];
		 lazy[node]=0;
		return c[start];
		}
	}
	if(start>=l&&end<=r)
	return c[start];
	int mid=(start+end)/2;
    queryRange(node*2,start,mid,l,r);
    queryRange(node*2+1,mid+1,end,l,r);
}
int main()
{
    int n,m,w,a,b;
    cin>>n>>m>>w;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        updateInterval(1,1,w,a+1,b+1);
        //cout<<" Lazy Array: ";
         /*for(int j=1;j<2*w+3;j++)
        	cout<<lazy[j]<<" ";
		cout<<"\n";*/
    }
    queryRange(1,1,n,1,n);
    for(int i=1;i<=w;i++)
    cout<<c[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        //cout<<queryRange(1,1,n,a+1,a+1)<<endl;
        cout<<c[a+1]<<endl;
    }
    return 0;
}


