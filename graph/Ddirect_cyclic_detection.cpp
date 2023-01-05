#include <bits/stdc++.h>
using namespace std;

bool d_f_s(vector<int> adj[], int sv, vector<int> &visited, vector<int> &check)
{
    visited[sv] = 1;
     check[sv] =1;
    for (auto it : adj[sv])
    {

        if (visited[it] == 0)
        {
            if (d_f_s(adj, it, visited, check))
            {
                return true;
            }
        }
        if ((visited[it] == 1) && (check[it] ==1))
        {
            return true;
        }
    }
    check[sv]=0 ;
    return false;
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
        cout << " enter the edges " << endl;
        cin >> i >> j;
        adj[i].push_back(j);
    }

    vector<int> visited(v, 0);
    vector<int> check(v, 0);

    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == 0)
        {
            if (d_f_s(adj, i, visited, check))
            {
                cout << "cycle is present " << endl;
                return 0;
            }
        }
    }

    cout << " cycle is not present " << endl;
    return 0;
}