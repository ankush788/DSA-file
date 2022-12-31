
#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[1000], b[1000];
int n;
cin>>n;
for(int c=0;c<n;c++)
{
	cin>>a[c];
	
}

for( int k=0;k<n;k++)
{ int i=0;
int j=1;
	while(j<n)
{
if(a[i]>a[j])
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}

i++;
j++;


} }
int k=0;
int i=0;
int j=1;
while(j<n)
{
 if(a[i]!=a[j])
 {
 b[k]=a[i];
 //b[k+1]=a[j];	
k++;}
i++;
j++;
} 
b[k]=a[n-1];
cout<<"START";
for( i=0;i<n;i++)
{
	cout<<b[i]<<endl;
	
}
return 0 ;}

