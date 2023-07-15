#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;
// ========== recurtion ==========
// int f(int day, int last, vector<vector<int>> &points){
//     if(day < 0) return 0;
    
//     int maxi = 0;
//     for(int task =0; task < 3; task++){
//       if (task != last) {
//         maxi = max(maxi, points[day][task] + f(day - 1, task, points));
//       }
//     }

//     return maxi;

// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     return f(n-1, 3, points);
// }



// /*=============== Memorization ==================*/
// int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
//     if(day < 0) return 0;

//     if(dp[day][last] != -1) return dp[day][last];
    
//     int maxi = 0;
//     for(int task =0; task < 3; task++){
//       if (task != last) {
//         maxi = max(maxi, points[day][task] +  f(day - 1, task, points, dp));
//       }
//     }

//     return dp[day][last] = maxi;
// }


// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int> (4, -1));

//     return f(n-1, 3, points, dp);
// }



/* =================== Tabulation ====================*/

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int> (4, 0));

//    prev[0] = max(points[0][1], points[0][2]);
//     prev[1] = max(points[0][0], points[0][2]);
//     prev[2] = max(points[0][0], points[0][1]);
//     prev[3] = max(points[0][0], max(points[0][1], points[0][2]));


//     for(int day = 1; day < n; day++){
//         for(int last =0; last < 4; last++){
//             dp[day][last] = 0;
//             for(int task =0; task < 3; task++){
//                 if (task != last) {
                    
//                     dp[day][last] = max( dp[day][last], points[day][task] + dp[day-1][task]);
//                 }
//             }
//         }
         
//     }

//     return dp[n-1][3];
// }


/* =================== Space Optimized ====================*/



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));


    for(int day = 1; day < n; day++){
        vector<int> temp(4, 0);
        for(int last =0; last < 4; last++){
            temp[last] = 0;

            for(int task =0; task < 3; task++){
                if (task != last) {
                    
                    temp[last] = max( temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}





int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
