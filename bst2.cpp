#include<iostream>
using namespace std;
class bst
{
	public:
	long long data;
	bst *left,*right;
};
bst * insertInBinaryTree(bst* root,int x,int flag)
{
	
	cout<<"Inserting"<<x<<endl;
	if(!root&&!flag)
	{
		bst *temp=new bst();
		temp->data=x;
		temp->left=temp->right=NULL;
		root=temp;
		return root;
	}
	if(!root&&flag)
	{
	    bst *temp=new bst();
		temp->data=x;
		temp->left=temp->right=NULL;
		root=temp;
		cout<<"NO\n";
		return root;
	}
	if(root->data>x)
		root->left=insertInBinaryTree(root->left,x,flag);
	else if(root->data<x)
		root->right=insertInBinaryTree(root->right,x,flag);
	else
	{
	    if(flag)
	    cout<<"YES\n";
	}
	return root;
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
    long long t,n,m,a;
    cin>>t;
    while(t--)
    {
        bst* root;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            root=insertInBinaryTree(root,a,0);
            
        }
        inorder(root);
        for(int i=0;i<m;i++)
        {
            cin>>a;
            root=insertInBinaryTree(root,a,1);
        }
    }
    return 0;
}

