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
class pairing{ 
public:
	node* head=NULL;
	node* tail=NULL;
};
pairing input()
{
	int data;
	cin>>data;
	node* head=NULL;
	node*tail=NULL;
	while(data!=-1)
	{ node* pointer= new node(data);
if(head==NULL)
{
	head=pointer;
	tail=pointer;
}
if(head!=NULL)
{
	tail->next=pointer;
	pointer->previous=tail;
	tail=tail->next;
}
//tail->next=NULL;
head->previous=NULL;
cin>>data;
}
pairing ans;
ans.head=head;
ans.tail=tail;
return ans;
}
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
	 head->previous=NULL;
	 	return head;
	 	
	 }
	 
 	while(count<index-1) 
{
	 temp=temp->next; 
	 count++;
}
/*
if(temp->next->next==NULL)
{
	temp->next=NULL;
	return head;
	
}*/
node* temp1=temp->next; 
temp->next=temp1->next;
temp1=temp1->next;
if(temp1!=NULL)
{

temp1->previous=temp;
}
return head;

 }
int main()
{
pairing object=input();
node* head= object.head;
node*tail=object.tail;
  head=deletion(4,head);
while(head!=NULL)
 {
 	cout<<head->data<<" ";
	head=head->next;
}
cout<<endl;

while(tail!=NULL)
{
	cout<<tail->data<<" ";
tail=tail->previous;
}
return 0;
}



