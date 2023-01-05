#include <bits/stdc++.h>
using namespace std;

void topo_b_f_s(vector<int> adj[], int sv, vector<int> &ans, vector<int> &visited, vector<int> &out)
{

    queue<int> q1;
    q1.push(sv);
    while (!q1.empty())
    {
        int val = q1.front();
        visited[val] = 1;
        q1.pop();
        ans.push_back(val);
        for (auto it : adj[val])
        {
            if (visited[it] == 0)
            {
                out[it]--;
                if (out[it] == 0)
                {
                    q1.push(it);
                }
            }
        }
    }
    return;
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
    vector<int> out(v, 0);

    for (int i = 0; i < v; ++i)
    {
        for (auto it : adj[i])
        {
            out[it]++;
        }
    }

    vector<int> ans;
    vector<int> visited(v, 0);

    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == 0 && out[i] == 0)
        {
            topo_b_f_s(adj, i, ans, visited, out);
        }
    }

    for (auto it : ans)
    {
        cout << it << " --> ";
    }

    return 0;
}