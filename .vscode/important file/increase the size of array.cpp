#include<bits/stdc++.h>
using namespace std;
int  ank (int a[ ],int n,int d, int e)
{
int in= d-1;int b;
for(b=0;b<n;b++)
{
	if(b==in)
	{ break;}
for( int c=n-1;c>=b;c--)

	{
	
         a[c+1]=a[c];		
	}
	
	a[in]=e;
	      
}  return n+1;}

int main()
{
	int n,d;
	int a[100];
	cout<<" enter the size of array"<<endl;
	cin>>n;
		for(int b=0;b<n;b++)
	{
		cin>>a[b];
	}
	
	cout<<" enter the postion to place"<<endl;
	cin>>d;
	int e;
	cout<<"enter the value to enter"<<endl;
	cin>>e;
	ank(a,n,d,e);
	for(int b=0;b<=n;b++)
	{
		cout<<a[b];
	}
//how to insert value in array


return 0 ;}

