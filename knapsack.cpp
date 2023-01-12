
// A thief robbing a store and can carry a maximal weight of W into his knapsack.
// There are N items and ith item weigh wi and is of value vi.What is the maximum value V,
//  that thief can take ?
#include <bits/stdc++.h>
using namespace std;

///////////// brute force approach is t.c --> expoential

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxi)
{

    if (n == 0 || maxi == 0)
    {
        return 0;
    }

    if (weight[n - 1] <= maxi)
    {
        int val = value[n - 1] + knapsack(weight, value, n - 1, (maxi - weight[n - 1]));

        int val1 = knapsack(weight, value, n - 1, maxi);
        return max(val, val1);
    }

    return knapsack(weight, value, n - 1, maxi);
}

/////////memorization  t.c. = O(maxi*maxi)
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxi, int **dp)
{

    if (n == 0 || maxi == 0)
    {
        return 0;
    }

    if (dp[n][maxi] != -1)
    {
        return dp[n][maxi];
    }

    if (weight[n - 1] <= maxi)
    {
        int val = value[n - 1] + knapsack(weight, value, n - 1, (maxi - weight[n - 1]), dp);

        int val1 = knapsack(weight, value, n - 1, maxi, dp);
        dp[n][maxi] = max(val, val1);
        return dp[n][maxi];
    }

    dp[n][maxi] = knapsack(weight, value, n - 1, maxi, dp);
    return dp[n][maxi];
}

int main()
{
    vector<int> value;
    vector<int> weight;

    int n;
    cout << " enter the size " << endl;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "enter the value  --> " << endl;
        int val;
        cin >> val;
        weight.push_back(val);
    }

    for (int i = 0; i < n; i++)
    {

        cout << "enter the weight  --> " << endl;

        int val;
        cin >> val;
        value.push_back(val);
    }

    int maxi;
    cout << " enter the max storage value " << endl;

    cin >> maxi;

    int **dp = new int *[maxi + 1];

    for (int i = 0; i <= maxi; i++)
    {
        dp[i] = new int[maxi + 1];

        for (int j = 0; j <= maxi; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "answer1 --> " << knapsack(weight, value, n, maxi, dp) << endl;

    cout << "answer2 --> " << knapsack(weight, value, n, maxi) << endl;

    /// iterative solution

    int ans[n + 1][maxi + 1];

    ///// first --> index , second --> maxi

    for (int i = 0; i <= n; i++)
    {
        ans[i][0] = 0;
    }

    for (int i = 0; i <= maxi; i++)
    {
        ans[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxi; j++)
        {

            if (weight[i - 1] <= j)
            {
                ans[i][j] = max(value[i - 1] + ans[i - 1][j - weight[i - 1]], ans[i - 1][j]);
                continue;
            }

            ans[i][j] = ans[i - 1][j];
        }
    }

    cout << " answer3 is --> " << ans[n][maxi] << endl;
    return 0;
}