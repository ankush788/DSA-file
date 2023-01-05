//// bellan ford algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int v, e;
    cout << " enter the vertex and edges  " << endl;
    cin >> v >> e;
    vector<pair<int, int>> adj[v];

    for (int k = 0; k < e; ++k)
    {
        int i, j, value;
        cout << " enter the edges and value " << endl;
        cin >> i >> j >> value;
        adj[i].push_back({j, value});
        // adj[j].push_back({i, value });   //// *****for  uundirected edges --> include it also ******
    }

    vector<int> distance(v, 1e8);
    int sv;
    cout << " enter the source vertex " << endl;
    cin >> sv;
    distance[sv] = 0;
    int count = 0;

    while (count != v - 1)
    {
        for (int i = 0; i < v; ++i)
        {

            for (auto it : adj[i])
            {
                if (distance[it.first] > distance[i] + it.second)
                {
                    distance[it.first] = distance[i] + it.second;
                }
            }
        }
        count++;
    }

    //////// iteration no. 'v' is use for -ve cycle detection

    for (int i = 0; i < v; ++i)
    {

        for (auto it : adj[i])
        {

            if (distance[it.first] > distance[i] + it.second)
            {
                cout << " here a negative cycle present " << endl;
                return 0;
            }
        }
    }

    for (auto it : distance)
    {
        cout << it << " --> ";
    }
    return 0;
}