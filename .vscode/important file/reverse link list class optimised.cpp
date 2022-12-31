#include<bits/stdc++.h>
using namespace std;
class node
{ public:
	int data;
	node*next;
	
		node(int data)
		{this->data=data;
		next=NULL;
		}
	};
	 
}
node*input()
{
	 int data;
	 cin>>data;
	 node* head=NULL;
	 node* tail=NULL;
	 while(data!=-1)
	 { 
	 	 node* pointer=new node(data);
	 	 if(head==NULL)
	 	 {
	 	 	head=pointer;
	 	 	 tail=pointer;
		  }
		  else{
		  	tail->next=pointer;
		  	tail=tail->next;
		  }
	 	 cin>>data;
	 }
	 return head;
}

void print(node* head)
{
	 node*temp= head;
	 while(temp!=NULL)
	 { 
	 cout<<temp->data<<" ";
	 temp=temp->next;
	 }
}
 node* reverse3( node* head)
 {
 	 
 	 if( head==NULL||head->next==NULL)
 	 {return head;
	  }
	  node* smallhead=reverse3(head->next);
	 
node* tail=head->next;
	  tail->next=head;
	  head->next=NULL;
	  return smallhead;
 }
int main()
{

node*p1=input();
 node* help=reverse3(p1);
 print(help);
return 0 ;}

