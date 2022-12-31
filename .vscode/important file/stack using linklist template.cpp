#include<bits/stdc++.h>
using namespace std;
template<typename t>
class node
{ public :
	 t data;
	  node<t> * next;
	  
	   node( t data)
	   { 
	   this->data=data;
	    next=NULL;
	   	 
	   }
};
/////////////////////////stack//////////jitni bhi class banoge unke sath  template lagna padega if the class is use any template
template<typename t>
 class Stack
 { int nextindex;
 node<t>* head ;
 public:
 	 Stack()
 	 {
 	 	 head=NULL;
 	 	  nextindex=0;
	  }
	  
//////////////////////////////push	
	  	void push( t data)
	  	{
	  	node<t>* temp=new node<t>(data);
		  if( head==NULL)	 
		  {
		  	 head=temp;
		  	 return;
		  }
		  temp->next= head;
		   head=temp;
		   nextindex++;
		  } 
///////////////////////pop
t pop()
{ 
if( head==NULL)
 {
 	 cout<<"stack is empty"<<endl;
 	  return -1;
 }
 node<t>* temp =head;
  head= head->next;
  t value =temp->data;
  delete temp;
  nextindex--;
  return value;
 } 
///////////////top 
  t top()
  {
  	 if( head==NULL)
  	 {
  	 	cout<<"stacK is empty"<<endl; 
  	 return 0;	
	   }
  	  return head->data;
			 }		   
//////////////////////isempty
bool isempty( )
{
	 return head==NULL;
} 
/////////////////////////
int size()
{
	 return nextindex;
}
 };
 
 
