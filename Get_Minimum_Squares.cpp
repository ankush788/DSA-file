
// Given an integer N, find and return the count of minimum numbers required
//  to represent N as a sum of squares.
#include <bits/stdc++.h>
using namespace std;

/// memorization --> O(n)
int min_no(int n, vector<int> &check)
{
    if (check[n] == -1)
    {
        return check[n];
    }

    if (n == 0 || n == 1)
    {
        check[n] = n;
        return check[n];
    }

    int minimum = 1e8;

    for (int i = 0; i <= sqrt(n); ++i)
    {
        minimum = min(minimum, min_no(n - i * i, check));
    }
    check[n] = 1 + minimum;
    return check[n];
}

// brute force approach time complexity in exponential

int min_no(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int minimum = 1e8;
    for (int i = 0; i <= sqrt(n); ++i)
    {
        minimum = min(minimum, min_no(n - (i * i)));
    }
    return 1 + minimum;
}

int main()
{
    int n;
    cout << "enter the no . " << endl;
    cin >> n;

    // min_no(n) ; ----> brute force

    // min_no(n ,check); ------> memorization

    /// iterative solution
    vector<int> store(n, -1);
    store[0] = 0;
    store[1] = 1;

    for (int j = 2; j < n; ++j)
    {
        int minimum = 1e8;
        for (int i = 1; i <= sqrt(j); ++i)
        {

            minimum = min(minimum, store[j - i * i]);
        }

        store[j] = 1 + minimum;
    }

    return 0;
}