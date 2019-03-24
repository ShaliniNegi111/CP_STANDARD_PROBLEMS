#include<bits/stdc++.h>
using  namespace  std ;
struct node
{
      int data ;
      node * left , * right ;
      node ( int data )
      {
            this -> data = data ;

      }
};

node * Binary_Tree( )
{

      int x;
	cin>>x;
	if(  x==-1)
		return NULL;
	node *root=new node ( x ) ;
	cout<<"\nenter left of "<<x<<"(-1 for empty node) :";
	root->left=Binary_Tree();
	cout<<"\nenter right of"<<x<<"(-1 for empty node) :";
	root->right=Binary_Tree();
	return root;
}
bool IsBST ( node * root )
{
      bool x = 1 ;
      if ( root == NULL ) return 1 ;
      if ( root -> left == NULL and root -> right == NULL ) return 1 ;
      if ( root -> left != NULL and root -> right  != NULL )
      {
            if ( root -> left -> data > root -> data  or  root -> right -> data  < root -> data ) x = 0 ;
      }
      else if (root -> left != NULL )
      {
             if ( root -> left -> data > root -> data  ) x = 0 ;

      }
      else if (   root -> right  != NULL )
      {
             if ( root -> right -> data  < root -> data ) x = 0 ;

      }
      return  ( x and IsBST (   root -> left ) and IsBST ( root -> right ) ) ;
}
int main ()
{
     node * root  = NULL ;
     cout << "enter the data \n ";
      root =Binary_Tree (  ) ;
      if ( IsBST( root ) ) cout << "Yes" << endl ;
      else cout << "NO" <<endl ;

}
