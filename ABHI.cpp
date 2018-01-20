#include<iostream>
using namespace std;
int c[1000003];
void updateInterval(int node,int start,int endi,int l,int r)
{
    if(start>endi||start>r||endi<l){
    return;
    }
    if(start==endi)
    {
        c[start]++;
        return;
    }
    int mid=(start+endi)/2;
    updateInterval(node*2,start,mid,l,r);
    updateInterval(node*2+1,mid+1,endi,l,r);
}

void updateRange(int node,int start,int end,int l,int r,int val)
{
	if(lazy[node]!=0)
	{
		c[node]+=(en)
	}
}



int main()
{
    int n,m,w,a,b;
    cin>>n>>m>>w;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        updateInterval(1,1,w,a+1,b+1);
    }
    for(int i=0;i<m;i++)
    {
        cin>>a;
        cout<<c[a+1]<<endl;
    }
    return 0;
}

