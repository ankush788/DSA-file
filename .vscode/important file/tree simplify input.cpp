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
 cout<<" enter the root data"<<endl;     
	int data; 
	 cin>>data;
	  tree<int>* root=new tree<int>(data);
	  
	///////////////queues sare node dalte rhe (as a pending for work) one by one nikal lo for work
	/////store baki ke node ke address ko 
	/////pop ya karega us node ko jis par work karna hai(front se phele node le lena) ( inbuilt stack pop  void function hai) 
	queue<tree*>pending;
	pending.push(root);
	while( !pending.empty())
	{ 
	tree<int>* work=pending.front();
	pending.pop();
	cout<< "enter the no of child of "<<work->data<<endl;
	int child;
	 cin>>child;
	 for( int i= 0 ; i<child ;i++)
	 { int value;
	 	cout<<"enter "<<i<<"data element "<<endl;
	  cin>>value;
	  tree<int>*putter= new tree<int>(value);
	  pending.push(putter);
	  work->children.push_back(putter);
	 }
		
		
	}
	 	 
	 return root;
}
//////////////////////// print
 void	print(tree<int>* root)
 	{
 	queue<tree<int>*> pending;
 	pending.push(root);
 	while( !pending.empty())
 	{
 	
 		tree<int>* work =pending.front();
 		pending.pop();
 		
 		cout<<work->data<<": ";
	 for( int i=0;i<work->children.size();i++)
	 {
	 	cout<<work->children[i]->data<<",";
	 	
	 	pending.push(work->children[i]);
	 }
	 
	 cout<<endl;
	 }
	 return ;}
 
///////////////////////count node 
int count(tree<int>*root)
{
	 int ans =1;
	  for( int i=0;i<root->children.size();i++)
	  {
	  	 ans= ans+count(root->children[i]);
	  }
	  return ans;
}
 /////////////////////maxvalue of node
	 int maximum( tree<int>*root)
	 {
	 	int max =root->data;
	for( int i =0 ;i<root->children.size();i++)
 {
 	if( max<maximum(root->children[i]))
		{
		 max=maximum(root->children[i]);
	 }
}
return max;
}
////////////////////////////////height of node
int height( tree<int>*root )
{
int maxlength=0;
if(root==NULL)
{

	return maxlength;
}
	  
	  for( int i =0 ; i<root->children.size();i++)
{
	if(maxlength<=height( root->children[i]))
	{
		maxlength=  height( root->children[i]);
	}
}
return (maxlength+1);
}
//////////////////////////////all element at a particular depth
void depths( tree<int>*root, int depth )
{

if(root==NULL)
{
cout<<"empty tree "<<endl;
	return ;
} 

	if(depth==0)
	{
	cout<<root->data<<" ";	
	return;
	}
	  
	  
	  
	  for( int i =0 ; i<root->children.size();i++)
{
	depths( root->children[i],depth-1);

}
return ;
}
/////////////leaf node total last node

int leaf( tree<int>*root)
{ 
int count=0;
	 if( root->children.size()==0)
	 {
	 	count++;
	 }
	  for( int i =0 ; i<root->children.size();i++)
{
count=count+leaf( root->children[i]);

}

return count;
}
 
};
///////////////////////////////

////////use  test case  10 3 20 30 40 2 40 50 0 0 0 0

/////////////////////////////////////
int main()
{ tree<int> obj(0);
tree<int>* root= obj.input();
obj.print(root );
cout<<count(root);
return 0;
}

