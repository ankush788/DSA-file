#include<bits/stdc++.h>
using namespace std;
 class Queue
 {
 	 int front ; 
 	 int rear;
 	 int size ;
 	 int *arr;
 	 int capacity;
 	 public :
 	 Queue( int total)
 	 {
 	 	arr=new int [total];
 	 	 front=0;
 	 	 rear =0;
 	 	 size=0;
 	 	  capacity =total;
	  }
////////////////enqueue
void enqueue( int data)
 {
 	 if(  capacity ==size)
 	 {
 	 	 cout<<" stack is full"<<endl ;
 	 	 return;  }
		   
 	 			 
			   arr[rear]=data;
		    rear=(rear+1)%capacity;
		    size++;
		    return ;
		    
 	 	  }
 ///////////////////////dequeue
 int dequeue( )
 {  if(size ==0)
 { cout<<"queue is empty"<<endl;
 return -1;
 }
 size--; 
 int value =arr[front];
front =(front+1)%capacity; 
 return value;
 
 }
 //////////////////////////front element
 int top( )
 {
 	 if(size==0)
 	 { 
 	 cout<<"queue is empty "<<endl;
 	 return -1;
	  }
	  
 
 return arr[front];
 }
 ////////////////////////////////////is empty
 bool isempty()
 {
 	 return size==0;
 }
 

 };
 /////////////////////////////////
int main()
{
Queue q1( 12);
for( int i =0 ;i<=17;i++)
{ 
q1.enqueue(i);
cout<<i<<endl;
}
cout<<"answer"<<endl;
for( int i=0 ;i<=17;i++)
 {
 	 cout<<q1.dequeue()<<endl;
 }
return 0 ;}

