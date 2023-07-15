// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recursive 
int ans(int i, int j, vector<vector<int>> &grid){
    if(i < 0 || j < 0) return INT_MAX;
    
    if(i == 0 && j == 0) return grid[0][0];

    int top = ans(i, j-1, grid);
    int left = ans(i-1, j, grid);

    return grid[i][j] + min(top, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    ans(n-1, m-1, grid);
}




// /* ===================== Memorization ==============*/


int ans(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    
    if(i < 0 || j < 0) return INT_MAX;
    if(i == 0 && j == 0) return grid[0][0];

    if(dp[i][j] != -1) return dp[i][j];

    int top = ans(i, j-1, grid, dp);
    int left = ans(i-1, j, grid, dp);

    return dp[i][j] = grid[i][j] + min(top, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return ans(n-1, m-1, grid, dp);
}


/* ===================== Tabulation ==============*/

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for(int i = 0; i <n; i++){
        for(int j =0; j < m; j++){
            if(i == 0 && j == 0) dp[0][0] = grid[0][0];
            else{
                int top = INT_MAX;
                int left = INT_MAX;

                if(i > 0)  left = dp[i-1][j];
                if(j > 0)  top = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(top, left);
            }
        }
    }

    return dp[n-1][m-1];
}



/* ===================== space optimized ==============*/
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> pre(m, 0);

    for(int i = 0; i <n; i++){
        vector<int> curr(m, 0);
        for(int j = 0; j < m; j++){

            if(i == 0 && j == 0) curr[0] = grid[0][0];
            else{
                int top = INT_MAX;
                int left = INT_MAX;

                if(i > 0)  left = pre[j];
                if(j > 0)  top = curr[j-1];
                curr[j] = grid[i][j] + min(top, left);
            }
        }
        pre = curr;
    }

    return pre[m-1];
}

// int main(){
//     cout <<uniquePaths(2, 2) <<endl;
    
    
    
//     return 0;
// }
