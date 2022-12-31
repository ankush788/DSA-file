#include<bits/stdc++.h>
////////agar complining me dikkat ho to file name i.e graph_traversal me space  hata dena or koi space  
// mata dena file name me and rename kare lena (for all files --> no input error problem )
using namespace std; 
 void dfs( int** edges,int n  ,int sv, int* check  )
 {
     cout<< sv <<"--> ";
      check[sv] =1;
     
  
  for( int i = 0 ;i<n ;++i)
  { 
     if(i ==sv)
     {
           continue ;
     }
  
  if(edges[sv][i]==1)
  {
      if(check[i]==0)
      { 
          dfs(edges, n , i,check);
      }
  }
  }
return ;
 }
////////////////////////////////////////////////
 void bfs(int**edges ,int n , int sv ,int *check  )
 {
      queue<int>store; 
      store.push(sv);
      check[sv]=1;
      while( !store.empty())
      {
           int val = store.front(  ); 
           store.pop(); 
          
           cout<< val <<" --> ";
           for( int i =0 ; i<n ;i++)
           {
                if(i==sv)
                {
                     continue;
                }
                 if( edges[val][i]==1)
                 {
                     if( check[i]==0)
                     {
                         check[i]=1;
                       store.push(i);


                     }
                 }
           }
      }
       
return ;
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
int store = 0 ;
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
bfs(edges ,n ,1, check );
/////we save a index for vertex visited or not 
return 0 ;
 }

