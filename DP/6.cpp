// https://www.codingninjas.com/codestudio/problems/loot-houses_630510
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recurtion
// int ans(vector<int> &houses, int idx){
//     if(idx < 0 ) return 0;

//     int take = houses[idx] + ans(houses, idx-2);
//     int notTake =  ans(houses, idx-1);

//     return max(take, notTake);
// }
// int maxMoneyLooted(vector<int> &houses, int n)
// {
//     return ans(houses, n-1);
// }

// // ========= memorization =========

// int ans(vector<int> &houses, vector<int>& dp, int idx){

//     if(idx < 0 ) return 0;

//     if(dp[idx] != -1) return dp[idx];

//     int take = houses[idx] + ans(houses,dp, idx-2);
//     int notTake =  ans(houses, dp, idx-1);

//     return dp[idx] = max(take, notTake);
// }

// int maxMoneyLooted(vector<int> &houses, int n)
// {
//     vector<int> dp(n, -1);
//     return ans(houses, dp, n-1);
// }

// ========= tabular =========



int maxMoneyLooted(vector<int> &houses, int n)
{
    int prev2 = 0;
    int prev = 0;
    int curr;


    for(int i = 0 ; i < n; i++){
        curr = max(houses[i] + prev2, prev);
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
