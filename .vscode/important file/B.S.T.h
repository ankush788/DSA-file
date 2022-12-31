#include<bits/stdc++.h>
#include"binary.h"
using namespace std;
class bst
{ public:
	binary<int>*root; 

	bst()
	{
		 root=NULL;
	}
	~bst()
	{ 
	delete root; 
	}
/////////////////////////////////////////////// insertion helper function
private:
	  binary<int>* helper( binary<int>*root, int val)
	 {
	 	 if( root==NULL)
	 {
	 	 root= new binary<int>(val);
	 	  return root;
	 }
	 if( root->data>val)
	 {
	 	 binary<int>*left1= helper(root->left,val);
	 	root->left=left1;
	 }
	 if( root->data<val)
	 {
	 	binary<int>*right1= helper(root->right,val);
	 root->right=right1;
	 }
	  
	 return root;
	 }
 
	 public:
/////////////////////////////////insertion main function	 	
 binary<int>* insertion()
{ cout<<" enter the data "<<endl; 
	int val ; 
	cin>>val;
	 
	while( val!=-1)
	{
	this->root =helper(this->root, val);
	cout<<" enter the data "<<endl; 
	cin>>val;	
	}
	 return this->root;
}
/////////////////////////////////////////////////// search help function
private:
	  bool help(binary<int>*root,int val)
	  {
	  	 if( root==NULL)
	  	 {
	  	 	 return false;
		   }
		    if( root->data==val)
		    {
		    	 return true;
			}
			if( root->data>val)
			 {
			 	 return help( root->left,val);
			 }
			 
			 if( root->data<val)
			 {
			 	 return help( root->right, val);
			 }
			 
			 
			 return false;
	  }
////////////////////////////////////////////////////////////search main function 	  
  public:
	bool search( int val)
	{
		 return help( this->root, val);
		 
	}
////////////////////////////////////// deletion  help function

private:
/////////////////////maximum function for deletion function
 int maximum( binary<int>*root)
 {
 	 if( root==NULL)
 	 {
 	 	 return INT_MIN;
	  }
	  
	  binary<int>* temp =root;
	while( temp->right!=NULL)
	{
		  temp =temp->right;
	}
	 return temp->data; 
	  
	 }
	 	
 binary<int>*help_deletion( binary<int>*root, int val)
 {
 	if( root==NULL)
 	{
 		 return NULL;
	 }
	  if(root->data==val)
	  {
///////////////////////////////////////////////////////////	  	
	  	 if( root->left==NULL&&root->right!=NULL)
		  {
		  	 binary<int>*temp= root->right;
		  	 root->left=NULL;
		  	 root->right=NULL;
		  	 delete root;
		  	 return temp;
		  }
//////////////////////////////////////////////////////////////		  
		  
		   if( root->left!=NULL&&root->right==NULL)
		   {
		   	 binary<int>*temp= root->left;
		  	 root->left=NULL;
		  	 root->right=NULL;
		  	 delete root;
		  	 return temp;
		   }
///////////////////////////////////////////////////////////////		   
	  	if(root->left==NULL&&root->right==NULL)
	  	{
	  		delete root; 
	  		return NULL;
	  		 
		  }
/////////////////////////////////////////////////////////////////		  
		  if( root->left!=NULL&& root->right!=NULL)
		  {
		  	 int maxima= maximum(root->left);
		  	 root->data= maxima;
		  	 binary<int>* left1=help_deletion(root->left,maxima);
		  	 root->left=left1;
		  	 return root;
		}
///////////////////////////////////////////////////////////////		  
	  }
	  
	  
	   if( root->data>val)
	   {
	   	 binary<int>*left1=help_deletion(root->left,val);
	   	 root->left= left1;
	   }
	  if( root->data<val)
	  {
	  	binary<int>*right1=help_deletion( root->right,val);
	  root->right=right1;
	  }
	  return root;
	 }	
////////////////////////////////////////////// deletion main fuction 	 
 public:
 void deletion(int val)
 {
 this->root= help_deletion(this->root, val);
 	 return ;
	 }

///////////////////////////////////// print function for BST 
void print(binary<int>* root)
{
	if(root==NULL)
	{
		 return ;
	}
	cout<<root->data<<":";
	if( root->left)
	{
	cout<<"L"<<root->left->data<<" ";
	}
	if( root->right)
	{
		cout<<"R"<<root->right->data<<" ";
	}
	 cout<<endl;
	print( root->left); 
	print( root->right);
		 }	 	
	 
};

