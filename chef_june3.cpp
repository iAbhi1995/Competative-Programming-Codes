#include<iostream>
#include<math.h>
#include<vector>
#define test int t;cin>>t;while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[2501][2501];
int main()
{
    test
    {
        long long int cnt =0;
        int n,k,len,x;
        cin>>n>>k;
        vector<int> falsity;
        for(int i=0;i<n;i++)
        {
            cin>>len;
            loop(j,0,len)
            {
                cin>>x;
                a[i+1][x]=1;
            }
        }
        loop(i,1,n+1)
        {
            loop(j,1,k+1)
            {
            	//cout<<a[i][j]<<" ";
                if(a[i][j]==0)
                    falsity.push_back(j);
                else
                    a[i][j]=0;
            }
            //cout<<endl;
            /*for(int q=0;q<falsity.size();q++)
            cout<<falsity[q]<<" ";
            cout<<"\n";*/

           if(falsity.size()==0){
            cnt+=n-i;
            falsity.clear();
            continue;
            }
            loop(j,i+1,n+1)
            {
                int q=0;
                 for(q=0;q<falsity.size();q++)
                {
                    if(a[j][falsity[q]]==0)
                        break;
                }
                if(q==falsity.size())
                    cnt++;
            }
            falsity.clear();
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
