// int a 2-D array find cost go from (0,0)( start) --> ( m-1,n-1)(last);
#include <bits/stdc++.h>
using namespace std;

/////brute force apporach is  t.c. = O(3^m*n)
int min_cost(int **matrix, int m, int n, int x, int y)
{

    if (x == m - 1 && y == n - 1)
    {
        return matrix[x][y];
    }

    if (x >= m || y >= n)
    {
        return INT_MAX;
    }
    int val = min_cost(matrix, m, n, x + 1, y); // down

    int val1 = min_cost(matrix, m, n, x, y + 1); // right

    int val2 = min_cost(matrix, m, n, x + 1, y + 1); // digonally

    return (matrix[x][y] + min(val, min(val1, val2)));
}

/////////using memorization method  t.c. = O( m*n)
int min_cost(int **matrix, int m, int n, int x, int y, int **dp)
{

    if (x == m - 1 && y == n - 1)
    {
        return matrix[x][y];
    }

    if (x >= m || y >= n)
    {
        return INT_MAX;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    int val = min_cost(matrix, m, n, x + 1, y, dp); // down

    int val1 = min_cost(matrix, m, n, x, y + 1, dp); // right

    int val2 = min_cost(matrix, m, n, x + 1, y + 1, dp); // digonally

    dp[x][y] = (matrix[x][y] + min(val, min(val1, val2)));
    return dp[x][y];
}

int main()
{

    int m, n;
    cout << " enter the no . of row and no. of column " << endl;
    cin >> m >> n;

    int **matrix = new int *[m];

    int **dp = new int *[m];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        dp[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << " , " << j << " element " << endl;
            cin >> matrix[i][j];
            dp[i][j] = -1;
        }
    }

    cout << " answer will be -->" << min_cost(matrix, m, n, 0, 0) << endl;
    cout << " answer will be -->" << min_cost(matrix, m, n, 0, 0, dp) << endl;
    // way to pass value , (0,0) is starting point

    //// iterative or dynamic programming solution

    int ans[m][n];
    ans[m - 1][n - 1] = matrix[m - 1][n - 1]; // our destiny is ans[m-1][n-1] which is the elemenet
                                              // so , store it

    /// fill last row  , start from second last element because last element is already filled -->

    for (int i = m - 2; i >= 0; i--)
    {
        ans[i][n - 1] = ans[i + 1][n - 1] + matrix[i][n - 1];
    }

    for (int j = n - 2; j >= 0; j--)
    {
        ans[m - 1][j] = ans[m - 1][j + 1] + matrix[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            ans[i][j] = matrix[i][j] + min(ans[i][j + 1], min(ans[i + 1][j], ans[i + 1][j + 1]));
        }
    }

    cout << ans[0][0] << endl;
    return 0;
}