
#include<bits/stdc++.h>
using namespace std;


int frogJumpAns(int n, vector<int> &heights, vector<int>& dp, int k)
{
    // tabulation
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int minSteps = INT_MAX;

        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 0){
                int jumpe = dp[i-j] + abs(heights[i] -heights[i-j]); 
                minSteps = min(minSteps, jumpe); 
            }
        }

        dp[i] = minSteps;
    }

    return dp[n-1];
}

int frogJump(int n, vector<int> &heights)
{
   
    vector<int> dp(n+1, -1);
    int k = 2;

    return frogJumpAns(n-1, heights, dp, k);

}