// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recursive 
// int ans(int i, int j, vector<vector<int>> &mat){
//     if(mat[i][j] == -1) return 0;
//     if(i < 0 || j < 0) return 0;
    
//     if(i == 0 && j == 0) return 1;

//     int top =  ans(i, j-1, mat);
//     int left = ans(i-1, j, mat);

//     return top + left;
// }

// int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
//     return ans(m-1, n-1, mat);
// }




// /* ===================== Memorization ==============*/


// int ans(int i, int j, vector<vector<int>> &mat, vector<vector<int>> dp){
//     if(mat[i][j] == -1) return 0;
//     if(i < 0 || j < 0) return 0;
    
//     if(i == 0 && j == 0) return 1;

//     if(dp[i][j] != -1) return dp[i][j];

//     int top =  ans(i, j-1, mat, dp);
//     int left = ans(i-1, j, mat, dp);

//     return dp[i][j] = (top + left) % mod;
// }

// int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return ans(m-1, n-1, mat, dp);
// }


/* ===================== Tabulation ==============*/

// int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
//     vector<vector<int>> dp(n, vector<int> (m, -1));

//     for(int i = 0; i <n; i++){
//         for(int j = 0; j <m; j++){
            
//             if(mat[i][j] == (-1)) dp[i][j] = 0;
//             else if(i == 0 && j == 0) dp[i][j] = 1;
//             else{
//                 int top = 0;
//                 int left = 0;
//                 if(i > 0 ) top =  dp[i-1][j];
//                 if(j > 0 ) left =  dp[i][j-1];
//                 dp[i][j] = (top + left) % mod;
//             }
            
//         }
//     }
//     return dp[n-1][m-1];
// }



/* ===================== space optimized ==============*/

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<int> pre(m, 0);

    for(int i = 0; i <n; i++){
        vector<int> curr(m, 0);
        for(int j = 0; j <m; j++){
            
            if(mat[i][j] == (-1)) curr[j] = 0;
            else if(i == 0 && j == 0) curr[j] = 1;
            else{
                int top = 0;
                int left = 0;
                if(i > 0 ) top =  pre[j];
                if(j > 0 ) left =  curr[j-1];
                curr[j] = (top + left) % mod;
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
