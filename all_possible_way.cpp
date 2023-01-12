
#include <bits/stdc++.h>
using namespace std;

int possible_ways(int nums, int n, int val)
{
     if (pow(val, n) == nums)
     {
          return 1;
     }

     if (pow(val, n) > nums)
     {
          return 0;
     }

     return (possible_ways(nums, n, val + 1) + possible_ways(nums - pow(val, n), n, val + 1));
}

int main()
{
     int num, n;
     cout << " enter the no. and power " << endl;

     cin >> num >> n;

     int val = 1; /// 1 is used as starting point from where we start checking

     cout << "answer will be --> " << possible_ways(num, n, val) << endl;
     return 0;
}