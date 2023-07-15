#include<bits/stdc++.h>
#define REP(i,n) for(int i = 1; i <= n; i++)
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

int ar[100005], pre[100005],suff[100005];

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int q, n, l, r;
    cin >> n >> q;

    REP(i, n){
        cin >> ar[i];
    }
    pre[0] = suff[n+1] = 0;

    REP(i,n) {
        pre[i] = gcd(pre[i-1], ar[i]);
    }
    for(int i = n; i >= 1; i--){
        suff[i] = gcd(suff[i+1], ar[i]);
    }
    
    while (q--)
    {
        cin >> l >> r;
        cout << (gcd(pre[l-1], suff[r+1])) << endl; 
    }
    
}
    
int main(){
    // freopen("input.txt", "r", stdin);
    
    
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    return 0;
}

