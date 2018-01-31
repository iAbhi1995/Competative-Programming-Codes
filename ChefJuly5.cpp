#include<bits/stdc++.h>
#include<iostream>
#define test int t;scanf("%d",&t);fflush(stdin);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define MOD1 1000000007
#define MOD2 1000000009
#define ll unsigned long long int
using namespace std;
int gcdExtended(ll a,ll b, ll& x, ll& y)
{
	//printf("a= %llu\n",a);
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1; 
    return gcd;
}
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, x, y);
    ll res = (x%m + m) % m;
      //cout << "Modular multiplicative inverse is " << res<<"\n";
        return res;
}
void primeFactors(ll& n,ll& m)
{
    while (n%2 == 0&&m%2==0)
    {
    	m=m/2;
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(min(n,m)); i = i+2)
    {
        while (n%i == 0&&m%i==0)
        {
        	m=m/i;
            n = n/i;
        }
    }
    if(n%m==0)
    {n=n/m;m=1;}
    else if(m%n==0)
    {m=m/n;n=1;}
}
int main()
{
	test
	{
		ll n,num,den;
		scanf("%llu",&n);
		if(n==1)
		{
			num=0;den=1;
		}
		else if(n==2)
		{
			num=1;den=1;
		}
		else{
			n=n-2;
			num=(n+2)*(n+1);
			den=4*n+2;
		}
	//	printf("numberators and denominator are %llu,%llu\n",num,den);
		primeFactors(num,den);
	//	printf("After numberators and denominator are %llu,%llu\n",num,den);
		ll ans1=((num%MOD1)*modInverse(den,MOD1))%MOD1;
		printf("%llu ",ans1);
		ans1=((num%MOD2)*modInverse(den,MOD2))%MOD2;
		printf("%llu \n",ans1);
	}
	return 0;
}
