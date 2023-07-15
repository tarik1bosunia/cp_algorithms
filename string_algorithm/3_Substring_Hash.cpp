#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int

using namespace std;

lli dp[1000001], inv[1000001];

lli power(lli a , lli n){
    lli res = 1;

    while (n)
    {
        if(n & 1) res = (res * a) % mod;
        n >>= 1;
        a = (a * a ) % mod;
    }

    return res;
    
}

void init(string input_string){
    lli p = 31;
    lli p_power = 1;
    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);

    for(int i = 1; i < input_string.size(); i++){
        char ch = input_string[i];
        p_power = (p_power * p) % mod;
        inv[i] = power(p_power, mod-2);
        dp[i] = (dp[i-1] + (ch - 'a' + 1) * p_power) % mod;
    }

}

int substringHash(int l, int r){
    int res  = dp[r];

    if(l > 0) res -= dp[l-1];

    res = (res * inv[l]) %  mod;

    return res;
}

int main(){
    string input_string;
    int tc, L, R;

    cin >> input_string;
    init(input_string);

    cin >> tc;

    while (tc--)
    {
        cin >> L >> R;
        cout << substringHash(L, R) << endl;
    }
    
    
    
    
    return 0;
}
