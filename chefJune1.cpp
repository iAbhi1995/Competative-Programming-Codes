#include<stdio.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#include <algorithm>
using namespace std;
void perform(int *a,int* b,int* c)
{
	int i,j,k,pos,pos1,pos2;
	pos=binarySearch(y,a[0],0);
	pos1=binarySearch(y,b[0],0);
	
	
	
	
	
}
int main()
{
	test
	{
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		int a[p+1],b[q+1],c[r+1];
		loop(i,1,p)
		scanf("%d",a[i]);
		loop(i,1,q)
		scanf("%d",b[i]);
		loop(i,1,r)
		scanf("%d",c[i]);
		sort(a,a+p);
		sort(b,b+q);
		sort(c,c+r);
		perform(a,b,c);
	}
	
	return 0;
}
