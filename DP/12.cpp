// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;
/* =============== Recurtion ============*/
int ans(vector<vector<int>>& triangle, int n, int idx, int idy){

    if(idx > n) return 0;

    int step1 = ans(triangle, n, idx + 1, idy);
    int step2 = ans(triangle, n, idx + 1, idy + 1);

    return triangle[idx][idy] +  min(step1, step2);

}

int minimumPathSum(vector<vector<int>>& triangle, int n){

	return ans(triangle, n-1, 0, 0);
}



/* ================= memorization ==============*/
int ans(vector<vector<int>>& triangle, int n, int idx, int idy,vector<vector<int>>& dp){
    
    if(idx > n) return 0;

    if(dp[idx][idy] != -1) return dp[idx][idy];

    int step1 = ans(triangle, n, idx + 1, idy, dp);
    int step2 = ans(triangle, n, idx + 1, idy + 1, dp);

    return dp[idx][idy] = triangle[idx][idy] +  min(step1, step2);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp (n, vector<int> (n, -1));

	return ans(triangle, n-1, 0, 0, dp);
}




/* ================= tabular ==============*/

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp (n, vector<int> (n, 0));

    // base case
    for(int j = 0; j < n ; j++){
        dp[n-1][j]  = triangle[n-1][j];
    }
    

    for(int i = n-2 ; i >= 0; i--){
        for(int j = i; j >= 0 ; j--){

            dp[i][j] = triangle[i][j] +  min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

	return dp[0][0];
}

/* ================= space optimized ==============*/

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int> prev (n, 0), curr (n, 0);

    // base case
    for(int j = 0; j < n ; j++){
        prev[j]  = triangle[n-1][j];
    }
    
    for(int i = n-2 ; i >= 0; i--){
        
        for(int j = i; j >= 0 ; j--){
            curr[j] = triangle[i][j] +  min(prev[j], prev[j+1]);
        }
        prev = curr;
    }

	return prev[0];
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
