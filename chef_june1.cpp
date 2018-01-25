#include<iostream>
#include<math.h>
#define test int t;cin>>t;while(t--)
using namespace std;
int a[1000011];
int main()
{
    test
    {
        unsigned long long int sum=0,i=1,next=0;
        int n,k=1;
        cin>>n;
        while(n--)
        {
            cout<<i<<" ";
            if(k<3)
            {
                i=i+k;
                k=i;
            }
            else
                i=i+3;
        }
        cout<<"\n";
    }
    return 0;
}
