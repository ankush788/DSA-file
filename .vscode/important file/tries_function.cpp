
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

~Triesnode()
{
	for( int i =0 ;i<26 ;++i)
	{
		delete arr[ i];
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
 in the function at time of calling root any place  we use this pointer otherwise  it create error at some pointes 
 ex:- count ( without this not work properly) .... so at any place where  root ( pointer) type use  then always use this 
 pointer with this;
 
 */
////////////////////////////////////////////////insert  function     
private:
    void inserted( Triesnode*root,string word)
    {  
	if( word.size()==0)
    {  
    if( root->check==false)
    {
    
    ++(this->root->count);
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
    
inserted(this->root,word );  ///////use this->root at  place of root is appericable 
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
    return search( this->root , word); ///////use this->root at  place of root is appericable 
    }

 /////////////////////////////////////////////////////startWith function (for searching prefix) 
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
 return startsWith( this->root,prefix);
    }
//////////////////////////////////////////////////////deletion function 
private: 
 void deletion( Triesnode*root, string word )
 {
 	 if(word.size()==0)
 	 {  
	  if( root->check==true)
 	 {
	  
 	 	 --(this->root->count);
 	 }
 	 	 root->check=false;
 	 	for(int i = 0 ; i<26;++i)
 	 	{ 
 	 	
 	 	if(root->arr[i]!=NULL)
 	 	{
		  return;
		  }
 	 }
 	 delete root;
 	 root=NULL;
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
		if( root->check==false)
		{
			 for(int i =0 ;i<26;++i)
			 {
			 	 if(root->arr[i]!=NULL)
			 	 {
			 	 	 return ;
				  }
			 }
		delete root ;
		root =NULL;
		}
		
		return ;
		
 }
 public :
 ///////////////////////////////////deletion function	
  void deletion(string word)
  {
  	 deletion( root, word );
     }
   
////////////////////////////////////total function
      int total()
     {
   	 return root->count;
     }
//////////////////////////////////// isempty function   
bool isempty()
{
	 return( root->count==0);
}
};
int main()
{
	Trie * t1= new Trie();
	 t1->insert("ankush");
	 cout<<" search "<<t1->search("ankush")<<endl; 
     t1->deletion("ankush");
     cout<<" search "<<t1->search("ankush")<<endl ;
}

