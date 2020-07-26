#include <iostream>
using namespace std ; 
struct node{
	int val ; 
   node  *left ; 
   node *right;
};
node* getNode(int x)
{
	node* n = new node();
    n->left=NULL;
    n->right=NULL;
    n->val=x;
    return n;
}
node* insert(node* root,int x )
{
	if(root==NULL)
		return getNode(x);
	if(root->val<x)
	{
		root->right=insert(root->right,x);
	}
	else
		root->left=insert(root->left,x);
	return root;
}
void Travelsal(node* root)
{
	if(root==NULL)
		return ;
	
	node* current=root;
	node* pre ; 
	 while(current!=NULL)
	 {
	 	if(current->left==NULL)
	 	{
	 		cout<<current->val<<" ";
	 		current=current->right;
	 	}
	 	else
	 	{
	 		pre= current->left;
	 		while(pre->right!=NULL && pre->right!=current)
	 			pre=pre->right;
	 		if(pre->right==NULL)
	 		{
	 			pre->right=current;
	 			current=current->left;
	 		}
	 		else
	 		{
	 			cout<<current->val<<" ";
	 			pre->right=NULL;
	 			current=current->right;
            }
	 	}

	 }
}
void inorder(node *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->val;
	inorder(root->right);
}
int main()
{
 node* root = NULL;
 root=insert(root,7);
 root=insert(root,3);
 root=insert(root,8);
 root=insert(root,4);
 root=insert(root,2);
 inorder(root);
 cout<<endl;
 Travelsal(root);
 return 0 ;

}