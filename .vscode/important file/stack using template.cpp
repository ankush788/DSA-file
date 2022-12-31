#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Stack{
	 int nextindex;
	  t *arr;
	  int capacity;
	  public :
	  Stack()
	  {
	  	 nextindex=0; 
	  	 arr=new t [4];
	  	 capacity=4;
	  }
	 
//////////////////////push 
void push( t data)
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
t pop()
{
	 if(isempty())
	 { cout<<" Stack is empty"<<endl; 
	 return -1;
	 }
	 nextindex--;
	 return arr[nextindex];
}

//////////////////// top
 t top( )
 {
 	if(isempty())
 	{
 		cout<<" the Stack is empty"<<endl;
 		return 0;
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


