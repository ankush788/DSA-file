// Given a positive integer 'n',  find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
//1.) Subtract 1 from it. (n = n - ­1) ,
//2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
//3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).

#include <bits/stdc++.h>
using namespace std;

// recurrsive solution t.c. --> O(3^n)

int min_step(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int val1 = 1e8;
    int val2 = 1e8;
    int val3 = 1e8;
    if (n % 2 == 0)
    {
        val1 = 1 + min_step(n / 2);
    }
    if (n % 3 == 0)
    {
        val2 = 1 + min_step(n / 3);
    }

    val3 = 1 + min_step(n - 1);

    int ans = (min(val1, min(val2, val3)));

    return ans;
}

////// for memorization  t.c. --> O(n)

int min_step(int n, vector<int> &count)
{
    if (count[n] != -1)
    {
        return count[n];
    }
    if (n == 1)
    {
        count[n] = 0;
        return count[n];
    }
    int val1 = 1e8;
    int val2 = 1e8;
    int val3 = 1e8;
    if (n % 2 == 0)
    {
        val1 = 1 + min_step(n / 2, count);
    }
    if (n % 3 == 0)
    {
        val2 = 1 + min_step(n / 3, count);
    }

    val3 = 1 + min_step(n - 1, count);

    int ans = min(val1, min(val2, val3));
    cout << n << "-->" << ans << endl;
    count[n] = ans;
    return count[n];
}

int main()
{
    int n;

    cout << " enter the no. " << endl;
    cin >> n;

    cout << "answer will be " << endl;

    // vector<int> count(n+1,-1);
    // cout<<"answer will  be "<< min_step(n) <<endl ;

    // cout << " answer will be " << min_step(n, count) << endl;

    //////// for iterative call
    /*
     vector<int>store( n+1 , -1 );

        store[1] =0 ;

        for( int i = 2 ; i<=n ; i++ )
        {
            if((i%2==0 )&& (i%3==0) )
            {

                store[i] = 1+min( store[i-1] , min( store[i/2] ,store[i/3]) );
                continue;
            }

            if(i%2==0)
            {
             store[i] = 1+ min( store[i -1] , store[i/2] );
                continue;
            }

            if( i%3 ==0 )
            {
                 store[i] =1+min( store[i-1], store[i/3]);
                 continue;
            }

            store[i] = 1+store[i-1];
        }

        int i=0;
        for(auto it : store)
        {
             cout<<i<<" --> "<<it <<endl ;
             i++;
        }
        */

    return 0;
}
