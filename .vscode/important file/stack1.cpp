#include<bits/stdc++.h>
using namespace std;
class Stack{
	 int nextindex;
	  int *arr;
	  int capacity;
	  public :
	  Stack()
	  {
	  	 nextindex=0; 
	  	 arr=new int [4];
	  	 capacity=4;
	  }
	 
//////////////////////push 
void push( int data)
{
	
			if( nextindex==capacity)
	{
		t * arr1= new t [2*capacity];
		for( int i=0;i<nextindex;i++)
		{
		arr1[i]=arr[i];	
		}
		delete [] arr;
		arr= arr1;
		capacity= capacity*2;
	}
	
	arr[nextindex]=data;
	nextindex++;
return ;
}
//////////////////pop
int pop()
{
	 if(isempty())
	 { cout<<" Stack is empty"<<endl; 
	 return -1;
	 }
	 nextindex--;
	 return arr[nextindex];
}

//////////////////// top
 int top( )
 {
 	if(isempty())
 	{
 		cout<<" the Stack is empty"<<endl;
 		return -1;
	 }
	 return arr[nextindex];
 }
 /////////////////////////isempty
 bool isempty( )
 {
 	 return nextindex==0;
 }
 ////////////////////size
 int size()
 {
 	 return nextindex;
 }
};
 //////////////////////

