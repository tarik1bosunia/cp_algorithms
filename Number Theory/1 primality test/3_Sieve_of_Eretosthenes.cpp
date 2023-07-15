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

// ====== using array ================

// int is_prime[1000001];

// void seive1(){
//     int maxN = 1000000;
//     for(int i = 2; i <= maxN; i++) is_prime[i] = 1;
//     is_prime[0] = is_prime[1] = 0;
//     for(int i = 2; i*i <= maxN; i++){
//         if(is_prime[i]){
//             for(int j = i * i; j <= maxN; j+=i){
//                 is_prime[j] = 0;
//             }
//         }
//     }

// }

// =================== using STL ===============



void seive(){
    int maxN = 1000000;
    vector<bool> is_prime(maxN+1 , true);
    is_prime[0] = is_prime[1] =  false;
    
   
    for(int i = 2; i*i <= maxN; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= maxN; j+=i){
                is_prime[j] = false;
            }
        }
    }

}
 
int main(){

    seive();
    // if() cout << "Prime" << endl;
    // else cout << "Not Prime" << endl;
    
    
    return 0;
}

