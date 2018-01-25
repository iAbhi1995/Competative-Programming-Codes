#include<iostream>
#include<math.h>
#include<algorithm>
#define test int t;cin>>t;while(t--)
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define revloop(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
ll p[100001],q[100001],r[100001],sumX[100001],sumZ[100001];
int x,y,z;
int main()
{
    test
    {
     int prevX=0,prevZ=0;ll sum=0;
     cin>>x>>y>>z;
     loop(i,0,x)
     cin>>p[i];
     loop(i,0,y)
     cin>>q[i];
     loop(i,0,z)
     cin>>r[i];
     sort(p,p+x);sort(q,q+y);sort(r,r+z);
     sumX[0]=p[0];
     loop(i,1,x)
     sumX[i]=sumX[i-1]+p[i];
     sumZ[0]=r[0];
     loop(i,1,z)
     sumZ[i]=sumZ[i-1]+r[i];
     loop(i,0,y)
     {
         while(p[prevX]<=q[i]&&prevX<x){
             cout<<prevX<<" x ";
             prevX++;
         }
         cout<<"\n";
         while(r[prevZ]<=q[i]&&prevZ<z){
             cout<<prevZ<<" z ";
             prevZ++;
         }
         cout<<"\n";
         if(prevZ==0||prevX==0)
             continue;
         cout<<prevX<<" "<<prevZ<<" "<<q[i]<<"\n";
         sum+=((q[i]*q[i])*(prevX)*(prevZ)+((prevX)*r[prevZ-1] + (prevZ)*p[prevX-1])*q[i]+(p[prevX-1]*r[prevZ-1]))%1000000007;
     }
     sum=sum%1000000007;
     cout<<sum<<"\n";
    }
    return 0;
}
