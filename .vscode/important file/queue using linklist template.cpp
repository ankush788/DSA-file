#include<bits/stdc++.h>
using namespace std;
//////////////////////////node
 template<typename t>
 class node 
 { 
 public :
 node<t>* next; 
 t data; 
 node<t>(t data)
 {
 	 next=NULL;
 	 this ->data =data;
 }
};
/////////////////////////////////queue
template<typename t>
 class Queue
 { int size ;
  node<t>* head; 
node<t>* tail;
public:
Queue<t>(){
	head=NULL;
	 tail=NULL;
	 size =0;
	 }
	 
/////////////////////enqueue
void enqueue( t data)
{
	node<t>* temp = new node<t>(data);
	size++;
	if( head== NULL)
	{
		head=temp ;
		tail =temp;
		return ;
	}
	else{
		 tail->next=temp;
		 tail= temp ;
	}
	return ;
	
}
/////////////////////////dequeue
t dequeue( )
{
	 if( head==NULL)
	{
		 cout<<"queue is empty "<<endl;
		 return 0;
	}
	size--;
	 
	 node<t> *temp=head;
	 t ans= head->data;
	 head =head->next;
	 delete temp;
	 
	 return ans;
}
///////////////////////////////////////front 
t fornt()
{
	 if( head==NULL)
	 {
	 	 cout<<" queue is empty "<<endl;
	 	 return 0;
	 }
	  return head->data;
}
////////////////////////////////is empty
 bool isempty()
  {
  	 return head==NULL;
  }
 
 	  };
int main()
{
Queue<int>q1; 
for( int i=0 ;i<=29;i++)
{
	 q1.enqueue( i);
}
for( int i=0 ;i<=29;i++)
{
	cout<<q1.dequeue( )<<endl;
}
return 0 ;}

