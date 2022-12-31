#include<bits/stdc++.h>
using namespace std;
int staircase(int n)
{//there n  1,2 value return is required because without it n become negative in recurrsion( staircase(n-2) , staircase(n-3)  ) and there is no base is present in code for it so segment fault will come 
   
  if(n==0)
  {
      return 1;
  }
    if(n==1)
    {
    return 1;
    
    }
 
    if(n==2)
    {
        return 2;
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}
int main()
{
int n;
cin>>n;
cout<<staircase(n);


return 0 ;}

