#include<bits/stdc++.h>
using namespace std;
int p=0;
void  combination(int a[],int i, int n,int output[][100] )
{
	if( i==n)
	{  int m=0;
	while(m<n)
	{
	output[p][m]=a[m];
	m++;
	
	}
	 p++;
	return ;
	}
	
for(int k=i;k<n;k++)
	{

	int l=a[i];
	a[i]= a[k];
	a[k]=l;
	combination(a,i+1,n,output);
	
l=a[i];
	a[i]=a[k];
	a[k]=l;
} 
}
int factorial (int n)
{if(n==1)
{
	 return 1;
}
int k= n*factorial(n-1);
return k;
}

int main()
{
int a[100]; 
 int count=0;
 int n;
 
 
 cin>>n;
for(int j=0; j<n;j++)
{cin>>a[j];
}  

int output[120][100];
  int i=0;   
combination(a,i,n,output);
 int k= factorial(n);
for(int j=0;j<k;j++)
{
for( int i=0;i<n;i++)
{
	cout<<output[j][i]<<" ";

}
count++;
cout<<endl;
}

cout<<" total count"<<count;
return 0;
}

