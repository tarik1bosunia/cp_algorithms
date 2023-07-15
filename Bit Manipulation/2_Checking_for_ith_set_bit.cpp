#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q, i;
    cin >> q;
    
    while (q--)
    {
        cin >> n >> i;

        int s = 1 << i;

        int res = (n & s);

        if(res == 0)
            cout << "false" << endl;
        else
        cout << "true" << endl;    
    }
    
    
    return 0;
}
