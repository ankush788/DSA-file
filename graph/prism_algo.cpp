// PRISM ALGO IS used TO M.S.T
#include <bits/stdc++.h>
using namespace std;

void prism(vector<pair<int, int>> adj[], int v)
{

   vector<int> parent(v, -1);
   vector<int> visited(v, 0);

   vector<int> distance(v, 1e8);
   ///////// making  a source vertex to start
   int sv = 0;
   distance[sv] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   /////////first--> distance  , second ---> vertex

   pq.push({0, sv});

   while (!pq.empty())
   {
      pair<int, int> val = pq.top();
      pq.pop();

      visited[val.second] = 1;

      for (auto it : adj[val.second])
      {
         if ((it.second < distance[it.first]) && visited[it.first] == 0)
         {
            distance[it.first] = it.second;
            parent[it.first] = val.second;

            pq.push({distance[it.first], it.first});
         }
      }
   }

   // note include the source vertex in printing
   for (int i = 1; i < v; ++i)
   {
      cout << i << " , " << parent[i] << " --> " << distance[i] << endl;
   }
   return;
}

int main()
{
   int v, e;
   cout << " enter the vertex and edges  " << endl;
   cin >> v >> e;
   vector<pair<int, int>> adj[v];
   for (int k = 0; k < e; ++k)
   {
      int i, j, value;
      cout << " enter the edges and value" << endl;
      cin >> i >> j >> value;
      adj[i].push_back({j, value});
      adj[j].push_back({i, value});
   }
   cout << " minimum spanning tree is " << endl;
   prism(adj, v);
   return 0;
}