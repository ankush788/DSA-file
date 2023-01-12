// Given two strings s and t. Return the minimum number of operations required to
// convert s to t.The possible operations are permitted :

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

#include <bits/stdc++.h>
using namespace std;

////////brute force apporach exponential t.c. = O(3^n)
int edit(string s, string t)
{
    int x = s.size();
    int y = t.size();

    if (s == t)
    {
        return 0;
    }

    if (x == 0 || y == 0)
    {
        return max(x, y);
    }

    if (s[0] == t[0])
    {
        return edit(s.substr(1), t.substr(1));
    }

    int val = edit(s.substr(1), t.substr(1)); // replace

    int val1 = edit(s.substr(1), t); // not first s

    int val2 = edit(s, t.substr(1)); // not first t

    return (1 + min(val, min(val1, val2)));
}

//////memorization method t.c. O(x*y)
int edit(int x, int y, string s, string t, int **ans)
{

    if (s == t)
    {
        return 0;
    }

    if (x == 0 || y == 0)
    {
        return max(x, y);
    }

    if (ans[x][y] != -1)
    {

        return ans[x][y];
    }

    if (s[0] == t[0])
    {
        ans[x][y] = edit(x - 1, y - 1, s.substr(1), t.substr(1), ans); // first dono ka same hai to
        return ans[x][y];                                              // baki par check kar lo
    }

    int val = edit(x - 1, y - 1, s.substr(1), t.substr(1), ans) + 1; // replace karke dekha kitne count

    int val1 = edit(x - 1, y, s.substr(1), t, ans) + 1; // s ka first kar dekha kitne count lagne

    int val2 = edit(x, y - 1, s, t.substr(1), ans) + 1; // t ka first replace karke dekha kitne count

    ans[x][y] = min(val, min(val1, val2)); // teeno ka min and +1

    return ans[x][y];
}

int main()
{

    string s1;
    string s2;
    cout << " enter the string " << endl;
    cin >> s1 >> s2;

    int x = s1.size();
    int y = s2.size();

    int **ans = new int *[x + 1];

    for (int i = 0; i <= x; i++)
    {
        ans[i] = new int[y];
        for (int j = 0; j <= y; j++)
        {
            ans[i][j] = -1;
        }
    }
    cout << "answer1 is --> " << edit(s1, s2) << endl;
    cout << " answer2 is --> " << edit(x, y, s1, s2, ans) << endl;

    //////////iterative solution is

    int **dp = new int *[x + 1];

    for (int i = 0; i <= x; i++)
    {
        dp[i] = new int[y + 1];

        for (int j = 0; j <= y; j++)
        {
            dp[i][j] = 1e9;
        }
    }

    for (int j = 0; j <= y; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 0; i <= x; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = (1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])));
        }
    }

    cout << "answer3 is -->" << ans[x][y] << endl;
    return 0;
}
