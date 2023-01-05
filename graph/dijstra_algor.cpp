// /use to find the m.s.t
#include <bits/stdc++.h>
using namespace std;

void dijstra_algo(vector<pair<int, int>> adj[], int v, int sv, vector<int> &distance)
{
    vector<int> visited(v, 0);
    distance[sv] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({distance[sv], sv});
    // first -->distance  ,second --> vertex

    while (!pq.empty())
    {
        pair<int, int> value = pq.top();
        pq.pop();
        visited[value.second] = 1;

        for (auto it : adj[value.second])
        {
            if ((distance[value.second] + it.second < distance[it.first]) && (visited[it.first] == 0))
            {
                distance[it.first] = distance[value.second] + it.second;
                pq.push({distance[it.first], it.first});
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
    vector<pair<int, int>> adj[v];
    for (int k = 0; k < e; ++k)
    {
        int i, j, value;
        cout << " enter the edges and value" << endl;
        cin >> i >> j >> value;
        adj[i].push_back({j, value});
        adj[j].push_back({i, value});
    }

    cout << " enter the source vertex " << endl;
    /// source vertex vo jiske reference me minimum distance nikalunga
    vector<int> distance(v, 1e8);
    int sv;
    cin >> sv;

    dijstra_algo(adj, v, sv, distance);

    for (int k = 0; k < 3; ++k)
    {
        cout << "enter th vertex for short distance " << endl;
        int i, j;
        cin >> i >> j;

        int value = distance[i] - distance[j];
        if (value < 0)
        {
            value = -value;
        }

        cout << " the shortest distance between " << i << " , " << j << " == " << value << endl;
    }
    return 0;
}