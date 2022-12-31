#include<bits/stdc++.h>
using namespace std;
 class node 
 { public:
 	 string key ; 
 	  int data; 
 	  node* next ;
 	  node( string key,int value )
 	  { this->key =key;
 	  	 data  =value  ; 
 	  	  next =NULL;
	   }
	    ~node()
	    {
	    	 delete next; 
		}
	   
 };
   class ourmap
   { 
   	 node** bucket; 
   	  int size ; 
   	    int count ; 
   	    double loadfactor; 
   	    public:
   	    ourmap( )
   	    {
   	    	 size =5;
   	    	 bucket= new node* [size];
   	    	  for( int i = 0 ; i<size; i++)
   	    	  {
   	    	  	
   	    	  	bucket[i]= NULL;
   	    	  	 
				 }
   	    	  count =0; 
   	    	   loadfactor =0.00;
   	    	   
		   }
		   ~ourmap()
		   {
		   	 for(int i=0 ;i<size;i++)
		   	 {
		   	 	 delete bucket[ i];
				}
				 delete [] bucket;
			} 
//////////////////////////////////////////////////////////		   
		   private:
		   	  int hashcode( string key)
		   	  {int index =0;
		   	  int  base = 1;
		   	  for( int i= key.size()-1; i>=0;i--)
		   	  {
		   	  	 index =index+ base* key[i];
		   	  	 index= index%size ; 
		   	  	   base=base* 37;
		   	  	   base=base%size; 
				 }
		   	    index= index%size;
		   	  	
		   	  	
		   	  	return index; 
				 }
////////////////////////////////
void rehashing( )
{
	 int oldsize= size ;
	 node** temp = bucket; 
	this->size=2*oldsize;
	 bucket= new node*[ size];
	 
	 for( int i=0 ;i<size;i++)
	 { 
	 bucket[ i]=NULL;	 
	 }
	 count=0;
	 for( int i= 0 ;i<oldsize;i++)
	 {
	 	 node* putter=temp[i];  
	 	 while( putter!= NULL)
	 	 { 
		  insertion( putter->key,putter->data);
		  
		  putter =putter->next;
	 }
}

///////previous array delelte 
 for( int i = 0; i<oldsize;i++)
 {
 	 node* take = temp [ i ]; 
 	 delete take ;
 }
delete []  temp;
}

////////////////////////////////////////////				 
		   public :
		void insertion( string key , int value)
		{
			int index = hashcode( key); 
			node* head = bucket[index]; 
			while(head!=NULL)
			{
				if(head->key== key)
			{
			
					 head->data= value;
					  return ;
			}
				
				
				head= head->next; 
			}
			
		
		head= bucket[index]; 
		node*Node= new node (  key , value);
		 Node->next= head ;  
		 bucket[index]= Node;
		 
		 count++;
		 loadfactor= (count*1.00)/size ; 
		 if( loadfactor>0.7)
		 { 
		 rehashing();
		 }
		  
	return ;
}
////////////////////////////////////////////////////

int remove( string key)
{
	 int index= hashcode( key); 
	 node*head = bucket[index];
	 node* previous=NULL; 
	  while(head!=NULL)
	  { if( head->key == key)
	  	{   
	  	count--;
	  	 if( previous ==NULL)
	  	 {
	  	 	 bucket[index]= head->next;
	  	 	 int ans= head->data;
	  	 	 head ->next = NULL;
	  	 	  delete head; 
	  	 	  return ans;
		   }
		   else{
		   	previous ->next= head->next ;
		   	 int ans  =  head->data; 
		   	 head->next =NULL; 
		   	  delete head; 
		   	  return ans ;
		   }
	  		
		  }
		  
		  previous= head;
		   head=head->next;
	  	 
	  }
	  return -1; 
	  }
///////////////////////////////////////////////////////////////////////////	
	int  get( string key)
	{
		 int index = hashcode(key); 
		 node* head =bucket[index]; 
		 while( head!=NULL)
		 {  if( head->key ==key)
		 { return head->data;
		 
		 }
		 	head=head->next;
			 
			 }
			 
			 return -1;
			 	}
			 	
	int getsize( )
	{
		 return count ; 
	}
	
	bool  isempty( )
	{
		 return( count==0);
	}
///////////////////////////////////////////////////// 
 double loadview()
  { cout<<"current size"<<this->size<<endl ;
  	 return this->loadfactor;
  }
  
//////////////////////////////////////////
   };

