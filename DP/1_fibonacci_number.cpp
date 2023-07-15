#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

int fib_memorization(int n, vector<int>& dp){
    if(n <= 1) return n;

    if(dp[n] != (-1)) return dp[n];

    return  dp[n] = fib_memorization(n-1, dp) + fib_memorization(n-2, dp); 
}

int fib_tabulation(int n, vector<int>& dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fib_tabulation_space_reduced(int n){
    if(n <= 1){
        return n;
    }
    
    int prev2 = 0;
    int prev = 1;
    int curr;

    for(int i = 2; i <= n; i++){
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n;
    cin >> n;

    // int dp[n+1];
    // memset(dp, -1, sizeof dp);
    // cout << "tata";

    // vector<int> dp(n+1, -1);
    // cout << fib_memorization(n, dp) << endl;
    cout << fib_tabulation_space_reduced(n) << endl;
    
    return 0;
}
