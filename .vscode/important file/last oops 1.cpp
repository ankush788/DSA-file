#include<bits/stdc++.h>
using namespace std;
class salary 
{
	 public: 
	 int pay;  
	 salary  ( int paygrade )
	 {
	 	 pay = paygrade *1200;
	 }
	 virtual  void print( )=0;
}; 
////////////////////////////////

  class faculty:public salary {
  public: 
  string name;
    faculty(int paygrade,string name): salary (paygrade)
   {
   this->name= name;
}
void print(  )
{
	 cout<<" name of the employe  is "<<this->name<<endl ;
	 cout<<" salary of employe  is "<<pay <<endl ;
}
};

int main()
{
faculty f1 ( 4200,"ankush ");
 f1.print();
 

return 0 ;}

