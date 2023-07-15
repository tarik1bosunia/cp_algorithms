// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recurtuion

// int f(vector<int>& num,int idx, int x){
//     if(idx == 0){
//         if(x % num[0] == 0) return (x / num[0]);
//         else return 1e8;
//     }

//     int not_take = f(num, idx-1, x);
//     int take = INT_MAX;
//     if(num[idx] <= x)
//         take = 1 + f(num, idx, x - num[idx]);

//     return min(take, not_take);
// }   

// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();

//     int result = f(num , n-1, x);
//     if (result >= 1e8){
//         return -1;
//     }
    
//     return result;
// }


// // memoriztion

// int f(vector<int>& num,int idx, int x, vector<vector<int>> &dp){
//     if(idx == 0){
//         if(x % num[0] == 0) return (x / num[0]);
//         else return 1e8;
//     }
//     if(dp[idx][x] != -1) return dp[idx][x];

//     int not_take = f(num, idx-1, x, dp);
//     int take = INT_MAX;
//     if(num[idx] <= x)
//         take = 1 + f(num, idx, x - num[idx], dp);

//     return dp[idx][x]  = min(take, not_take);
// }   

// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();

//     vector<vector<int>> dp(n, vector<int>(x+1, -1));

//     int result = f(num , n-1, x, dp);
//     if (result >= 1e8){
//         return -1;
//     }
    
//     return result;
// }



// tabulation
// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();

//     vector<vector<int>> dp(n, vector<int>(x+1, 0));

//     for(int t = 0; t <= x; t++){
//         if(t % num[0] == 0) dp[0][t] = t / num[0];
//         else dp[0][t] = 1e8;
//     }

//     for(int idx = 1; idx < n; idx++){
//         for(int t = 0; t <= x; t++){
            
//             int not_take =  dp[idx-1][t];
//             int take = INT_MAX;
//             if(num[idx] <= t)
//                 take = 1 + dp[idx][t-num[idx]];

//             dp[idx][t]  = min(take, not_take);
//         }
//     }

//     int result = dp[n-1][x];
    
//     if (result >= 1e8){
//         return -1;
//     }
    
//     return result;
// }


// memory optimized
// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();

//     vector<int> pre(x+1, 0), curr(x+1, 0);

//     for(int t = 0; t <= x; t++){
//         if(t % num[0] == 0) pre[t] = t / num[0];
//         else pre[t] = 1e8;
//     }

//     for(int idx = 1; idx < n; idx++){
//         for(int t = 0; t <= x; t++){
            
//             int not_take =  pre[t];
//             int take = INT_MAX;
//             if(num[idx] <= t)
//                 take = 1 + curr[t-num[idx]];

//             curr[t]  = min(take, not_take);
//         }
//         pre = curr;
//     }

//     int result = pre[x];
    
//     if (result >= 1e8){
//         return -1;
//     }
    
//     return result;
// }

// more optimize

int minimumElements(vector<int>& num, int x) {
    int n = num.size();
    const int INF = 1e8;

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (num[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    int result = dp[x];
    if (result >= INF) {
        return -1;
    }

    return result;
}
