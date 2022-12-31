#include<bits/stdc++.h>
using namespace std; 
 template<typename t>
 class tree{
 	public:
 	t data ; 
    vector<tree<t>*>children ; 
    tree( t data)
    {
    	this->data= data;
	}
//////////////////////////input
tree<t>* input()
{
	 cout<<"enter data"<<endl;
	 int value;
	 cin>>value;
	 tree<int>*root=new tree<int>( value);
	 cout<<" enter the no . of children "<<endl;
	 int child;
	  cin>>child;
	 for( int i =0;i<child;i++)
	 {
	 	root->children.push_back(input());
	 }
	 return root;
}
//////////////////////// print
 void	print(tree<int>* root)
 	{
 		 if(root==NULL)
 	{
	 return;
	 }
	 cout<<root->data<<" : ";
	 for( int i =0 ;i<root->children.size();i++)
	 {
	 	cout<<root->children[i]->data<<" ";
	 }
	 cout<<endl;
 	for( int i=0;i<root->children.size();i++)
 	{
 		print ( root->children[i]);
	 }
	 return ;}
 };
 
int main()
{ tree<int> obj(0);
tree<int>* root= obj.input();
obj.print(root );

return 0;
}

