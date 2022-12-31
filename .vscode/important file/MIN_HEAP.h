#include<bits/stdc++.h>
using namespace std;


// min heap 
 
    class minheap{
    	public:
        int *arr;
        int size;

        minheap(){
            arr=new int[1000];
            size=-1;
        }
        void print(); 
        int getsize();
        void push(int x);
        int  pop();
        int getminElement();
        bool isempty();
    };

///////////////////////////////////////////////////////push function 
    // Function to perform push operation
    void minheap :: push(int data){
size++;
        arr[ size]=data;
     int   index=size;
         while( index>0)
         { int root= (index-1)/2;
          if(arr[root]<=arr[index])
          {
              return ;
          }
           else
           { int temp= arr[root]; 
            arr[root]= arr[index]; 
            arr[ index] =temp ;
                index =root;
           }
             
             
         }
        return ;
       
    } 

///////////////////////// Function to pop operation
    int minheap :: pop(){

         if(isempty())
         { return -1 ;
             
           }
           int ans = arr[0];
        int temp =arr[ size];
         arr[ size ] =arr[ 0];
         arr[ 0]=temp;
        --size; 
        
         
          int root =0;
        int indexleft= (2*root)+1;
            int indexright=(2*root)+2;
        int min= 0 ;/////use to find minimum wala root
        while( indexleft<=size)
        {  
           
     if( arr[min]>arr[indexleft])
     {
         min=indexleft; 
     }
             if( (arr[min]>arr[indexright])&&(indexright<=size))
     {
         min=indexright; 
    
          }
    if( min ==root)
    {
         return ans;
    }
            if( root!=min)
            {
                 int temp = arr[min];
                     arr[min]=arr[root];
                arr[root]=temp; 
                root= min; 
                indexleft= (2*root)+1;
            indexright=(2*root)+2;
            }
            
      
    } 
        return ans  ;
    }
//////////////////////////////////////getting the minimum element 
    int minheap :: getminElement(){
        if( isempty())
        {
             return -1;
        }
        return arr[0];
       
    }
/////////////////////////////////// is empty function 

    bool minheap :: isempty(){
 return (size==-1);
       
    }
////////////////////////////////////////// getsize function 
 int minheap::  getsize( )
 {
 	 return ( size+1);
	 }    
//////////////////////////////////////// print function 
 void  minheap:: print()
 {
 	int index= 0 ;
 	 while( index<=size)
 	 {
 	 	 cout<<arr[index]<<" ";
 	 	  ++index;
	  }
 	
		 	  return ;
		 }
/////////////////////////////////////////		 
