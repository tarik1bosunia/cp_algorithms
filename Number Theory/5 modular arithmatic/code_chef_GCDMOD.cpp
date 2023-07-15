#include<bits/stdc++.h>
#define REP(i,n) for(int i = 1; i <= n; i++)
#define mod 1000000007
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

#define m (1e9+7)

using namespace std;

lli power(lli a ,lli n, lli d){
    lli res = 1;

    while (n)
    {
        if(n%2){
            res = ((res%d * a%d) %d);
            n--;
        }else{
            a = (a % d * a % d) %d;
            n /= 2;
        }
    }

    return res;
    
}

lli GCD (lli a, lli b , lli n){
    if( a == b) {
        return (power(a, n, mod) + power(b, n, mod)) % mod;
    }

    lli candidate = 1;
    lli num = a - b;

    for(lli i = 1; i * i <= n; i++ ){
        if(num % i == 0){
            lli tmp = (power(a, n, i) + power(b, n, i))% i;

            if(tmp == 0){
                candidate = max(candidate , i);
            }
            tmp = (power(a, n, num/i) + power(b, n, num/i))% (num/i);
            if(tmp == 0){
                candidate = max(candidate , num / i);
            }
        }
        
    }

    return candidate % mod;
}

void solve(){
    lli a, b, n;
    cin >> a >> b >> n;
    cout << GCD(a , b , n) << endl;
}
    
int main(){
    freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}

