#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

/* =========== Recurtion =============*/

// int f(int idx, int idy, string s1, string s2){
//     if(idx < 0 || idy < 0) return 0;

//     if(s1[idx] == s2[idy]){
//         return 1 + f(idx-1, idy-1, s1, s2);
//     }

//     return max(f(idx-1, idy, s1, s2), f(idx, idy-1, s1, s2));
// }

// int longestCommonSubsequence(string  s1, string s2){
//     int idx = s1.size() - 1;
//     int idy = s2.size() - 1;

//     return f(idx, idy, s1, s2);
// }

/* =========== Memorization =============*/

// int f(int idx, int idy, string s1, string s2, vector<vector<int>> & dp){
//     if(idx < 0 || idy < 0) return 0;

//     if(dp[idx][idy] != -1) return dp[idx][idy];

//     if(s1[idx] == s2[idy]){
//         return dp[idx][idy] = 1 + f(idx-1, idy-1, s1, s2, dp);
//     }

//     return dp[idx][idy] = max(f(idx-1, idy, s1, s2, dp), f(idx, idy-1, s1, s2, dp));
// }

// int longestCommonSubsequence(string  s1, string s2){
//     int idx = s1.size();
//     int idy = s2.size();

//     vector<vector<int> > dp(idx, vector<int>(idy, -1));

//     return f(idx-1, idy-1, s1, s2, dp);
// }
 /* =========== Index Shifting =============*/

// int f(int idx, int idy, string s1, string s2, vector<vector<int>> & dp){
//     if(idx == 0 || idy == 0) return 0;

//     if(dp[idx][idy] != -1) return dp[idx][idy];

//     if(s1[idx -1] == s2[idy -1]){
//         return dp[idx][idy] = 1 + f(idx-1, idy-1, s1, s2, dp);
//     }

//     return dp[idx][idy] = max(f(idx-1, idy, s1, s2, dp), f(idx, idy-1, s1, s2, dp));
// }

// int longestCommonSubsequence(string  s1, string s2){
//     int idx = s1.size();
//     int idy = s2.size();

//     vector<vector<int> > dp(idx + 1, vector<int>(idy + 1, -1));

//     return f(idx, idy, s1, s2, dp);
// }


// /* =========== Tabulation =============*/
// int longestCommonSubsequence(string  s1, string s2){
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

//     for(int i = 0; i <= m; i++) dp[0][i] = 0;
//     for(int i = 0; i <= n; i++) dp[i][0] = 0;

//     for(int idx = 1; idx <= n; idx++){
//           for(int idy = 1; idy <= m; idy++){
//             if(s1[idx -1] == s2[idy -1]){
//                 dp[idx][idy] = 1 +  dp[idx-1][idy-1];
//             }else{
//                 dp[idx][idy] = max(dp[idx-1][idy], dp[idx][idy-1]);
//             }  
//         }
//     }

//     return dp[n][m];
// }


/* =========== Memory Optimized =============*/
int longestCommonSubsequence(string  s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0), curr(m+1, 0);

    for(int i = 0; i <= m; i++) prev[i] = 0;

    for(int idx = 1; idx <= n; idx++){
          for(int idy = 1; idy <= m; idy++){
            if(s1[idx -1] == s2[idy -1]){
                curr[idy] = 1 +  prev[idy-1];
            }else{
                curr[idy] = max(prev[idy], curr[idy-1]);
            }  
        }
        prev = curr;
    }

    return prev[m];
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    cout << longestCommonSubsequence("ab", "ab") << endl;
    
    return 0;
}
