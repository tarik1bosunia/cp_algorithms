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

void primeFactBueteForce(int n){
    for(int i = 2; i <= n ; i++){
        if(n % i == 0){
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            cout << i << "^" << cnt << endl;
            
        }
    }
}

void primeFactOptimized(int n){
    for(int i = 2; i * i <= n ; i++){
        if(n % i == 0){
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            cout << i << "^" << cnt << endl;
            
        }
    }
    if(n > 1) cout << n << "^" << 1 << endl;
}
void primeFactSieve(int n){
    for(int i = 2; i * i <= n ; i++){
        if(n % i == 0){
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            cout << i << "^" << cnt << endl;
            
        }
    }
    if(n > 1) cout << n << "^" << 1 << endl;
}

void solve(){
    int n;
    cin >> n;
    // primeFactBueteForce(n);
    primeFactOptimized(n);
    
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

