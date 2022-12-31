#include<bits/stdc++.h>
using namespace std;
int main()
{

int  n,a,b,c,d=0,e,f=0, count=0;
cout<<" enter the value of no."<<endl;
cin>>a;
while(a>0)
{ c=a%2;
d=d*10+c;
 a=a/2;count++;} 
 
for(b=1;b<=count;b++)
{e=d%10;
f=f*10+e;
d=d/10;
}
cout<<f;
return 0 ;}

