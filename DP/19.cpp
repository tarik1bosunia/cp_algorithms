// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// int f(vector<int> &num, int idx, int tar)
// {

//     if(idx == 0){
//         if(tar == 0 && num[0] == 0){
//             return 2;
//         }
//         if(tar == 0 || tar == num[0] ) return 1;

//         return 0;
//     }

//     int not_pick = f(num, idx-1, tar);
//     int pick = 0;
//     if(num[idx] <= tar)
//       pick = f(num, idx-1, tar - num[idx]);

//     return pick + not_pick;   
// }

// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n;i++ ){
//         totalSum += arr[i];
//     }
//     int target = (totalSum - d);

//     if(target & 1) return 0;

//     return f(arr, n-1, target/2);
// }


// // memorization

// int f(vector<int> &num, int idx, int tar, vector<vector<int>>& dp)
// {

//     if(idx == 0){
//         if(tar == 0 && num[0] == 0){
//             return 2;
//         }
//         if(tar == 0 || tar == num[0] ) return 1;

//         return 0;
//     }

//     if(dp[idx][tar] != -1) return dp[idx][tar];

//     int not_pick = f(num, idx-1, tar, dp);
//     int pick = 0;
//     if(num[idx] <= tar)
//       pick = f(num, idx-1, tar - num[idx], dp);

//    return dp[idx][tar] =  (pick + not_pick) % mod;   
// }

// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n;i++ ){
//         totalSum += arr[i];
//     }
//     int target = (totalSum - d);

//     if(target < 0 || target & 1 ) return 0;

//     target = target / 2;

//     vector<vector<int>> dp(n, vector<int> (target+1, -1));

//     return f(arr, n-1, target, dp);
// }



// tabulation

// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n;i++ ){
//         totalSum += arr[i];
//     }
//     int target = (totalSum - d);

//     if(target < 0 || target & 1 ) return 0;

//     target = target / 2;

//     vector<vector<int>> dp(n, vector<int> (target+1, 0));

//     if(arr[0] == 0) dp[0][0] = 2;
//     else dp[0][0] = 1;
//     if(arr[0] != 0 && arr[0] <= target)  dp[0][arr[0]] = 1;

//     for(int idx = 1; idx < n; idx++){
//         for(int tar = 0; tar <= target; tar++){

//             int not_pick = dp[idx-1][tar];
//             int pick = 0;
//             if(arr[idx] <= tar)
//                 pick = dp[idx-1][tar - arr[idx]];

//             dp[idx][tar] =  (pick + not_pick) % mod;
//         }
//     }

//     return dp[n-1][target];
// }


// memory optimized

int countPartitions(int n, int d, vector<int> &arr) {

    int totalSum = 0;
    for(int i = 0; i < n;i++ ){
        totalSum += arr[i];
    }
    int target = (totalSum - d);

    if(target < 0 || target & 1 ) return 0;

    target = target / 2;

    vector<int> pre(target+1, 0), curr(target+1, 0);

    if(arr[0] == 0) pre[0] = curr[0] = 2;
    else pre[0] = curr[0] = 1;
    if(arr[0] != 0 && arr[0] <= target)  pre[arr[0]] = 1;

    for(int idx = 1; idx < n; idx++){
        for(int tar = 0; tar <= target; tar++){

            int not_pick = pre[tar];
            int pick = 0;
            if(arr[idx] <= tar)
                pick = pre[tar - arr[idx]];

            curr[tar] =  (pick + not_pick) % mod;
        }
        pre = curr;
    }

    return pre[target];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
