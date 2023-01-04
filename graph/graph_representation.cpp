#include <bits/stdc++.h>
using namespace std;

int main()
{
  int v, e;
  cout << "enter the no. of edges and vertex " << endl;
  cin >> v >> e;
  int choose;
  cout << " enter how to store the 0--> adjcent matrix , else--> adjcency list " << endl;
  cin >> choose;
  if (choose == 0)
  {
    cout << " adjcency matrix " << endl;
    int edges[v][v] = {0};
    for (int k = 0; k < e; k++)
    {
      int i, j, value;
      cout << " enter the edges and value" << endl;
      cin >> i >> j >> value;
      edges[i][j] = value;
      edges[j][i] = value; //---> for undirected graph only
    }
  }
  else
  {
    cout << " adjcency list " << endl;
    vector<int> edges[v];
    for (int k = 0; k < e; ++k)
    {
      int i, j, value;
      cout << " enter the edges and value  " << endl;
      cin >> i >> j >> value;
      edges[i].push_back(value);
      edges[j].push_back(value); // only for undirected graph
    }
  }

  return 0;
}