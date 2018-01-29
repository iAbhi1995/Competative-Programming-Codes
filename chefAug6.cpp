#include<bits/stdc++.h>
#define test int t;scanf("%d",&t);while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,long int>
#define ll long long int
#define pli pair<ll ,int>
#define CHARTOKEY(p) (key[p]-'0')
using namespace std;
int power[1000001];
ll cnt;
class Trienode
{
	public:
	Trienode* children[2];
	bool isLeaf;
	Trienode()
	{
		isLeaf = false;
		children[0]=children[1]=NULL;
	}
};
void insert(Trienode * root,long int n)
{
	int index;
	Trienode* pCrawl =root;
	for(long int level=n-1;level>=0;level--)
	{
		index=power[level];
		if(pCrawl->children[index]==NULL)
		{
			pCrawl->children[index]=new Trienode();
			cnt++;
		}
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isLeaf = true;
}

void convertpower(long int c,long int n)
{
	while(power[c]!=0&&c<n)
	{
		power[c]=0;
		c++;
	}
	if(c==n)
	return;
	power[c]=1;
}

int main()
{
	test
	{
		memset(power,0,sizeof(power));
		long int n,q,c;cnt=0;char ch;
		scanf("%ld %ld",&n,&q);
		string query;
		Trienode* root=new Trienode();
		while(q--)
		{
			scanf("\n%c",&ch);
			if(ch=='!')
			{
				scanf("%ld",&c);
				convertpower(c,n);
				insert(root,n);
			}
			else
				printf("%lld\n",cnt+1);
		}
	}
	return 0;
}

/*bool search(Trienode *root,const char *key)
{
	int length=strlen(key),index;
	Trienode* pCrawl =root;
	loop(level,0,length)
	{
		index=CHARTOINDEX(key[level]);
		if(!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isLeaf);
}*/
