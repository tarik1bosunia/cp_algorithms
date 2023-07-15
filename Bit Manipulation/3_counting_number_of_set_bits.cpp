#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> q;
    while (q--)
    {
        cin >> n;

        int cnt = 0;
        // 1st apporoch
        // while (n > 0)
        // {
        //     if(n & 1 > 0){
        //         cnt++;
        //     }
        //     n = n >> 1; 
        // }
        // cout << cnt << endl;

        // 2nd apporoch
        while (n > 0)
        {
            cnt++;
            n = n &  n-1; 
        }
        cout << cnt << endl;
        
    }
    
    
    
    
    return 0;
}
