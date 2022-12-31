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
	 node* merge( node* head1,node* head2)
	{
	if(head1==NULL)
	{ return head2;
	}
	if(head2==NULL)
	{
		return head1;
	}
	node*head=NULL;
	
node*dummy =new node(0);
	head=dummy;
	while((head1!=NULL)&&(head2!=NULL))
{  if((head1->data)<=(head2->data))
{
	
	dummy->next=head1;
	dummy=dummy->next;
	head1=head1->next;
	
}
	else
	{ cout<<"hi   "<<endl;
		dummy->next=head2;
			dummy=dummy->next;
			head2=head2->next;
	}
	
}
while(head1!=NULL)
{
	dummy->next=head1;
	dummy=dummy->next;
	head1=head1->next;
	
}

while(head2!=NULL)
{
	dummy->next=head2;
	dummy=dummy->next;
	head2=head2->next;
	
}
dummy->next=NULL;
dummy=dummy->next;
delete dummy;
return head->next;

}
node* mid(node*head)
{
if((head==NULL)||(head->next==NULL))
{
	return head;
}
node* slow =head;
node* fast=head;
while((fast->next!=NULL)&&(fast->next->next!=NULL)  )
{
fast=	fast->next->next;
	slow =slow->next;
}
 return slow;

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
	 node* merge_sort(node* head)
	 {
	 	if(head==NULL||head->next==NULL)
	 	{ return head; } 
	 		node* middle=mid(head);
	 		node* left=head;
	 		node* right=middle->next;
	 		middle->next=NULL;
	 	left=	merge_sort(left);
	 	right=	merge_sort(right);
		node* head3= merge(left,right);

	 		return head3;  
	 		}

int main()
{ node* p1=input();
print (p1);
//node *p2=input();
 node *p3=merge_sort(p1);
 //cout<<p3<<endl;
print(p3);
//print(p2);

return 0 ;}

