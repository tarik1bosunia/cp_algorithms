#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

int main(){

    int t, n;
    cin >> t ;

    while (t--)
    {
        cin >> n;

        if(n >= 2 && n <= 4) 
         cout << "Bob" << endl;
        else 
           cout << "Alice" << endl;
    }
    
    
    return 0;
}
