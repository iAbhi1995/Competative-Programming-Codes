//convert binary tree into bst in minimum no. of swaps;
#include<stdio.h>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int n,cnt;
pair<int,int> inArr[100002];
void inorder(int *tree,int i)
{
	if(i>n)
	return;
	inorder(tree,2*i);
	inArr[cnt].first=tree[i];
	inArr[cnt].second=cnt;
	cnt++;
	inorder(tree,2*i+1);
}
int main()
{
	scanf("%d",&n);
	int a[n+1],total=0;
	for(int i=1;i<=n;i++)
	{scanf("%d",&a[i]);}
	cnt=1;
	inorder(a,1);
	sort(inArr+1,inArr+n+1);
	vector<bool> vis(n+1,false);
	for(int i=1;i<n+1;i++)
	{
		if(vis[i]||inArr[i].second==i)
		continue;
		int j=i,cyclesize=0;
		while(!vis[j])
		{
			vis[j]=1;
			j=inArr[j].second;
			cyclesize++;
		}
		total+=(cyclesize-1);
	}
	printf("%d\n",total);
	return 0;
}
