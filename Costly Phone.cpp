#include<stdio.h>
#include<iostream>
#include<string>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	printf("In main\n");
    test
    {
        int d,cost[11],l,total=0;bool update;string s;
        loop(i,0,10){
        	scanf("%d",cost+i);
    	}
			printf("In main\n");
    	scanf("%d",&l);
        printf("Input the string\n");
        cin>>s;
		while(1)
        {
            update=false;
            loop(i,0,10)
            loop(j,0,10)
            {
                d=(i+j)%10;
                if(cost[d]>cost[i]+cost[j])
                {
                    update=true;
                    cost[d]=cost[i]+cost[j];
                }
            }
            if(!update)
            break;
        }
        loop(i,0,l)
            total=total+cost[s[i]-'0'];
        printf("%d\n",total);
    }
    return 0;
}
