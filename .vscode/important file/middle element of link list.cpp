#include<bits/stdc++.h>
using namespace std;
class node
{ public :
	int data;
	 node *pointer;
node( int data)
{
	  this->data= data;
	  pointer=NULL;
}
	
};

 node* element(int data ,int index,node *head) 
{ node* temp =head;
node*n= new node(data);
	int count =0;
	if(index==0)
	{
		 n->pointer=head;
		 head=n;
		 return head;
	}
	while(count<index-1 &&temp!=NULL)
	{ 
	temp=temp->pointer;
	count++;
	}
	if( temp!=NULL)
{	n->pointer= temp->pointer;	
	temp->pointer=n;  }
	
	return head;	
}
node* put()
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
	 tail ->pointer = n;
	 tail =tail->pointer;	
	 }
	 cin>>data;
	 }

	 return head;
}
void print (node*head)
{
	 node*temp= head;
	 while( temp!=NULL)
	 {
	 	 cout<<temp->data<<" ";
	 	 temp=temp->pointer;
	 }
	 
}

node* deletion( int index,node *head)
{ int count =0;
	node* temp =head;
	if( temp!=NULL)
	{
	if( index==0)
	{ node * a= head;
	head=head->pointer;
	delete a;
	return head;
	}
	
	while( count<index-1)
	{ temp  =temp->pointer;
	
	count++;
	}
	node* a=temp->pointer;
	temp->pointer=a->pointer;
		delete a;
	}
		return head;

}
   void mid(node*head)
   { int count =1;
   
   	node* fast= head; 
   	node *slow= head;
   	 while(head!=NULL)
   	 {
	if( fast->pointer==NULL)
   	{  cout<<"the middle element is "<<slow->data<<endl;
	   return ;
   
   }
   
   	 	 if( fast->pointer->pointer==NULL)
   	{  cout<<"the middle element is "<<slow->data<<endl;
	   return ;
   	}
   
   		 
			slow=slow->pointer;
	   fast=fast->pointer->pointer;
}
cout<< "null link list "<<endl;
	   
	    }

int main()
{
 node *head  =NULL; 
 mid(head);
return 0 ;}

