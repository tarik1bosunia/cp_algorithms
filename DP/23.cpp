// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;


// recursive
// long f(int* denominations, int idx , int target)
// {
//     if(idx == 0){
//         return (target % denominations[idx] == 0);
//     }

//     long not_take = f(denominations, idx-1, target);

//     long take = 0;

//     if(denominations[idx] <= target)
//         not_take = f(denominations, idx, target - denominations[idx]);

//     return take + not_take;    
// }


// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     return f(denominations, n-1, value);
// }


// memoriztion 

// long f(int* denominations, int idx , int target, vector<vector<long>>& dp)
// {
//     if(idx == 0){
//         return (target % denominations[idx] == 0) ? 1 : 0;
//     }

//     if(dp[idx][target] != -1) return dp[idx][target];

//     long not_take = f(denominations, idx-1, target, dp);

//     long take = 0;

//     if(denominations[idx] <= target)
//         take = f(denominations, idx, target - denominations[idx], dp);

//     return dp[idx][target] = take + not_take;    
// }


// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     vector<vector<long>> dp(n, vector<long> (value + 1, -1));
//     return f(denominations, n-1, value, dp);
// }



// tabulation

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value + 1, 0));

    for(int t = 0; t <= value; t++){
        dp[0][t] =(t % denominations[0] == 0) ? 1 : 0;
    }

    for(int idx = 1; idx < n; idx++){
        for(int t = 0; t <= value; t++){
            long not_take = dp[idx-1][t];
            long take = (denominations[idx] <= t) ? dp[idx][t-denominations[idx]] : 0;

            dp[idx][t] = take + not_take;
        }
    }
    return dp[n-1][value];
}

// memory optimized

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> pre (value + 1, 0);

    for(int t = 0; t <= value; t++){
        pre[t] =(t % denominations[0] == 0) ? 1 : 0;
    }

    for(int idx = 1; idx < n; idx++){
        for(int t = 0; t <= value; t++){
            long not_take = pre[t];
            long take = (denominations[idx] <= t) ? pre[t-denominations[idx]] : 0;

            pre[t] = take + not_take;
        }
    }
    return pre[value];
}


