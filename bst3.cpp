#include<iostream>
#include<stdio.h>
using namespace std;
class bst
{
	public:
	long long data;
	bst *left,*right;
};
bst * insertInBinaryTree(bst* root,long long x)
{
	if(!root)
	{
		bst *temp=new bst();
		temp->data=x;
		temp->left=temp->right=NULL;
		root=temp;
		return root;
	}
	if(root->data>x)
		root->left=insertInBinaryTree(root->left,x);
	else if(root->data<x)
		root->right=insertInBinaryTree(root->right,x);
	return root;
}
bst* LCA(bst* root,int a,int b)
{
	while(1)
	{
		if((root->data>a&&root->data<b)||(root->data<a&&root->data>b))
		return root;
		if(root->data<a)
		root=root->right;
		else
		root=root->left;
	}
}
long long maxm;
void find(bst* root,int val)
{
		cout<<"In FIND\n";
	if(root->data>maxm)
	maxm=root->data;
	if(root->data==val)
	return;
	if(root->data<val)
	find(root->right,val);
	if(root->data>val)
	find(root->left,val);
	
}

int main()
{
	cout<<"IN main\n";
	bst* root=NULL,*lca=NULL;
	long long n,a;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		cout<<"In loop\n";
		scanf("%lld",&a);
		root=insertInBinaryTree(root,a);
	}
	scanf("%lld%lld",&a,&n);
	lca=LCA(root,a,n);
	find(lca,a);
	find(lca,n);
	printf("%lld",maxm);
	return 0;
}
