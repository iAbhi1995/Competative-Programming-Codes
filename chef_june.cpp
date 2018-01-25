#include<iostream>
#include<math.h>
#include<algorithm>
#define test int t;cin>>t;while(t--)
using namespace std;
int main()
{
    test
    {
        long long int maxSum=0,crntSum=0,n,cnt=0,negSum=0,x;
        cin>>n;
        int a[n],k=0;
        for(long long i=0; i<n; i++)
        {
            cin>>x;
            if(x<0)
                a[k++]=x;
            else
            {
                crntSum+=x;
                cnt++;
            }
        }
        maxSum=cnt*crntSum;
        sort(a,a+k);
        for(int i=k-1;i>=0;i--)
        {
            if((crntSum+a[i])*(cnt+1)>=maxSum)
            {
                //cout<<crntSum<<" "<<cnt<<"in if\n";
                crntSum=crntSum+a[i];
               cnt=cnt+1;
               maxSum= (crntSum)*(cnt);
            }
            else{
                negSum+=a[i];
                //cout<<maxSum<<"in else\n";
            }
        }
        maxSum+=negSum;
        cout<<maxSum<<"\n";
    }
    return 0;
}

/*void build(int node,int start,int endi)
{
    if(start==endi)
        tree[node]=a[start];
    else
    {
        int mid=(start+endi)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,endi);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void updateRange(int node,int start,int endi,int l,int r)
{
    if(start>endi||start>r||endi<r)
        return;
    if(start==endi){
        tree[node]=0;
        return;
    }
    int mid=(start+endi)/2;
    updateRange(2*node,start,mid,l,r);
    updateRange(2*node+1,mid+1,endi,l,r);
    a[node]=0;
}
int queryRange(int node,int start,int endi,int l,int r)
{
    if(start>endi||start>r||endi<r)
        return 0;
    if(start==endi){
}
}
int maxSubArraySum(int a[], int size1,int *block_size)
{
   int max_so_far = a[0],prev_max=0,curr_size=0,so_far_size=0;
   int curr_max = a[0];

   for (int i = 1; i < size1; i++)
   {
        prev_max=curr_max;
        curr_max = max(a[i], curr_max+a[i]);
        if(curr_max==prev_max+a[i])
            curr_size++;
        else
            cur_size=1;
        prev_max=max_so_far;
        max_so_far = max(max_so_far, curr_max);
        if(max_so_far==curr_max)
            so_far_size=curr_size;
   }
   return max_so_far;
}*/
