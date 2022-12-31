#include<bits/stdc++.h>

using namespace std;
 void merge(int a[], int i ,int j, int d)
{ 

int k=i;
int r =i; int s=d+1;
int m=0;
int n=0;
	int x[100];
	int y[100];

	while (i<=d )
	{
		x[m]=a[i];
		
		i++;
		m++;	}
while(i<=j)
	{
		y[n]=a[i];
		i++;
	n++;	
			}
	 m=0;  n=0; 

	while(r<=d&&s<=j)
		{
			if(x[m]<y[n])
			{
				a[k]=x[m];
				r++;
				m++;
			k++;	
			}
			else
			{
				a[k]=y[n];
				k++;
				n++;
			s++;
			}
			}
			
				while(r<=d)
				{
					a[k]=x[m];
					m++;
				r++;
					k++;
						}
					while(s<=j)
					{
				a[k]=y[n];
						k++;
						n++;
						s++;	
					}
				
					
}
 void merge_short(int a[],int i,int j)
{
	int n=j-i+1;
	if(i>=j)
	{cout<<"help"<<endl;
		return;
	}
	int d=(i+j)/2;
	 merge_short(a,i,d);
	
	 merge_short(a,d+1,j) ;
	 merge(a,i,j,d);
	 
	 
}
int main()
{int n;
cout<<"enter the size of array"<<endl;
cin>>n;
int a[100];
int k;
cout<<"enter the element of array"<<endl;
for( k=0;k<n;k++)
{
	cin>>a[k];
}
int i=0;
int j=n-1;

merge_short(a,i,j);
for(int k=0;k<n;k++)
{
	cout<<a[k]<<endl;
}
return 0 ;}

