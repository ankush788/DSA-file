#include<bits/stdc++.h>
using namespace std;
class node
{ public :
	int data;
	 node *next;
node( int data)
{
	  this->data= data;
	  next=NULL;
}
	
};
//////////////////////INSERTION FUNCTION
 node* insertion(int data ,int index,node *head) 
{ node* temp =head;
node*n= new node(data);
	int count =0;
	if(index==0)
	{
		 n->next=head;
		 head=n;
		 return head;
	}
	while(count<index-1 &&temp!=NULL)
	{ 
	temp=temp->next;
	count++;
	}
	if( temp!=NULL)
{	n->next= temp->next;	
	temp->next=n;  }
	
	return head;	
}
///////////////////////////////////INPUT FUNCTION
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
	 }
	 cin>>data;
	 }

	 return head;
}
/////////////////////////////////////PRINT FUNCTION
void print (node*head)
{
	 node*temp= head;
	 while( temp!=NULL)
	 {
	 	 cout<<temp->data<<" ";
	 	 temp=temp->next;
	 }
	 
}
///////////////////////////////////////DELETION FUNCTION
node* deletion( int index,node *head)
{ int count =0;
	node* temp =head;
	if( temp!=NULL)
	{
	if( index==0)
	{ node * a= head;
	head=head->next;
	delete a;
	return head;
	}
	
	while( count<index-1)
	{ temp  =temp->next;
	
	count++;
	}
	node* a=temp->next;
	temp->next=a->next;
		delete a;
	}
		return head;

}


