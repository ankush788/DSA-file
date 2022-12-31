#include<bits/stdc++.h>
using namespace std;
void subset(  int  a[],int i, int k,int n,int output[])
{
	if(i==n)
	
{int p=0;
while(p<k)
{

	 cout<<output[p]<<" ";
p++;}
	
	cout<<endl;
return;		
	}
	
	subset(a,i+1,k,n,output);
	output[k]=a[i];
	subset(a,i+1,k+1,n,output);

	
}


int  main()
{ int n;
cin>>n; 
int a[100];
for(int i=0;i<n;i++)
{

cin>>a[i];
}
int output[100];
int i=0;
int k=0;
subset(a,i,k,n,output);


return 0 ;}

