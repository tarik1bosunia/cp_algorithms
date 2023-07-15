/*https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?*/
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;
// recursive
// bool f(vector<int> &arr, int idx, int target){
//     if(target == 0) return true;
//     if(idx == 0) return arr[idx] == target;

//     bool not_take = f(arr, idx-1, target); 
//     bool take = false;

//     if(arr[idx] <= target)
//         take = f(arr, idx-1, target - arr[idx]); 

//     return take || not_take;     
// }

// bool canPartition(vector<int> &arr, int n)
// {
//     int sum = 0;

// 	for(int i = 0; i < n; i++){
//         sum += arr[i];
//     }

//     if(sum & 1) return false;

//     return f(arr, n-1, sum / 2);
// }



// memorization
// bool f(vector<int> &arr, int idx, int target, vector<vector<bool>>& dp){
//     if(target == 0) return true;
//     if(idx == 0) return arr[idx] == target;

//     if(dp[idx][target]) return dp[idx][target];

//     bool not_take = f(arr, idx-1, target, dp); 
//     bool take = false;

//     if(arr[idx] <= target)
//         take = f(arr, idx-1, target - arr[idx], dp); 

//     return dp[idx][target] = take || not_take;     
// }

// bool canPartition(vector<int> &arr, int n)
// {
//     int sum = 0;

// 	for(int i = 0; i < n; i++){
//         sum += arr[i];
//     }

//     if(sum & 1) return false;

//     vector<vector<bool>> dp(n, vector<bool>(sum/2+1, false));

//     return f(arr, n-1, sum / 2, dp);
// }


// // tabulation

// bool canPartition(vector<int> &arr, int n)
// {
//     int sum = 0;

// 	for(int i = 0; i < n; i++){
//         sum += arr[i];
//     }

//     if(sum & 1) return false;

//     vector<vector<bool>> dp(n, vector<bool>(sum/2+1, false));
    
//     for(int idx = 0; idx < n; idx++){
//         dp[idx][0] = true;
//     }
//     dp[0][arr[0]] = true;

//     for(int idx = 1; idx < n; idx++){
//         for(int target = 1; target < sum/2+1; target++){
//             bool not_take = dp[idx-1][target]; 
//             bool take = false;

//             if(arr[idx] <= target)
//                 take = dp[ idx-1][target - arr[idx]];

//             dp[idx][target] = take || not_take; 
//         }
//     }

//     return dp[n-1][sum/2];
// }



// memory optimized

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;

	for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    if(sum & 1) return false;

    vector<bool> pre(sum/2+1, false), curr(sum/2+1, false);
    
    pre[0] = curr[0] = true;
    pre[arr[0]] = true;

    for(int idx = 1; idx < n; idx++){
        for(int target = 1; target < sum/2+1; target++){
            bool not_take = pre[target]; 
            bool take = false;

            if(arr[idx] <= target)
                take = pre[target - arr[idx]];

            curr[target] = take || not_take; 
        }
        pre = curr;
    }

    return pre[sum/2];
}
