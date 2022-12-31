#include<bits/stdc++.h>
using namespace std;
class node
{ public :
	int data;
	 node *next;
	 node* previous;
	  
node( int data)
{
	  this->data= data;
	  next=NULL;
	  previous=NULL;
	  
}
	
};
//////////////////////////////////////////////////// INSERTION FUNCTION
 node* insertion (int data ,int index,node *head) 
{ node* temp =head;
node* n= new node(data);
	int count =0;
	
	if(index==0)
	{

		temp->previous->next=n;
		n->previous=temp->previous;
		 n->next=temp;
		temp->previous=n;
		 
		 return n;
	}
	while(count<index-1)
	{ 
	temp=temp->next;
	count++;
	}
	n->next= temp->next;
	temp->next->previous=n;
	temp->next=n;
	n->previous=temp;
	
	return head;	
}
//////////////////////////////////// INPUT FUNCTION
node* input()
{ node* head= NULL;
node* tail =NULL;
	int data;
	 cin>>data;
	 while(data!=-1)
	 {
 node *n= new node(data);
	  if( head ==NULL)
	 	{
	 	head = n;
		 tail =n;
	}
	 else
	 {
	 tail ->next = n;
	 tail =tail->next;	
	 tail->previous=n;
	 }
	 cin>>data;
	 }
	 tail->next=head;
head->previous=tail;
	 return head;
}
///////////////////////////// PRINT_HEAD FUNCTION
void print_head(node*head)
{
	 node*temp= head;
	 do
	 {
	 	 cout<<temp->data<<" ";
	 	 temp=temp->next;
	 }
	 while(temp!=head);
	 
}
/////////////////////////////PRINT_TAIL FUNCTION 

void print_tail(node* tail)
{ node* temp=tail;
	do{  cout<<temp->data<< " ";
		temp=temp->previous;
	}
	while( temp!=tail);
}
////////////////////////////// DELETION FUNCTION 
node* deletion( int index,node *head)
{ int count =0;
	node* temp =head;
	if( temp==NULL)
	{
	return head;}
	
	if( index==0)
	{ 
	
	
	 node * a= head;
	head->previous->next=head->next;
	head->next->previous=head->previous;
	head=head->next;
	delete a;
     return head;
	}
	
    while( count<= index-1)
    { temp  =temp->next;
	count++;}
	cout<<"test value"<<temp->data<<endl;
	temp->next->previous=temp->previous;
	temp->previous->next=temp->next;
	// temp->next->previous=temp->previous;
	temp=NULL ;
	
		return head;
}
//////////////////////////////////// INT MAIN
int main()
{
	 node *head =input();
	 int  index;
	 cout<<"enter the index "<<endl;
	 cin>>index;
	  head=deletion( index,head);
	  print_head(head);
	 /* node*  temp=head;
	    while( temp->next!=head)
	    {
	    	temp=temp->next;
		}*/
	// print_tail(temp);
/*	 int data;
	 cout<<"enter the data"<<endl;
	cin>>data;
	*/
//	head= insertion(data ,index,head);
	//print_head(head);
	 /* temp=head;
	    while( temp->next!=head)
	    {
	    	temp=temp->next;
		}
	 print_tail(temp);
	 */
	return 0;
}

