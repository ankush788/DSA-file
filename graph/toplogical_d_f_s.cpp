#include <bits/stdc++.h>
using namespace std;

void topo_d_f_s(vector<int> adj[], int sv, stack<int> &s1, vector<int> &visited)
{
    visited[sv] = 1;

    for (auto it : adj[sv])
    {
        if (visited[it] == 0)
        {
            topo_d_f_s(adj, it, s1, visited);
        }
    }
    s1.push(sv);
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

    stack<int> s1;
    vector<int> visited(v, 0);

    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == 0)
        {
            topo_d_f_s(adj, i, s1, visited);
        }
    }

    vector<int> ans;
    while (!s1.empty())
    {
        ans.push_back(s1.top());
        s1.pop();
    }

    cout << " topological is " << endl;
    for (auto it : ans)
    {
        cout << it << " --> ";
    }

    return 0;
}