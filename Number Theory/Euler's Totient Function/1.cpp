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

using namespace std;

int phi(int n){
    int res = n;

    for(int i =2; i * i <= n ; i++){
        if(n % i == 0){
            res /= i;
            res *= (i-1);

            while (n % i == 0)
            {
                n /= i;
            }
            
        }
    }

    if(n > 1){
        res /= n;
        res *= (n-1);
    }

    return res;

}

void solve(){
    int n;
    cin >> n;
    cout << "ETF( " << n << ") : " << phi(n) << endl;
    
}
    
int main(){


    
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    return 0;
}

