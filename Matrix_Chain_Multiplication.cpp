// Given a chain of matrices A1, A2, A3, .....An, you have to figure out the most efficient way to
// multiply these matrices i.e.determine where to place parentheses to minimise the
// number of multiplications.You will be given an array p[] of size n + 1.
//  Dimension of matrix Ai is p[i - 1] * p[i].You need to

#include <bits/stdc++.h>
using namespace std;

int mini(int *arr, int start, int end, int **dp)
{
    if (end - start <= 1)
    {
        return 0;
    }

    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int minimum = 1e9;

    ///
    for (int i = start + 1; i < end; i++)
    {
        int val = mini(arr, start, i, dp) + mini(arr, i, end, dp) + (arr[start] * arr[i] * arr[end]);

        minimum = min(minimum, val);
    }
    dp[start][end] = minimum;
    return minimum;
}
int main()
{
    int n;
    cout << " enter the no. in array  " << endl;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {

        cout << " enter the no. " << endl;
        cin >> arr[i];
    }

    return 0;
}