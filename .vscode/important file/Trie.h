#include<bits/stdc++.h>
using namespace std;
/////////////////////////Triesnode class which is use to store data ;
class Triesnode{
public:
char data; 
 Triesnode* arr[26]; 
 bool check ;
  int count ;
 public:
Triesnode() {
    data= '\0';
    count =0; 
    check=0;
    for(int i=0 ;i<26;i++)
    { 
	arr[i]=NULL;
	
}
    }
    Triesnode( char data)
    {  
         this->data= data;
       count =0;
          check=0;
          for(int i=0 ;i<26;i++)
    { 
	arr[i]=NULL;
}

    }
};
///////////////////////////////////////////////////Trie class use for root to use us head of acesss all data
class Trie
{ public:
    Triesnode* root;
    
 Trie()
 { 
 root =new Triesnode('\0');
 }
 /*
 
 
 */
////////////////////////////////////////////////insert  function     
private:
    void inserted( Triesnode*root,string word)
    {  
	if( word.size()==0)
    {  
    if( root->check==false)
    {
    ++(this->root->count);/////there this is required to mention because there root indicate not orginal root but
	// recursion root  so...this->root indicate the object root( real/main ) root in which we want change our count 
    }
	     root->check= 1;
         
          
       return ;
    }
     int index =word[0]-'a'; 
     if( root->arr[ index]!=NULL)
     {
         inserted(root->arr[index],word.substr(1)); 
     }
     else{
        root->arr[index]= new Triesnode(word[0]);
         inserted( root->arr[index],word.substr(1));
     }
          return ; 
    }
    
public:
    
void insert(string word) {
    
inserted(root,word );  ///////use this->root at  place of root is appericable 
        return; 
    }

 ////////////////////////////////////////search function 
 private:  
  bool search( Triesnode*root, string word )
  {
      
	   if( word.size()==0)
       {   if((root->check)==true){
	   
           return true;
       }
       return false;
       }
       int index =word[0]-'a';
     return ( (root->arr[index]!=NULL)&&search(root->arr[index],word.substr(1)));
  }
  
 public:
    bool search(string word) {
    return search( root , word); ///////use this->root at  place of root is appericable 
    }

 /////////////////////////////////////////////////////startWith function (for searching prefix) 
    private:
	 bool startsWith(Triesnode*root,string word)
     {
     	 if( word.size()==0)
       {   return true;
       }
       int index =word[0]-'a';
      
     return ( (root->arr[index]!=NULL)&&search(root->arr[index],word.substr(1)));
	 }
 public:	 
    bool startsWith(string prefix) {
 return startsWith( root,prefix);
    }
//////////////////////////////////////////////////////deletion function 
private: 
 void deletion( Triesnode*root, string word )
 {
 	 if(word.size()==0)
 	 {  
	  if( root->check==true)
 	 {
	  
 	 	 --(this->root->count);/////there this is required to mention because there root indicate not orginal root but
	// recursion root  so...this->root indicate the object root( real/main ) root in which we want change our count 
 	 	 
 	 }
 	 	 root->check=false;
 	 	 
 	 	
		   return ;
	  }
	   int index= word[0]-'a';
	    if(  root->arr[index]!=NULL)
	    {
	    deletion( root->arr[index],word.substr(1));	  
		}
		else
		{
			return ;
		}
		
		return ;
		
 }
 public :
 ///////////////////////////////////deletion function	
  void deletion(string word)
  {
  	 deletion( root, word );
  }
   
   /////////////////////////////total function
   int total()
   {
   	 return root->count;
   }
 ////////////////////////// isempty function   
bool isempty()
{
	 return( root->count==0);
}
};

