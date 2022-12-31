#include<bits/stdc++.h>
using namespace std;
 class dynamic_arr{
 	int index; 
 	  int *data;
 	  int capacity;
 	  public :
 	  	dynamic_arr()
 	  	{
 	  	 index=0; 
 	  data=new int[5];
 	   capacity=5;
 }
 	  	void push_back(int element)
 	  	{ if( index==capacity)
 	  	{
 	  		int *newdata= new int[2*capacity];
			   for( int i=0; i<index;i++)
			   { 
			   newdata[i]=data[i];
			   	 }  
						delete [] data;
				 data=newdata;
			
				 data[index]= element;
				 index++;
				 capacity =2*capacity;
		     }
 	  		 else 
 	  		 { data[index]= element;
 	  		 index++;
 	  		 }
				 }
		void add(int j, int element)
		{
			if ((j==index))
			{  push_back(element);
			
			}
			if(j<index)
		{
			data[j]=element;
			
		}
		if(j>index)
		{ 
		
		}
		}
		void print(int i)
		{
			 if( i<index)
			 {
			 	 cout<<data[i]<<endl;
			 	 }else
			 	 {
			 	 	 cout<< " element not found"<<endl;
				  }
			 
		}
		
 	  	
 };
int main()
{
	
dynamic_arr v1;
 v1.push_back(5);
 v1.push_back(4);
 v1.push_back(9);
 v1.push_back(3);
 v1.push_back(2);
 v1.push_back(89);
 v1.add(10,69);
 for( int i =0;i<7;i++)
 { 
 v1.print(i);
 }
 //v1.print(0);

return 0;
}

