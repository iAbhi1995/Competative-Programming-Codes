#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
#include<stdio.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define test int t;cin>>t;while(t--)
#define MOD 1000000007
using namespace std;
vector<int> prime;
int a[1000001];

void simpleSieve(int limit)
{
    bool mark1[(int)sqrt(limit)+1];
    memset(mark1,true,sizeof(mark1));
	mark1[0]=mark1[1]=false;
	for(int p=2;p<sqrt(limit);p++)
    {
        if(mark1[p]==true)
        {
            for(int i=p*2;i<sqrt(limit)+1;i+=p)
                mark1[i]=false;
        }
    }
    for(int i=0;i<sqrt(limit)+1;i++)
        if(mark1[i])
            prime.push_back(i);
}

void segment(int left,int right,bool* mark)
{
    memset(mark,true,sizeof(mark));
    for(int i=0;i<prime.size();i++)
    {
        int flag=1;
        for(int j=left;j<=right;j+=flag)
        {
            if(j%prime[i]==0&&j==prime[i])
                flag=prime[i];
            else if(j%prime[i]==0){
                mark[j-left]=false;
                flag=prime[i];
            }
        }
    }
}
int func(int &l,int &r,int& x,int& y,int &n)
{
    simpleSieve(y);
    int result=0;
    int division=sqrt(y-x+1),i=0;
    for(i=x;i<=y;i+=division)
    {
        bool mark[division];int number,exponent=0;
        segment(i,i+division-1,mark);
        for(int t=0;t<division&&t+i<=y;t++)
        {
 //         cout<<mark[t]<<t+i<<endl;
            if(mark[t])
            for(int k=l;k<=r;k++)
            {
                number=a[k];exponent=0;
                while(number%(i+t)==0)
                {
                    exponent +=1;
                    number=number/(i+t);
                }
                result=result+exponent;
                result=result%MOD;
            }
        }
    }
    return result;
}
int main()
{

    int n,q,l,r,x,y;
    //cout<<"Enter n\n";
    cin>>n;
    //cout<<"Enter array elements\n";
    loop(i,0,n)
    cin>>a[i];
    //cout<<"Enter q\n";
   	cin>>q;
   	while(q--)
    {
    //    cout<<"Enter l r x y\n";
        scanf("%d%d%d%d",&l,&r,&x,&y);
        l-=1;r-=1;
        cout<<func(l,r,x,y,n)<<endl;
        prime.clear();
    }
	return 0;
}
