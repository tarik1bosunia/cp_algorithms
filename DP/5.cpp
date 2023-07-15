// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recurtion 
// int ans(vector<int>& nums, int idx){
//     if(idx < 0) return 0;

//     int pic = nums[idx] + ans(nums, idx-2);
//     int not_pic = ans(nums, idx-1);

//     return max(pic, not_pic);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();

//     return ans(nums, n-1);
// }


// // memorize
// int ans(vector<int>& nums, vector<int>& dp,  int idx){

//     if(idx < 0) return 0;

//     if(dp[idx] != -1) return dp[idx];


//     int pic = nums[idx] + ans(nums, dp, idx-2);
//     int not_pic = ans(nums, dp, idx-1);

//     return dp[idx] = max(pic, not_pic);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n, -1);

//     return ans(nums, dp, n-1);
// }


/* =============== Tabular =========== */

// int ans(vector<int>& nums, vector<int>& dp,  int idx){

//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);

//     for(int i = 2; i <= idx; i++){

//         int not_pic = dp[i-1];
//         int pic = nums[i] + dp[i-2];

//         dp[i] = max(pic, not_pic);
//     }
    
//     return dp[idx];

// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n);

//     return ans(nums, dp, n-1);
// }

// ======== Memory Optimized =============



int maximumNonAdjacentSum(vector<int> &nums){

    int idx = nums.size() -1;
    if(idx = 0) return nums[0];

    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);
    int curr;

    for(int i = 2; i <= idx; i++){

        curr = max(nums[i] + prev2 , prev);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){

    int prev2 = 0;
    int prev = 0;
    int curr;

    for(int num : nums){

        curr = max(num + prev2 , prev);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
