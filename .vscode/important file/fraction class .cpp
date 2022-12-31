#include<bits/stdc++.h>
using namespace std;
int min( int a, int b)
{  if(a>=b)
{
	return b; }
	if( a<b)
	{
		return a;
	}
}
class fraction 
{
	int numerator;
	int denominator;
public :
	fraction(int numerator,int denominator)
	{ this-> numerator=numerator;
	 this-> denominator=denominator;
}
	public :
 void multiply(const fraction f2)
{
	 numerator =numerator*f2.numerator;
	 denominator=denominator*f2.denominator;
	 cout<<"multiplication is "<<numerator<<"/"<<denominator<<endl;
 } 
 void simply()
 {
 	int  gcd=1;
 	int j = min(numerator, denominator);
 for( int i=2;i<=j;i++)
 {	

 	if((numerator%i==0)&&(denominator%i==0))
 	{
 		gcd=i;
	 }
}
	 numerator=numerator/gcd;
	denominator=denominator/gcd;
 
 }

void add(const fraction &f2)
{
	 int lcm =denominator*f2.denominator;
	numerator= (numerator*f2.denominator)+(f2.numerator*denominator);
	denominator= lcm;
	simply();
	cout<<" add of fraction "<<numerator<<"/"<< denominator<<endl;
	//f2.denominator=15;
}
void display( )
{
	 cout<<numerator<<"/"<<denominator<<endl;
}

};

int main()
{ fraction f1(7,2);
fraction f2(7,2);
f1.display();
//f1.add(f2);
f1.multiply(f2);
f2.display();
f1.add(f2);
return 0 ;}

