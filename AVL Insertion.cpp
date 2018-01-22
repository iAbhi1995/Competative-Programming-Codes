#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; 
int height(node *N)
{
    if (N == NULL)
        return -1;
    return N->ht;
}
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

void RotateLeft(node* root)
{
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root->ht=(height(root->left)> height(root->right) ? height(root->left) : height(root->right))+1;
    temp->ht=((height(temp->left) > height(temp->right)) ? height(temp->left) : height(temp->right))+1;
    root=temp;
}
void RotateRight(node* root)
{
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root->ht=((height(root->left ) > height(root->right)) ? height(root->left) : height(root->right))+1;
    temp->ht=((height(temp->left) > height(temp->right)) ? height(temp->left) : height(temp->right))+1;
    root=temp;
}
node * insert(node * root,int val)
{
	
   if(root==NULL)
   {
       node *temp = (node*)malloc(sizeof(node));
       temp->left=temp->right=NULL;
       temp->ht=0;
       temp->val=val;
       return temp;
   }
    if(root->val<val){
        root->right=insert(root->right,val);
    	//	cout<<root->left->val<<endl;
		//cout<<"In the insertion right "<<val<<endl;
	}
    else{
        root->left=insert(root->left,val);
    	//cout<<"In the insertion left "<<val<<endl;
	}
	 root->ht=((height(root->left) > height(root->right)) ? height(root->left) : height(root->right))+1;
	int balanceFactor = getBalance(root);
	cout<<"BALANCE FACTOR : "<<balanceFactor<<" "<<root->val<<endl;
    if(balanceFactor>1)
    {
     if(height(root->left->left) > height(root->left->right))
         RotateLeft(root);
      else
          {
          RotateLeft(root->left);
          RotateRight(root);
      }
    }
    if(balanceFactor<-1)
    {
     if(height(root->right->right) < height(root->right->left))
         RotateRight(root);
      else
          {
         RotateRight(root->right);
         RotateLeft(root);
      }
    }
   return root;
}
int main()
{
	node* root=NULL;
	int a[]={3,2,4,5,6};
	for(int i=0;i<5;i++){
	root = insert(root,a[i]);
 }
	cout<<getBalance(root)<<" "<<root->val<<endl;
//	cout<<getBalance(root->left)<<root->left->val<<endl;
	cout<<getBalance(root->right)<<root->right->val<<endl;
	cout<<getBalance(root->right->right)<<root->right->right->val<<endl;
	return 0;
}
