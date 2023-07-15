// https://www.spoj.com/problems/TDKPRIME/

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


const int maxN = 90000000;
vector<int> primes;
vector<bool> is_prime;//this is not prime


void seive(){
    int n = maxN;
    is_prime.resize(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n ; i++){
        
        if(is_prime[i]){
            primes.push_back(i);

        }
    }

}

    
int main(){
    // freopen("input.txt", "r", stdin);
    
    int q, n;
    cin >> q;
    seive();
    while (q--)
    {
        cin >> n;
        cout << primes[n-1] << endl;
        
    }

    return 0;
}

