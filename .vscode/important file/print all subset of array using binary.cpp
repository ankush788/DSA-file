#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;
cin>>n;
int m[100];
for(int i=0;i<n;i++)
{
	cin>>m[i];
}

string a;
 string c;
 int k=pow(2,n);
 int i;
 int count;
 int max=0;
 for(int d=k-1;d>=0;d--)
 { i=d;
c="";
count=0;
  while(i>0)
 {
if(i%2==0)
 	{
 	a ="0";	
	 }
 
 else
 {
 	 a="1";
 }
  c=a+c;
  
 i=i/2;
 count++;
 
 
}
if(max<count )
{
	max=count;
}
int j=c.size();
string p="0";
if(j<max)
{
for(int i=j;i<max;i++)
{
	c=p+c;
	}	
}
//cout<<c;
for(int i=0;i<max;i++)
{ 
	if(c[i]=='1')
{
	cout<<m[i]<<" ";
}
}
cout<<endl;
}




return 0 ;}
ww
