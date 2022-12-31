#include<bits/stdc++.h>
using namespace std;


// max heap 
 
    class maxheap{
    	public :
        int *arr;
        int size;

        maxheap(){
        
            arr=new int[1000];
            size=-1;
        }
        int getsize();
        void print();
        void push(int x);
        int pop();
        int getMaxElement();
        bool isempty();
    };

///////////////////////////////////////////////////////push function 
    // Function to perform push operation
    void maxheap :: push(int data){
size++;
        arr[ size]=data;
     int   index=size;
         while( index>0)
         { int root= (index-1)/2;
          if(arr[root]>=arr[index])
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
    int  maxheap :: pop(){

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
        int max= 0 ;/////use to find maximum wala root
        
        while( indexleft<=size)
        {  
           
     if( arr[max]<arr[indexleft])
     {
         max=indexleft; 
     }
             if( (arr[max]<arr[indexright])&&(indexright<=size))
     {
         max=indexright; 
    
          }
    if( max ==root)
    {
         return ans;
    }
            if( root!=max)
            {
                 int temp = arr[max];
                     arr[max]=arr[root];
                arr[root]=temp; 
                root= max; 
                indexleft= (2*root)+1;
            indexright=(2*root)+2;
            }
            
      
    } 
        return ans ;
    }
//////////////////////////////////////getting the maximum element 
    int maxheap :: getMaxElement(){
        if( isempty())
        {
             return -1;
        }
        return arr[0];
       
    }
/////////////////////////////////// is empty function 

    bool maxheap :: isempty(){
 return (size==-1);
       
    }
/////////////////////////////////////get size function
 int maxheap :: getsize()
 {
 	return (size+1);
	 }
/////////////////////////////////////////print function 
void maxheap ::print( )
{ int index= 0;
 while( index<=size)
 {
 	cout<<arr[index]<<" ";
 	++index;
 }
 
	
	}    
