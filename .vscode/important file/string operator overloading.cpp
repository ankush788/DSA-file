#include<bits/stdc++.h>
using namespace std;
class strings
{
	 public:
	 	string  name; 
	 	 
	 	 void input()
	 	 {
	 	 	 cin>>this->name;
	 	 	 return;
		  }
	 	void operator= (strings S2)
	 	{
	 		 int n= S2.name.size();
	 		 int i=0;
	 		  for( i = 0; i<n;i++)
	 	{
	 		this->name[i]=S2.name[i];
	 		
	 		}
	 		this->name[i]='\0';
		 
		 return;
		 }
		 bool operator== (strings S2)
		 {
		 	 if( this->name.size()!=S2.name.size())
		 	 {
		 	 	 return false;
			  }
			  for(int i=0; i<S2.name.size() ;i++)
			  {
			  	 if( this->name[i]!=S2.name[i])
			  	 {
			  	 	 return false;
				   }
			  }
			  return true;
		 }
		bool operator< (strings S2)
		{
		return( this->name.size()<S2.name.size());	 
		}
		bool operator> (strings S2)
		{
			 return( this->name.size()<S2.name.size());
		}
		 
   strings operator+ (strings S2)
   {  strings S3;
    ///int n = this->name.size()+S2.name.size();
   char help[100];
   int i=0;
   for(  i =0 ;i<this->name.size();i++)
   {
   	 help[i]=this->name[i];
   }
   for(i =this->name.size();i<this->name.size()+S2.name.size();i++)
   {
   	 help[i]=S2.name[i];
   }
   help[i]='\0';
   for( int j=0;j<=i;i++)
   {
   	S3.name[j]=help[j];
   }

    return S3;
   
   }
 
  void print()
  {
  	 int n=this->name.size();
  	 for( int i=0;i<n;i++)
  	 {
  	 	 cout<<this->name[i];
	   }
  	return ;
  }
		 
};
int main()
{
	strings S1,S2,S3;	
	S1.input();	
	S2.input();
S3=S1+S2;
S3.print();

return 0 ;}

