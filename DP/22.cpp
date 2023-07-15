#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recursive
// int f(int idx, int target, vector<int> & arr){


//     if(idx == 0){
//         int count = 0;
//         if(target == arr[0]) count++;
//         if(target == -arr[0]) count++;
//         return count;
//     }

//     int plus = f(idx -1, target - arr[idx], arr);

//     int minus = f(idx -1, target + arr[idx], arr);

//     return plus + minus;
// }

// int targetSum(int n, int target, vector<int>& arr) {
//     return f(n-1, target, arr);
// }

int f(vector<int> &num, int idx, int tar, vector<vector<int>>& dp )
{
    if(idx == 0){
        if(tar == 0 && num[0] == 0){
            return 2;
        }
        if(tar == 0 || tar == num[0] ) return 1;

        return 0;
    }

    if(dp[idx][tar] != -1) return dp[idx][tar];

    int not_pick = f(num, idx-1, tar, dp);
    int pick = 0;
    if(num[idx] <= tar)
      pick = f(num, idx-1, tar - num[idx], dp);

   return dp[idx][tar] = pick + not_pick;   
}


int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int i = 0; i < n;i++ ){
        totalSum += arr[i];
    }
    int target = (totalSum - d);

    if(target < 0 || target & 1 ) return 0;

    target = target / 2;

    vector<vector<int>> dp(n, vector<int> (target+1, -1));

    return f(arr, n-1, target, dp);
}



int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}



