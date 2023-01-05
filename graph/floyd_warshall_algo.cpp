#include <bits/stdc++.h>
using namespace std;

int main()
{

    int v, e;
    cout << " enter the vertex and edges  " << endl;
    cin >> v >> e;
    int adj[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; ++j)
        {
            if (i == j)
            {
                adj[i][j] = 0;
                continue;
            }
            adj[i][j] = 1e8;
        }
    }

    for (int k = 0; k < e; ++k)
    {
        int i, j, value;
        cout << " enter the edges and value" << endl;
        cin >> i >> j >> value;
        adj[i][j] = value;
    }

    for (int k = 0; k < v; ++k)
    {
        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < v; ++j)
            {
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (adj[i][j] != 1e8)
            {
                cout << i << " --> " << j << " = " << adj[i][j] << endl;
            }
        }
    }

    return 0;
}