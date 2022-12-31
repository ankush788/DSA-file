#include<bits/stdc++.h>
using namespace std;
int main()
{
int  b=0,n,c,d=0;
 int a[100];
 cout<<"enter the size of array"<<endl;
 cin>>n;
 cout<<"enter the array value"<<endl;
 for(int c=0;c<n;c++)
{
	cin>>a[c];
}
for(int e=0;e<n-1;e++)
{ 
	for(b=d;b<n;b++)
	{
if(a[b]<a[d])	
	{
		int k =a[b];
		a[b]=a[d];
	a[d]=k;
	}
	}
   d++;} 
for(int e=0; e<n;e++)
{
	cout<<a[e];
}






return 0 ;}

