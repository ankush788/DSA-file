// Given an integer array nums, return the length of the longest strictly increasing subsequence

#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int> &nums)
{

    int n = nums.size();

    int count = 1;
    vector<int> output(n, 1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] <= nums[j])
            {
                continue;
            }
            int possible = 1 + output[j];

            if (possible > output[i])
            {
                output[i] = possible;

                count = max(output[i], count);
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cout << " enter the size of array " << endl;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "enter the no . " << endl;
        cin >> val;
        nums.push_back(val);
    }

    cout << " Longest Increasing Subsequence -->" << lengthOfLIS(nums) << endl;
    return 0;
}