#include<bits/stdc++.h>

using namespace std;



int main(){
    
    
    int n, a, l, r, q;
    cin >> n >> q;
    vector<int> ar;

    int pre_xor = 0;

    while (n--)
    {
        cin >> a;
        pre_xor = a ^ pre_xor;
        ar.push_back(pre_xor);
    }
    while (q--)
    {
        cin >> l >> r;
        if(l = 0) {
            cout << ar[r] << endl;
        }else{
            cout << (ar[r] ^ ar[l-1]);
        }
    }
    


    
    
    
    return 0;
}
