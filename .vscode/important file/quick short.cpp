#include<bits/stdc++.h>
using namespace std;
void quick_sort( vector<int>&arr,int i,int j)
{
    if( i>=j)
    {
        return;
    }
     int count=0;
    int help=arr[i];
     for(int k=i;k<=j;k++)
     {
    if(help>arr[k])
    {
        count++;
    }
     }
     int shift =arr[i];
     arr[i]=arr[count+i];
     arr[count+i]=shift;
     
      int real=count+i;

int m=i;
     int n=real+1;
    while(m<real&&n<=j)
    {
        if(arr[m]<arr[real])
        {
            m++;
            
        }
        if(arr[n]>=arr[real])
        {
        	n++;
		}
    if(arr[m]>=arr[real]&&arr[n]<arr[real])
    {
        int shift2=arr[m];
        arr[m]=arr[n];
        arr[n]=shift2;
    m++;
        n++;
    }
    }
 quick_sort(arr,i,real-1);
quick_sort(arr,real+1,j);
 }

int main()
{
	vector<int>arr;
	int n;
	 cout<<"enter the size of vector"<<endl;
	 cin>>n;
	 cout<<"enter the element of array"<<endl;
	 int help;
	 for(int i=0;i<n;i++)
	 {
	 	cin>>help;
	 	arr.push_back(help);
	 }

int i=0;
int j=n-1;
quick_sort(arr,i,j);
cout<<"anser"<<endl;
for(int i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}
return 0 ;}
