#include<bits/stdc++.h>
using namespace std;
int main()
{ int a,b,c,g,z;
cin>>z;
a=z/2+1; g=z/2;
 b=1;
  while(b<=a)
{ c=1;
  
   while(c<=a-b) 
   {
   
cout<<" ";
 c++;
}
	c=1;
	while(c<=b)
	{
		 cout<<"*";
		 c++;
	}
c=1; 
 while( c<=b-1)
  {
  	cout<<"*";
  	c++;
	  }	cout<<endl;
	  b++;}
	  
	  
	  b=1;
	while(b<=g)
	{ 
		c=1;
	while(c<=b)
	{
		 cout<<" ";
		 c++;
	}	
	c=g-b+1;
	while( c>=1)	
		{
			cout<<"*";
			c--;
		}
		c=g-b;
		while( c>=1)
		{ cout<<"*";
		c--;
		}
		
		 cout<<endl;
		 b++;
	}


return 0 ;}




