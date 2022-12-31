#include<bits/stdc++.h>
using namespace std;

void ank(int a,int f)
{

int c,b;
cout<<"enter the first array"<<endl;
int d[100]; int e[100];

for( b=0; b<a; b++)
{
	cin>>d[b];
	
}
cout<<" enter the array 2"<<endl;

for( c=0;c<f;c++)
{
	cin>>e[c];
	
}

for( b=0;b<a;b++)
{
	for( c=0;c<f;c++)

{
	if(d[b]==e[c])
	{
		cout<<d[b]; break;
	}
}}   

}


int main()
{ int a,f, j;
cout<<" no. of test conducted "<<endl;
cin>>j;
for( int c=0; c<j; c++)
{
	cin>>a;
	cin>>f;
	ank(a,f);
	cout<<" done";
}



return 0 ;}

