#include<bits/stdc++.h>
using namespace std;
 string strl( char n)
{
	if(n=='1')
	{
		return "@#*&";
	}
	if(n=='2')
	{
		return "abc";
	}
	if(n=='3')
	{
		return "def";
	}
	
	if(n=='4')
	{
		return "ghi";
	}
if(n=='5')
	{
		return "jkl";
	}
	if(n=='6')
	{
		return "mno";
	}
	if(n=='7')
	{
		return"pqrs";
	}
	if(n=='8')
	{
		return "tuv";
	}
	if(n=='9')
	{
		return "wxyz";
	}
	else{ return " ";
	}
	
}
int subs( string a,string b[])
{
	if(a.size()==0)
	{
		return 1 ;
		
	}
	
string n= strl(a[0]);

string d=a.substr(1);	
	
	int k =subs( d,b);
  string  temp[1000];
int p=0;

	
	int r=n.size();


for(int j=0; j<k;j++)
{for(int i=0;i<r;i++)
{
temp[p]=n[i]+b[j];


	p++;
} } 

for(int i=0; i<p;i++)
{
	b[i]=temp[i];
}

return r*k;
}

int main()
{ 
string  a;
cin>>a;

string l;
  string b[100];
                                                                                                                                          
int k= subs(a,b);
 
for(int i=0;i<k;i++)
{
	cout<<b[i]<<endl;
} 
return 0 ;}

