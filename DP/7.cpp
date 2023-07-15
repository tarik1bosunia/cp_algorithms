// https://www.codingninjas.com/codestudio/problems/loot-valueInHouse_630510
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;


long int ans(vector<int> &valueInHouse, int n)
{
    int prev2 = 0;
    int prev = 0;
    int curr;


    for(int i = 0 ; i < n; i++){
        curr = max(valueInHouse[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    for(int i = 0; i < n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }

    return max(ans(temp1, n-1) , ans(temp2, n-2));
}


