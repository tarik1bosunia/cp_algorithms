// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;


/* ==========recurtion ==========*/

// int ans(vector<vector<int>> &matrix, int idX, int idY)
// {
//     if(idY >= matrix[0].size() || idY < 0) return -1e8;

//     if(idX == 0) return matrix[0][idY];

//     int stand =  ans(matrix, idX - 1, idY);
//     int leftd =  ans(matrix, idX - 1, idY - 1);
//     int rightd =  ans(matrix, idX - 1, idY + 1);


//     return matrix[idX][idY] + max(stand, max(leftd, rightd));
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {

//     int n = matrix.size();
//     int m = matrix[0].size();
//     int maxi = -1e8;

//     for(int j = 0; j < m; j++){
//         maxi =  max(maxi, ans(matrix, n-1 , j));
//     }

//     return maxi;
// }

// /* =========  memorization ================*/

// int ans(vector<vector<int>> & matrix, int idX, int idY, vector<vector<int>>& dp)
// {
//     if(idY >= matrix[0].size() || idY < 0) return -1e9;

//     if(idX == 0) return matrix[0][idY];

//     if(dp[idX][idY] != -1);

//     int stand =  ans(matrix, idX - 1, idY, dp);
//     int leftd =  ans(matrix, idX - 1, idY - 1, dp);
//     int rightd =  ans(matrix, idX - 1, idY + 1, dp);


//     return dp[idX][idY] = matrix[idX][idY] + max(stand, max(leftd, rightd));
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
    
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, 0));
//     int maxi = -1e8;


//     for(int j = 0; j < m; j++){
//         maxi =  max(maxi, ans(matrix, n-1 , j, dp));
//     }

//     return maxi;
// }


/* =========  tabular ================*/

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
    
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, 0));
//     int maxi = -1e8;

//     for(int j = 0; j <m; j++){
//         dp[0][j] = matrix[0][j];
//     }

//     for(int i = 1; i < n; i++){
//         for(int j = 0; j < m; j++){
//             int stand = -1e8, leftd = -1e8, rightd = -1e8;
//             stand =  dp[i-1][j];
//             if(j > 0)
//                 leftd =  dp[i-1][j-1];
//             if(j+1 < m)    
//              rightd = dp[i-1][j+1];

//             dp[i][j] = matrix[i][j] + max(stand, max(leftd, rightd));
//         }
//     }

//     for (int j = 0; j < m; j++) {
//         maxi = max(maxi, dp[n-1][j]);
//     }

//     return maxi;
// }


/*============ space optimized =============*/

int getMaxPathSum(vector<vector<int>> &matrix)
{
    
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> dp(m, 0);
    int maxi = -1e8;

    for(int j = 0; j <m; j++){
        dp[j] = matrix[0][j];
    }

    for(int i = 1; i < n; i++){
        vector<int> curr(m, 0);
        for(int j = 0; j < m; j++){
            int stand = -1e8, leftd = -1e8, rightd = -1e8;
            stand =  dp[j];
            if(j > 0)
                leftd =  dp[j-1];
            if(j+1 < m)    
             rightd = dp[j+1];

            curr[j] = matrix[i][j] + max(stand, max(leftd, rightd));
        }
        dp = curr;
    }

    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[j]);
    }

    return maxi;
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
