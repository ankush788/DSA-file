#include<bits/stdc++.h>
using namespace std;

int main()
{ char ank[100];
int n;
cin.getline(ank,100);
cout<<"enter the size of array"<<endl;
cin>>n;
int i=0, j=n-1;
while(i<=j)
{
	char k=ank[i];
	ank[i]=ank[j];
	ank[j]=k;
i++;j--;
} 


int b=0,start=0, end=0;
for(b=0;b<n;)
{
	while(b<n&&ank[b]==' ')
{
	b++;
} start =b;
while(b<n&&ank[b]!=' ')
{ b++;
	
}  end=b-1;
while(start<=end)
{char k=ank[start];
ank[start]=ank[end];

ank[end]=k;
start++;end--;}
}
cout<<ank;

return 0 ;}

