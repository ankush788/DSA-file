// Given a binary matrix mat of size n *m,
// find out the maximum size square sub - matrix with all 1s.

#include <bits/stdc++.h>
using namespace std;
int maxSquare(int n, int m, vector<vector<int>> mat)
{

    int arr[n][m];
    int minima = 0;

    for (int i = 0; i < n; i++)
    {

        arr[i][0] = mat[i][0];

        minima = max(minima, arr[i][0]);
    }

    for (int j = 0; j < m; j++)
    {
        arr[0][j] = mat[0][j];

        minima = max(minima, arr[0][j]);
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < m; j++)
        {
            if (!mat[i][j])
            {
                arr[i][j] = 0;
                continue;
            }
            arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;

            minima = max(minima, arr[i][j]);
        }
    }
    return minima;
}

int main()
{
int n, m;

    cout << " enter row and column" << endl;
    cin >> n >> m;
    vector<vector<int>>mat(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cout << "enter " << i << "-->" << j << endl;
            cin >> val;
            mat[i].push_back(val);
        }

    }

    cout << "answer will be " << maxSquare(n, m, mat) << endl;

return 0;
}