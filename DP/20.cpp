// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// int f(vector<int> weight, vector<int> value, int idx, int maxWeight){

//     if(idx == 0) {
//         if(weight[0] <= maxWeight){
//             return value[0];
//         }else {
//             return 0;
//         }
//     }


//     int not_take = f(weight, value, idx -1, maxWeight);
//     int take  = 0;
//     if(weight[idx] <= maxWeight)
//         take = value[idx] +  f(weight, value, idx -1, maxWeight - weight[idx]);


//     return max(take, not_take);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	return f(weight, value, n-1, maxWeight);
// }


// /* ================== memorization ===============*/

// int f(vector<int> weight, vector<int> value, int idx, int maxWeight, vector<vector<int>> & dp){

//     if(idx == 0) {
//         if(weight[0] <= maxWeight){
//             return value[0];
//         }else {
//             return 0;
//         }
//     }

//     if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

//     int not_take = f(weight, value, idx -1, maxWeight, dp);
//     int take  = 0;

//     if(weight[idx] <= maxWeight)
//         take = value[idx] +  f(weight, value, idx -1, maxWeight - weight[idx], dp);


//     return dp[idx][maxWeight] =  max(take, not_take);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));

// 	return f(weight, value, n-1, maxWeight, dp);
// }


/* ================== tabulation ===============*/

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
//     for(int i = weight[0]; i <= maxWeight; i++){
//         dp[0][i] = value[0];
//     }

//     for(int idx = 1; idx < n; idx++){
//         for(int maxW = 0; maxW <= maxWeight; maxW++){
//             int not_take = dp[idx-1][maxW];
//             int take  = INT_MIN;
//             if(weight[idx] <= maxW)
//                 take = value[idx] +  dp[idx-1][maxW - weight[idx]];
//             dp[idx][maxW] =  max(take, not_take);
//         }
//     }


// 	return dp[n-1][maxWeight];
// }


/* ============== memory optimized ====================*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> pre(maxWeight+1, 0), curr(maxWeight+ 1, 0);

    for(int i = weight[0]; i <= maxWeight; i++){
        pre[i] = value[0];
    }

    for(int idx = 1; idx < n; idx++){
        for(int maxW = 0; maxW <= maxWeight; maxW++){
            int not_take = pre[maxW];
            int take  = INT_MIN;
            if(weight[idx] <= maxW)
                take = value[idx] +  pre[maxW - weight[idx]];
            curr[maxW] =  max(take, not_take);
        }
        pre = curr;
    }


	return pre[maxWeight];
}