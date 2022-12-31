#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100][100]; int n;
cout<<" enter the size of array "<<endl;
cin>>n;
for(int i=0;i<n;i++ )	
{
	for(int j=0;j<n;j++)
{
	cin>>a[i][j];
}

}

int i =0;
while(i<n)
{
int j=0;
	while(i>j)
	{   int k =a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=k;
		j++;
	}

i++;}
for(int i=0;i<n;i++ )	
{
	for(int j=0;j<n;j++)
{
	cout<<a[i][j];
}
cout<<endl;
}
return 0 ;}

