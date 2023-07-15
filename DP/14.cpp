// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;
// /* ============== Recurtion ============*/
// int f(int i, int j1, int j2, vector<vector<int>> &grid){
    
//     if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
//       return 0;
  
    
//     if(i == grid.size()-1){
//         if(j1 == j2) 
//             return grid[i][j1];
//         else 
//             return grid[i][j1] + grid[i][j2];
//     }

//     int maxy = 0;
//     for(int x = -1; x <= 1 ; x++){
//          for(int y = -1; y <= 1 ; y++){
//             maxy = max(maxy, f(i + 1, j1 + x , j2 + y, grid));
//         }
//     }

//     if(j1 == j2)
//         return maxy + grid[i][j1];
    
//     return maxy + grid[i][j1] + grid[i][j2];
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

//     return f(0, 0, c-1, grid);
// }


// /* ============== Memorization ============*/

// int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> dp){
    
//     if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
//       return 0;
  
    
//     if(i == grid.size()-1){
//         if(j1 == j2) 
//             return grid[i][j1];
//         else 
//             return grid[i][j1] + grid[i][j2];
//     }

//     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

//     int maxy = 0;
//     for(int x = -1; x <= 1 ; x++){
//          for(int y = -1; y <= 1 ; y++){
//             maxy = max(maxy, f(i + 1, j1 + x , j2 + y, grid, dp));
//         }
//     }

//     if(j1 == j2)
//         return dp[i][j1][j2] = maxy + grid[i][j1];
    
//     return dp[i][j1][j2] = maxy + grid[i][j1] + grid[i][j2];
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int> (c, -1)));

//     return f(0, 0, c-1, grid, dp);
// }


// /* ============== Tabulation ============*/
// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int> (c, 0)));


//     // initialization 
//     for(int j = 0; j < c; j++){
//         for(int k =0; k < c; k++){
//             if(j == k) dp[r-1][j][k] =  grid[r-1][j];
//             else dp[r-1][j][k] = grid[r-1][j] + grid[r-1][k];
//         }
//     }

//     for(int i = r-2; i >= 0; i--){
//         for(int j1 = 0; j1 < c; j1++){
//             for(int j2 = 0; j2 < c; j2++){
//                 int maxy = 0;
//                 for(int x = -1; x <= 1 ; x++){
//                     for(int y = -1; y <= 1 ; y++){
//                         if(j1+x >= 0 && j1+x < c && j2+y >= 0 && j2+y < c )
//                         maxy = max(maxy, dp[i+1][j1+x][j2+y]);
//                     }
//                 }

//                 if(j1 == j2)
//                     dp[i][j1][j2] = maxy + grid[i][j1];
//                 else    
//                     dp[i][j1][j2] = maxy + grid[i][j1] + grid[i][j2];
//             }
//         }

//     }

//     return dp[0][0][c-1];
// }


/* ============== Memory optimized ============*/
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> pre(c, vector<int> (c, 0));

    // initialization 
    for(int j = 0; j < c; j++){
        for(int k =0; k < c; k++){
            if(j == k) pre[j][k] =  grid[r-1][j];
            else pre[j][k] = grid[r-1][j] + grid[r-1][k];
        }
    }

    for(int i = r-2; i >= 0; i--){
        vector<vector<int>> curr(c, vector<int> (c, 0));
        for(int j1 = 0; j1 < c; j1++){
            for(int j2 = 0; j2 < c; j2++){
                int maxy = 0;
                for(int x = -1; x <= 1 ; x++){
                    for(int y = -1; y <= 1 ; y++){
                        if(j1+x >= 0 && j1+x < c && j2+y >= 0 && j2+y < c )
                        maxy = max(maxy, pre[j1+x][j2+y]);
                    }
                }

                if(j1 == j2)
                    curr[j1][j2] = maxy + grid[i][j1];
                else    
                    curr[j1][j2] = maxy + grid[i][j1] + grid[i][j2];
            }
        }
        pre = curr;

    }

    return pre[0][c-1];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
