// Given two sequences,find the length of longest subsequence present in both of them.
// Both the strings are of uppercase.
#include <bits/stdc++.h>
using namespace std;
////brute force apporach

int lcs(string s1, string s2)
{
    int x = s1.size();
    int y = s2.size();
    if (x <= 0 || y <= 0)
    {
        return 0;
    }

    if (s1[0] == s2[0])
    {
        return (1 + lcs(s1.substr(1), s2.substr(1)));
    }

    int val = lcs(s1.substr(1), s2);
    int val1 = lcs(s1, s2.substr(1));

    return max(val, val1);
}

//////// using memorization t.c. = O( x*y);
int lcs(int x, int y, string s1, string s2, int **dp)
{
    // your code here
    if (x == 0 || y == 0)
    {
        return 0;
    }

    if (dp[x][y] != -1)
    {

        return dp[x][y];
    }

    if (s1[0] == s2[0])
    {
        dp[x][y] = (1 + lcs(x - 1, y - 1, s1.substr(1), s2.substr(1), dp));
        return dp[x][y];
    }

    dp[x][y] = max(lcs(x - 1, y, s1.substr(1), s2, dp), lcs(x, y - 1, s1, s2.substr(1), dp));

    return dp[x][y];
}

int lcs(int x, int y, string s1, string s2)
{

    int **dp = new int *[x + 1];

    for (int i = 0; i <= x; i++)
    {
        dp[i] = new int[y + 1];

        for (int j = 0; j <= y; j++)
        {
            dp[i][j] = -1;
        }
    }

    return lcs(x, y, s1, s2, dp);
}

int main()
{

    string s1;
    string s2;

    cout << " enter the string s1 and s2 " << endl;
    cin >> s1 >> s2;
    cout << " answer1 will be  --> " << lcs(s1.size(), s2.size(), s1, s2) << endl;

    cout << " answer2 will be --> " << lcs(s1, s2) << endl;

    ///////////using iterative method
    int x = s1.size();
    int y = s2.size();

    int ans[x + 1][y + 1];

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            ans[i][j] = 0;
        }
    }

    for (int i = 1; i <= x; ++i)
    {
        for (int j = 1; j <= y; j++)

        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[i][j] = 1 + ans[i - 1][j - 1];
                continue;
            }

            ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
        }
    }
    cout << " answer3 will be --> " << ans[x][y] << endl;

    return 0;
}