#include<bits/stdc++.h>
#define REP(i,n) for(int i = 1; i <= n; i++)
#define P 1000000007
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

int F[1000001];

int power(int a, int n){
    int res = 1;
    while (n)
    {
        if(n % 2){
            res = (res * 1LL * a) % P;
        }
        n = n / 2;
        a = (a * 1LL * a) % P;
    }

    return res;
    
}

int C(int n, int k){
    if(k > n) return 0;

    int res = F[n];
    res = (res * 1LL * power(F[k], P-2)) % P;
    res = (res * 1LL * power(F[n-k], P-2)) % P;

    return res;
}

 
int main(){
    F[0] = F[1] = 1;

    for(int i = 2 ; i < 1000000;i++){
        F[i] = (F[i-1] * 1LL * i) % P;
    }

    int q, n, k;

    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        cout << C(n, k) << endl; 
    }
    
    return 0;
}

