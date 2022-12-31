#include<bits/stdc++.h>
using namespace std;
int main()
{ 

int i,j,n,d;
cin>>d;

n=(d)/2;

	
	for(i=1;i<=n;i++)
	{ 
	int d=i;
	for(j=1;j<=i;j++)
	{ if(j==1||j==i)
		{
		cout<<"*";}
		
		else{ cout<<" ";
		}
	}
	
	for( j=n-i;j>0;j--)
	
	{
		cout<<" ";
		
		
	} 
	
	for(j=n-i;j>0;j--)

	{
		cout<<" ";
	}
for(j=1;j<=i;j++)
{    if(j==1||j==i)
{
		cout<<"*";
}

else{
	cout<<" ";
}
}



cout<<endl;	}

n=d/2;
	for(i=1;i<=n;i++)
	{ 
	
	for(j=n-i;j>=0;j--)
	{   if(j==n-i||j==0)
		{
		cout<<"*";}
		else{
			cout<<" ";
		}
	}
	
	for( j=1;j<i;j++)
	
	{
		cout<<" ";
		
		
	}
	for(j=1;j<i;j++)

	{ 
	
		cout<<" ";

	}

for(j=n-i;j>=0;j--)
{ if( j== n-i||j==0)
{
		cout<<"*";}

else{
	cout<<" ";
}
}
cout<<endl;}



return 0 ;}

