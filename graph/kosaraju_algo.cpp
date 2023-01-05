/// only possible for directed component 
#include<bits/stdc++.h>
using namespace std;
 
 void d_f_s( vector<int> adj[], int v, int sv ,vector<int>&visited, stack<int>&s1 )
 {
 visited[sv] =1;  

 for( auto it : adj[sv] )
 {
    if( visited[it]==0 ){
         
         d_f_s(adj, v ,it, visited, s1);
    }
 }

s1.push(sv) ;
 return;
 }
/////////////////////////
 void d_f_s(vector<int>adj1[] ,int v ,int sv ,vector<int>&visited)
 {
     visited[sv]= 1; 
      
      for( auto it: adj1[sv])
      {
         if( visited[it]==0)
         {
             d_f_s(adj1 ,v ,it ,visited);
         }
      }
 }

 int main()
{

    int v, e;
    cout << " enter the vertex and edges  " << endl;
    cin >> v >> e;
    vector<int> adj[v];

    for (int k = 0; k < e; ++k)
    {
        int i, j;
        cout << " enter the edges and value" << endl;
        cin >> i >> j;
        adj[i].push_back(j);
    }
 
vector<int>visited(v, 0);
 stack<int>s1 ; 

  for(int i = 0; i<v ;++i )
  {
     if( visited[i]==0 )
     {
         d_f_s( adj,v, i ,visited ,s1);
     }
      
  }

  /////////////////////// reversing the graph
 vector<int>adj1[v];
  for( int i = 0 ;i<v ;++i)
 {
    visited[i]=0;
     for( auto it : adj[ i])
     {
        adj1[it].push_back(i);
     }
 }
 
 int count = 0;  

  while(!s1.empty())
 {
    int val= s1.top();
     s1.pop(); 
     if( visited[val]==0)
     {  
        count++;
        d_f_s(adj1,v, val ,visited);
     }
 }

  cout<<" the s.c.c in this graph --> "<<count <<endl ;  
return 0;
}