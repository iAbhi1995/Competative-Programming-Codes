#include<bits/stdc++.h>
#define testcase long long int test;scanf("%lld",&test);while(test--)
#define ll long long int
using namespace std;

int main()
{
	testcase
	{
		ll k,a,b;
		scanf("%lld %lld %lld",&k,&a,&b);
		double angle=360.0/k,ab;
		//printf("angle = %f\n",angle);
		ab=angle*abs(b-a);
		if(ab<180)
		printf("%lld\n",abs(b-a)-1);
		else if(ab>180)
		{
			ab=360-ab;
			ab=ab/angle;
			ab=ab-1;
			a=(ll)ab;
			printf("%lld\n",a);
		}
		else
		printf("0\n");
	}
	return 0;
}
