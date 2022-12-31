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
//////////////////////////////////////////////////// INSERTION FUNCTION
 node* insertion (int data ,int index,node *head) 
{ node* temp =head;
node* n= new node(data);
	int count =0;
	if(index==0)
	{ while( temp->next!=head)
	{ temp=temp->next;
	}
	temp->next=n;
		 n->next=head;
		 
		 return n;
	}
	while(count<index-1)
	{ 
	temp=temp->next;
	count++;
	}
	n->next= temp->next;	
	temp->next=n;  
	
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
	 }
	 cin>>data;
	 }
	 tail->next=head;

	 return head;
}
///////////////////////////// PRINT FUNCTION
void print (node*head)
{
	 node*temp= head;
	 do
	 {
	 	 cout<<temp->data<<" ";
	 	 temp=temp->next;
	 }
	 while(temp!=head);
	 
}
////////////////////////////// DELETION FUNCTION 
node* deletion( int index,node *head)
{ int count =0;
	node* temp =head;
	if( temp==NULL)
	{
	return head;}
	
	if( index==0)
	{ while( temp->next!=head)
	{
		 temp=temp->next;
	}
	 node * a= head;
	head=head->next;
	delete a;
	temp->next=head;
	return head;
	}
	
	while( count<index-1)
	{ temp  =temp->next;
	
	count++;
	}
	node* a=temp->next;
	temp->next=a->next;
		delete a;
	
		return head;

}

