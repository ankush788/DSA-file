#include <bits/stdc++.h>
using namespace std;

//simple fabbonacci t.c. -->O(2^n)
int fab( int n)
{ 
    if( n==0||n==1)
    {
         return n ;
    }

    return (fab(n-1)+ fab(n-2));
}

/// memorization  fabbonacci   t.c. --> O(n)
int fabbo(int n, vector<int> &visited)
{
    if (visited[n] != -1)
    {
        return visited[n];
    }

    if (n == 0 || n == 1)
    {
        visited[n] = n;
        return visited[n];
    }

    visited[n] = (fabbo(n - 1, visited) + fabbo(n - 2, visited));
    return visited[n];
}
int main()
{
    int n;
    cout << " enter the no. " << endl;
    cin >> n;
    vector<int> visited(n + 1, -1);
 
  // fab(n);
   // fabbo(n, visited);

   //////////////////for iterative solution

vector<int> store (n,-1); 

store[0] =0; 
store[1] =1;
for( int i =2 ; i<=n ; ++i )
{
 store[i] = store[i-2] +store[i-1] ;

}

    return 0;
}