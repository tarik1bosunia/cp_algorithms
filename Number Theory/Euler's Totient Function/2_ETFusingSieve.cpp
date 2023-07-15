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

int phi[1000000];

void init(int maxN){
    for(int i = 1; i <= maxN; i++){
        phi[i] = i;
    }
    for(int i = 2; i <= maxN; i++){
        if(phi[i] == i){
            for(int j = i; j <= maxN; j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}


    
int main(){

    int t, n;
    cin >> t;

    init(1000000);
    
    while (t--)
    {
       cin >> n;
       cout << phi[n] << endl; 
    }
    
    return 0;
}

