#include <bits/stdc++.h>
using namespace std;
int real_parent(int i, vector<int> parent)
{
    if (parent[i] == i)
    {
        return i;
    }
    parent[i] = real_parent(parent[i], parent);
    return parent[i];
}
int main()
{
    int v, e;
    cout << " enter the no. of vertex and edges " << endl;
    cin >> v >> e;
    vector<int> parent(v, -1);
    for (int i = 0; i < v; ++i)
    {
        parent[i] = i;
    }

    vector<int> rank(v, 0);

    vector<int> edges[v];
    for (int k = 0; k < e; ++k)
    {
        int i, j;
        cout << " enter the edges   " << endl;
        cin >> i >> j;
        int i1 = real_parent(i, parent);
        int j1 = real_parent(j, parent);
        if (i1 == j1)
        {
            cout << " create a cycle " << endl;
            continue;
        }
        else
        {
            if (rank[i1] > rank[j1])
            {
                parent[j1] = i1;
            }
            else if (rank[i1] < rank[j1])
            {
                parent[i1] = j1;
            }

            else
            {
                rank[max(i1, j1)]++;
                parent[i1] = parent[j1] = max(i1, j1);
            }
        }
        edges[i].push_back(j);
        edges[j].push_back(i);
        // only for undirected graph
        ///////we change in parent vertex not in current vertex because if we change in current
        // not changing in parent vertex it lost the data of previous connection of vertex
        // can also introduce a cycle in it
    }

    return 0;
}