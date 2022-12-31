#include<bits/stdc++.h>
using namespace std;
 
 class salary
  { public:
   
  int paygrade;
   	salary( int n )
   	{ paygrade= n*1000;
	   }
  	 
  };
  
  
  class employee 
  {
  	 public :
  	int employee_id;
  	employee()
  	{ 
	  
    }
  		}; 
  class faculty:public employee,public salary 
 { 
 	public:
	  string name ;
	 faculty(string name, int n):salary(n)
	 {
	 this->name= name;	
	 }
	 
   void print( ) 
   {
   	  cout<<" name of employee is "<<this->name<<endl ;
   	  cout<<" salary of the employee is "<< paygrade<<endl;
	   }	
 };
int main()
{
faculty f1( "ankush",3);
f1.print();

return 0 ;}

