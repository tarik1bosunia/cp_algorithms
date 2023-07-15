#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

long long binpow(long long a, long long b){
   long long res = 1;
   while (b > 0)
   {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
   }
   return res;
}

void solve(){
    
    
}
    
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    return 0;
}

