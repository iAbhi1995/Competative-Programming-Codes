#include<iostream>
#include<math.h>
#define test int t;cin>>t;while(t--)
using namespace std;
int main()
{
   long long u,v,x;
    long long int ranking;
    test
    {
        cin>>u>>v;
        ranking=(1+(v*(v+1)/2));
        v+=2;
        x=(u*(u-1))/2;
        ranking+=u*v;
        ranking+=x;
        /*while(u!=0)
        {
            u--;
            ranking+=v;
            v++;
        }*/
        cout<<ranking<<"\n";
    }
    return 0;
}
