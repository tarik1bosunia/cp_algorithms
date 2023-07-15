// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long

using namespace std;

lli fib(int n){
     if(n == 0) return 0;
     if(n == 1) return 1;
    
    int prev = 1;
    int prev2 = 1;
    int curr = 0;

    for(int i = 2; i <= n; i++){
        curr = (prev +  prev2) % mod;
        prev2 = prev;
        prev = curr;
    }

    
    return curr;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}