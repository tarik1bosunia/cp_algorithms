// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

//  recurtion

// int f(int idx , int target, vector<int> &profit, vector<int> &weight){

//     if(idx == 0){
//         if(weight[0] <= target) return (target / weight[0]) * profit[0];
//         else return 0;
//     }

//     int not_take = f(idx-1, target, profit, weight);

//     int take = 0;
//     if(weight[idx] <= target){
//         take = profit[idx] +  f(idx, target - weight[idx], profit, weight);
//     }

//     return max(take , not_take);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     return f(n-1, w, profit, weight);
// }

// // memorization

// int f(int idx , int target, vector<int> &profit, vector<int> &weight, vector<vector<int>> dp){

//     if(idx == 0){
//         return (weight[0] <= target) ? (target / weight[0]) * profit[0] : 0;
//     }

//     if(dp[idx][target] != -1 ) return dp[idx][target];

//     int not_take = f(idx-1, target, profit, weight, dp);

//     int take = 0;
//     if(weight[idx] <= target){
//         take = profit[idx] +  f(idx, target - weight[idx], profit, weight, dp);
//     }

//     return dp[idx][target] = max(take , not_take);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>>dp (n, vector<int>(w + 1, -1));
//     return f(n-1, w, profit, weight, dp);
// }


// tabulation

int f(int idx , int target, vector<int> &profit, vector<int> &weight, vector<vector<int>> dp){

    if(idx == 0){
        return (weight[0] <= target) ? (target / weight[0]) * profit[0] : 0;
    }

    if(dp[idx][target] != -1 ) return dp[idx][target];

    int not_take = f(idx-1, target, profit, weight, dp);

    int take = 0;
    if(weight[idx] <= target){
        take = profit[idx] +  f(idx, target - weight[idx], profit, weight, dp);
    }

    return dp[idx][target] = max(take , not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp (n, vector<int>(w + 1, 0));

    for(int j = 0; j <= w; j++){
        dp[0][j] = (weight[j] <= w) ? (w / weight[0]) * profit[0] : 0;
    }

     for(int idx = 1; idx < n; idx++){
        for(int j = 0; j <= w; j++){
                int not_take = dp[idx-1][j];

                int take = 0;
                if(weight[idx] <= j){
                    take = profit[idx] + dp[idx][j-weight[idx]];
                }

                dp[idx][j] = max(take , not_take);
        }
    }

    return dp[n-1][w];
}

