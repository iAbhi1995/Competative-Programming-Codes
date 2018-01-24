#include<iostream>
using namespace std;
class bst
{
	public:
	int data;
	bst *left,*right;
};
int count;
bst * insertInBinaryTree(bst* root,int x)
{
	if(!root)
	{
		bst *temp=new bst();
		temp->data=x;
		temp->left=temp->right=NULL;
		root=temp;
		count++;
		return root;
	}
	if(root->data>x)
	{
		root->left=insertInBinaryTree(root->left,x);
	}
	else if(root->data<x)
	{
		root->right=insertInBinaryTree(root->right,x);
	}
	return root;
}
int height(bst* root)
{
	if(root==NULL)
	return 0;
	else
	return (max(height(root->right),height(root->left))+1);
}
void inorder(bst* root)
{
	if(root->left)
	inorder(root->left);
	cout<<root->data<<" ";
	if(root->right)
	inorder(root->right);	
}
int main()
{
	bst* root=NULL;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		root=insertInBinaryTree(root,x);
	}	
	cout<<height(root)<<endl;
	inorder(root);
	return 0;
}
