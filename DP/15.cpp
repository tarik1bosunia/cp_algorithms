// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// /* =========== Recurtion ============*/

// bool f(int idx, int target, vector<int> &arr){
//     if(target == 0) return true;

//     if(target < 0) return false;

//     if(idx == 0) 
//         return (target == arr[idx]);
    

//     bool not_take = f(idx-1, target, arr);
//     bool take = false;

//     if(arr[idx] <= target){
//         take = f(idx-1, target - arr[idx], arr);
//     }
    

//     return take || not_take;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     return f(n-1, k, arr);
// }




// /* =========== Memorization ============*/

// bool f(int idx, int target, vector<int> &arr, vector<vector<int>>& dp){
//     if(target == 0) return true;

//     if(target < 0) return false;

//     if(idx == 0) 
//         return (target == arr[idx]);
    
//     if(dp[idx][target] != -1) return dp[idx][target];

//     bool not_take = f(idx-1, target, arr, dp);
//     bool take = false;

//     if(arr[idx] <= target){
//         take = f(idx-1, target - arr[idx], arr, dp);
//     }
    

//     return dp[idx][target] = take || not_take;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n, vector<int> (k+1, -1));
//     return f(n-1, k, arr, dp);
// }


// /* =========== Tabular ============*/

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool> (k+1, false));

//     for(int idx = 0; idx < n; idx++){
//        dp[idx][0] = true;
//     }
//     dp[0][arr[0]] = true;


//     for(int idx = 1; idx < n; idx++){
//          for(int target = 1; target < k+1; target++){
//                 bool not_take = dp[idx-1][target];
//                 bool take = false;

//                 if(arr[idx] <= target){
//                     take = dp[idx-1][target - arr[idx]];
//                 }

//                 dp[idx][target] = take || not_take;
//         }
//     }
//     return dp[n-1][k];
// }


/* =========== Space optimized ============*/

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> pre(k+1, false), curr(k+1, false);
    pre[0] = curr[0] = true;
    pre[arr[0]] = true;

    for(int idx = 1; idx < n; idx++){
         for(int target = 1; target < k+1; target++){
                bool not_take = pre[target];
                bool take = false;

                if(arr[idx] <= target){
                    take = pre[target - arr[idx]];
                }

                curr[target] = take || not_take;
        }
        pre = curr;
    }
    return pre[k];
}