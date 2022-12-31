#include<bits/stdc++.h>
using namespace std;

int upper(int k,int i)
{ k=k-1;
    int current= 1;
    for(int j=k;j>(k-i);j--)
    {
        current=current*j;
    }
  return current;  
}
int lower(int i)
{
   int current=1;
    for(int j=1;j<=i;j++)
    {
        current=current*j;
    }
    return current;
}

int element(int k,int i)
{int n=upper(k,i);
 int d=lower(i);
 int ans= n/d;
 return ans;
}
vector<int> kthRow(int k) 
{
    vector<int>ans(k,1);
    for(int i=1;i<=k-2;i++)
    { int help=element(k,i);
       ans[i]=help;
    } return ans;
	// Write your code here.
} 
int main()
{
vector<int>ans;
int k;
cin>>k;

ans=kthRow(k);
for( int i=0; i<k;i++)
{
	 cout<<ans[i]<<" ";
}

return 0 ;}

