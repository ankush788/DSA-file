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
	tree()
	{
		data=0;
	}
////////////////// delete tree destructor
 ~tree( )
 { 
 ///////yha par us object ke just delete hone se phele ya remove hone se phele ke  kaaam kar skte hai
 for(int  i=0 ; i<children.size();i++)
 {
 	 delete children[i];
 }
 	 
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
 	{ tree<int>*temp= root;
 	queue<tree<int>*> pending;
 	pending.push(temp);
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
 

////////////////////delete function( deleting tree by using function )
 void deletion(tree<int>*root)
{
	 for( int i=0;i<root->children.size();i++)
	 {
	 	 deletion( root->children[i]);
	 }
	  delete root;
}

 
};

///////////////////////////////

////////use  test case  10 3 20 30 40 2 40 50 0 0 0 0

/////////////////////////////////////

