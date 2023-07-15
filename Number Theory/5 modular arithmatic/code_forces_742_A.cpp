#include<bits/stdc++.h>

#define lli long long int

using namespace std;



lli power(lli a, lli n, lli p){
    lli res = 1;
    while (n)
    {
        if(n % 2){
            res = (res * a) % p;
            n--;
        }else{
            a = (a * a) % p;
            n /= 2;
        }
    }
    
    return res;

}


    
int main(){


    int n;
    cin >> n;

    cout << power(8, n, 10) << endl;
    
    return 0;
}

