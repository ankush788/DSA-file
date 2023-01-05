#include <bits/stdc++.h>
using namespace std;

void bridge(vector<int> adj[], int sv, int par_sv, int &count, vector<int> &lower, vector<int> &parent, vector<int> &visited)
{
    parent[sv] = par_sv;
    lower[sv] = count;
    count++;
    visited[sv] = 1;
    for (auto it : adj[sv])
    {
        if (visited[it] == 0)
        {
            bridge(adj, it, sv, count, lower, parent, visited);
        }
    }

    if (parent[sv] != -1)
    {
        for (auto it : adj[sv])
        {
            if (it != parent[sv])
            {
                lower[sv] = min(lower[sv], lower[it]);
            }
        }

        if (lower[sv] > lower[parent[sv]])
        {
            cout << sv << " --> " << parent[sv] << endl;
        }
    }

    return;
}
int main()
{
    int v, e;
    cout << "enter the no. of vertex and edges " << endl;
    cin >> v >> e;
    vector<int> adj[v];

    for (int k = 0; k < e; ++k)
    {
        int i, j;
        cout << " enter the edges " << endl;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    vector<int> visited(v, 0);
    vector<int> lower(v, 0);
    vector<int> parent(v, -1);
    int count = 0;

    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == 0)
        {
            bridge(adj, i, -1, count, lower, parent, visited);
        }
    }

    return 0;
}