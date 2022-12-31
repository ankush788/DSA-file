#include<bits/stdc++.h>
using namespace std;
 template<typename t, typename v,typename w>
 class paired
 {
 	  t x ; 
 v y;
 w z;
 	 public :
 	 	void setx( t x)
 	 	{
 	 		this->x=x;
 	 		
		  }

void sety(v y)
{
	 this->y=y;
}

t getx( )
{
return x;	 
}
v gety( )
{ 
return y;
}


 };
int main()
{
 paired<paired<int,int,int >,int,int>p1; 
 paired<int,int,int>p2;
  p2.setx(10);
  p2.sety(232);

p1.setx(p2);
p1.sety(20);

 //cout<<p1.getx()<<endl;
return 0 ;}

