#include<bits/stdc++.h>
using namespace std;
vector<int> get( int k)
{ vector<int> ans(k,1);
if(k==1)
{
	return ans;
}
for( int j=1;j<=k-2;j++)
{vector<int>help=get(k-1);

ans[j]=help[j-1]+help[j];
}
return ans;
}
int main()
{
int k;
//vector<int>ans;
cin>>k;
for(int i=1;i<=k;i++)
{
vector<int>ans=get(i);

for(int j=0;j<i;j++)
{
	cout<<ans[j]<<" ";
}
cout<<endl;
}

return 0 ;}

