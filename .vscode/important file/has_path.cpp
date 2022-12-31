#include<bits/stdc++.h>
using namespace std; 
 bool has_path( int**edges , int n , int start , int end , int* check)
 {
    check[ start]=1;
     if( start==end)
     {
         return true ; 
     }
     bool ans= false;
      for(int i = 0 ; i< n ;++i )
      { 
        if( edges[start][i]==1&&check[i]==0)
{
    ans= ans+has_path(edges, n , i ,end, check);
}
      }
      return ans;
 }
int main()
{

int n,e;
 cout<<" enter the no. of vertex --> and no. of edges-->  "<<endl ;
 cin>>n>>e; 
 int** edges = new int*[n];
 for( int i =0; i<n ;i++)
 {
      edges[i]= new int[n];
 }

  for(int k = 0 ; k<e ;k++)
{
     cout<<" enter the edge "<<endl ;
     int i, j; 
      cin>>i>>j ;
///////////////////////////////////////////
     
      
      edges[i][j]=1;
      edges[j][i]=1;
      
     
}

int *check= new int[n];
for(int i =0 ;i<n ;++i)
{ 
check[i]=0;
}
 }
