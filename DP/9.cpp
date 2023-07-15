// https://www.codingninjas.com/codestudio/problem-details/total-unique-paths_1081470
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

// recursive 
// int ans(int x, int y){
//     if(x < 0 || y < 0) return 0;
    
//     if(x == 0 && y == 0) return 1;
    

    

//     int top =  ans(x, y-1);
//     int left = ans(x-1, y);

//     return top + left;
// }
// int uniquePaths(int m, int n) {
//     return ans(m-1, n-1);
// }



// /* ===================== Memorization ==============*/


// int ans(int x, int y, vector<vector<int>>& dp){
//     if(x < 0 || y < 0) return 0;
    
//     if(x == 0 && y == 0) return 1;
    
//     if(dp[x][y] != -1) return dp[x][y];

//     int top =  ans(x, y-1, dp);
//     int left = ans(x-1, y, dp);

//     return dp[x][y] = top + left;
// }
// int uniquePaths(int m, int n) {
//     vector<vector<int>> dp (m , vector<int> (n, -1));

//     return ans(m-1, n-1, dp);
// }


/* ===================== Tabulation ==============*/

// int uniquePaths(int m, int n) {
//     int dp[m][n];

//     for(int i = 0; i < m; i++){
//         for(int j = 0; j<n; j++){
//             if(i == 0 && j == 0) dp[i][j] = 1;
//             else{
//                 int top = 0;
//                 int left = 0;
//                 if(j > 0)  top = dp[i][j-1];
//                 if(i > 0)  left = dp[i-1][j];
//                 dp[i][j] = top + left;
//             }

            
//         }
//     }

//     return dp[m-1][n-1];
// }



/* ===================== space optimized ==============*/

int uniquePaths(int m, int n) {
    vector<int> prev (n, 0);

    for(int i = 0; i < m; i++){
        vector<int> temp (n, 0);

        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0) temp[j] = 1;
            else{
                int top = 0;
                int left = 0;
                if(j > 0)  top = temp[j-1];
                if(i > 0)  left = prev[j];
                temp[j] = top + left;
            }
            
        }
        prev = temp;
    }

    return prev[n-1];
}

int main(){
    cout <<uniquePaths(2, 2) <<endl;
    
    
    
    return 0;
}
