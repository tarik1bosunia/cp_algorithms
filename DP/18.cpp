// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;


// recurtion 
int f(vector<int> &num, int idx, int tar)
{

    if(idx == 0){
        if(tar == 0 && num[0] == 0){
            return 2;
        }
        if(tar == 0 || tar == num[0] ) return 1;

        return 0;
    }

    int not_pick = f(num, idx-1, tar);
    int pick = 0;
    if(num[idx] <= tar)
      pick = f(num, idx-1, tar - num[idx]);

   return pick + not_pick;   
}

int findWays(vector<int> &num, int tar)
{
    return f(num, num.size()-1, tar);
}



// memo..

// int f(vector<int> &num, int idx, int tar, vector<vector<int>>& dp )
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

//    return dp[idx][tar] = pick + not_pick;   
// }

// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp (n, vector<int> (tar+1, -1));

//     return f(num, num.size()-1, tar, dp);
// }


// tabular 
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp (n, vector<int> (tar+1, 0));

    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    if(num[0] <= tar) dp[0][num[0]] = 1;

    for(int idx = 1; idx < n; idx++){
        for(int target = 1; target <= tar; target++){
            int not_pick = dp[idx-1][target];
            int pick = 0;
            if(num[idx] <= target)
                pick = dp[idx-1][target - num[idx]];

            dp[idx][target] = pick + not_pick;  
        }
    }

    return dp[n-1][tar];
}


// memory optimized

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int>pre(tar+1, 0), curr(tar+1, 0);

    pre[0] = curr[0] = 1;

    if(num[0] <= tar) pre[num[0]] = 1;

    for(int idx = 1; idx < n; idx++){
        for(int target = 1; target <= tar; target++){
            int not_pick = pre[target];
            int pick = 0;
            if(num[idx] <= target)
                pick = pre[target - num[idx]];

            curr[target] = pick + not_pick;  
        }
        pre = curr;
    }

    return pre[tar];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
