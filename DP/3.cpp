// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// int frogJump(int n, vector<int> &heights)
// {
    // // recursive
    // if(n <= 1) return 0;
    // int left;
    // int right = INT_MAX;

    // left = frogJump(n-1, heights) + abs(heights[n-1] -heights[n-2]); 
    // if(n > 2) 
    //     right = frogJump(n-2, heights) + abs(heights[n-1] -heights[n-3]);

    // return min(left, right);

// }


// int frogJumpAns(int n, vector<int> &heights, vector<int>& dp)
// {
//     // memorization
//     if(n == 0) return 0;

//     if(dp[n] != -1) return dp[n];

//     int right = INT_MAX;
//     int left = frogJumpAns(n-1, heights, dp) + abs(heights[n] -heights[n-1]); 
    
//     if(n > 1) 
//         right = frogJumpAns(n-2, heights, dp) + abs(heights[n] -heights[n-2]);

//     return dp[n] = min(left, right);

// }

// int frogJump(int n, vector<int> &heights)
// {
   
//     vector<int> dp(n+1, -1);

//     return frogJumpAns(n-1, heights, dp);

// }




// int frogJumpAns(int n, vector<int> &heights, vector<int>& dp)
// {
//     // tabulation
//     dp[0] = 0;
//     dp[1] = abs(heights[1] -heights[0]);

//     for(int i = 2; i <= n; i++){

//         int left = dp[i-1] + abs(heights[i] -heights[i-1]); 
//         int right = dp[i-2] + abs(heights[i] - heights[i-2]);
//         dp[i] = min(left, right);
//     }

//     return dp[n];
// }

// int frogJump(int n, vector<int> &heights)
// {
   
//     vector<int> dp(n+1, -1);

//     return frogJumpAns(n-1, heights, dp);

// }


// int frogJump(int n, vector<int> &heights)
// {

   
//   // space optimized

//     if(n == 1) return 0;
//     if(n == 2) return abs(heights[1] -heights[0]);


//     int prev2 = 0;
//     int prev = abs(heights[1] -heights[0]);
//     int curr;


//     for(int i = 2; i < n; i++){

//         int left = prev + abs(heights[i] -heights[i-1]); 
//         int right = prev2 + abs(heights[i] - heights[i-2]);
//         curr = min(left, right);

//         prev2 = prev;
//         prev = curr;
//     }

//     return curr;

// }

int frogJump(int n, vector<int> &heights)
{
  // space + best optimized

    int prev2 = 0;
    int prev = 0;
    int curr;

    for(int i = 1; i < n; i++){

        int fs = prev + abs(heights[i] -heights[i-1]); 
        int ss = INT_MAX;
        if(i > 1)
            ss = prev2 + abs(heights[i] - heights[i-2]);

        curr = min(fs, ss);

        prev2 = prev;
        prev = curr;
    }

    return curr;

}





int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
