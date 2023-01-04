#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int a[10][10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        for (int i = 0; i < n; i++)

        {
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                {
                    int k = a[j][i];
                    a[j][i] = a[i][j];
                    a[i][j] = k;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    return 0;
}
