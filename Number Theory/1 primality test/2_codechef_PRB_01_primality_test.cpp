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

bool isPrime(int n){
    if( n == 1) return false;
    for(int i = 2; i * i <= n; i++) if(n%i == 0) return false;

    return true;
}

void solve(){
    int n;
    cin >> n;
     if(isPrime(n)) cout << "yes" << endl;
    else cout << "no" << endl;
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

