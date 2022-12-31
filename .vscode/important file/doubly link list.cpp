#include<bits/stdc++.h>
using namespace std;
class node
{ public:
	int data;
	node* next;
	 node* previous;
node(int data)
{
	 this->data=data;
	 next=NULL;
	 previous=NULL;
}
};

///////////////////////////////////// INPUT  FUNCTION
node* input()
{
	int data;
	cin>>data;
	node* head=NULL;
	node*tail=NULL;
	while(data!=-1)
	{
	  node* pointer= new node(data);
if(head==NULL)
{
	head=pointer;
	tail=pointer;
}
else
{
	tail->next=pointer;
	pointer->previous=tail;
	tail=tail->next;

}

cin>>data;
}

return head;
}
//////////////////////////////// INTERSTION FUNCTION 
node* insertion( int pos ,int data,node* head)
{ node* pointer =new node(data);
node* temp =head;

if( pos==0||head==NULL)
{pointer->next=head;
if(head!=NULL)
{
head->previous=pointer;
}

return pointer;
	 
}
	 int count =0;
	 while( count<pos-1)
	 { if(temp==NULL)
	 { 
	 return head;
	 }
	 
	 temp=temp->next;
	 	count++;
	 }
	 if( temp->next!=NULL)
	 {
		 temp->next->previous=pointer;
	pointer->next=temp->next;
	 }
	 	temp->next=pointer;
	 pointer->previous=temp;
	 
	 return head;
}
//////////////////////////////// DELETION FUNCTION
 node*deletion (int index,node*head)
 {
 	
 	int count= 0;
 	
 	node* temp= head;
 	if(head==NULL)
 	{
 		 return head ;
	 }
	 if(index==0 )
	 {
	 	head=head->next;
	 delete head->previous;
	 head->previous =NULL;
	 	return head;
	 	
	 }
	 
 	while(count<=index-1) 
{
	if(temp==NULL)
	{
		return head;
	}
	 temp=temp->next; 
	 count++;
}
if(temp->next!=NULL)
{
temp->next->previous=temp->previous;

}
temp->previous->next=temp->next;
delete temp;
return head;

 }
 ////////////////////// PRINT HEAD FUNCTION
 void print_head(node* head)
 {
 	if(head==NULL)
 {
 	return ;
 }
 while(head!=NULL)
 {
 	cout<<head->data<<" ";
	head=head->next;
}
}
///////////////////////////////// PRINT TAIL FUNCTION 
void print_tail(node* tail)
{
	if(tail==NULL)
	{
		return ;
	}
	while( tail!=NULL)
	{ cout<<tail->data<<" ";
		 tail=tail->previous;
	}
}




s
