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

using namespace std;

#define N 101
#define m 1000000007
int ar[N][N], I[N][N];

void mul(int A[][N], int B[][N],int dim){
    int res[dim+1][dim+1];
    int val;

    REP(i, dim){
        REP(j , dim){
            val = 0;
            REP(k, dim) val += A[i][k] * B[k][j] % m;
            res[i][j] = val % m;
        }
    }
    REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
}

void power(int A[][N], int dim , int n){
    // initialize identity matrix
    REP(i, dim) REP(j, dim)
    if(i == j) I[i][j] = 1;
    else       I[i][j] = 0;

    // I = I * A;
    // REP(i, n) mul(I, A, dim);

    while (n)
    {
        if(n % 2) mul(I, A, dim), n--;
        else mul(A, A, dim), n /= 2;
    }
    


    REP(i, dim) REP(j, dim) A[i][j] = I[i][j];
}

void printMat(int A[][N], int dim){
    REP(i, dim){
        REP(j, dim) cout << A[i][j] << " ";
        cout << endl;
    }
}

void solve(){
    int dim , n;
    cin >> dim >> n;
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cin >> ar[i][j];
        }
    }
    power(ar, dim, n);
    printMat(ar, dim);
    
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

