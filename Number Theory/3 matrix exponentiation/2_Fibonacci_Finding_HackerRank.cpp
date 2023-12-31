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

lli ar[3];
lli I[3][3] , T[3][3];

void mul(lli A[3][3], lli B[3][3], int dim){
    lli res[dim+1][dim+1];

    REP(i, dim){
        REP(j, dim){
            res[i][j] = 0;
            lli val;
            REP(k, dim){
                val = (A[i][k] * B[k][j]) % mod;
                res[i][j] = (res[i][j] + val) % mod;
            }
            
        }
    }

    REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
}

lli getFib(int n){
    if(n <= 2) return ar[n];

    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;

    n = n -1;

    while (n)
    {
        if(n%2){
            mul(I, T, 2);
            n--;
        }else{
            mul(T, T, 2);
            n /= 2;
        }
    }
    lli Fn = (ar[1] * I[1][1] + ar[2] * I[2][1] ) % mod;

    return Fn;
    
}
    
int main(){
    freopen("input.txt", "r", stdin);

    
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> ar[1] >> ar[2] >> n;
        cout << getFib(n) << endl;
    }
    
    return 0;
}

