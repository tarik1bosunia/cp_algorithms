// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;


// tabulization
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum = 0;
	for(int i = 0; i <n; i++){
        totalSum += arr[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(totalSum+1, false));

    for(int idx = 0; idx < n; idx++){
       dp[idx][0] = true;
    }
    dp[0][arr[0]] = true;


    for(int idx = 1; idx < n; idx++){
         for(int target = 1; target < totalSum+1; target++){
                bool not_take = dp[idx-1][target];
                bool take = false;

                if(arr[idx] <= target){
                    take = dp[idx-1][target - arr[idx]];
                }

                dp[idx][target] = take || not_take;
        }
    }

    int mini = INT_MAX;
    for(int j = 0; j < totalSum +1; j++){

      if(dp[n-1][j] == true){
         int s2 = totalSum - j;
         mini = min(mini, abs(s2 - j));
      }
    }
    return mini;
}

// space optimized

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum = 0;
	for(int i = 0; i <n; i++){
        totalSum += arr[i];
    }

    vector<bool>prev(totalSum+1, false), curr(totalSum+1, false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;


    for(int idx = 1; idx < n; idx++){
         for(int target = 1; target < totalSum+1; target++){
            bool not_take = prev[target];
            bool take = false;

            if(arr[idx] <= target){
                take = prev[target - arr[idx]];
            }

            curr[target] = take || not_take;
        }
        prev = curr;
    }

    int mini = INT_MAX;
    
    for(int j = 0; j < totalSum/2 ; j++){
      if(prev[j] == true){
         int s2 = totalSum - j;
         mini = min(mini, abs(s2 - j));
      }
    }
    return mini;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
