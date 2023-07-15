#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int t;
    cin >> t;
    string s;

    while (t--)
    {
        cin >> s;

        int sum = 0;
        int prev = INT_MIN;

        for(int i = s.size()-1; i >= 0; i--){
            int number = s[i] - 'A' + 1;
            number = pow(10, number);

            if(number > prev) {
                sum += number;
             
            }
            else sum -= number; 

            prev = number;
            
        }

        cout << sum << endl;
    }
    
    
    
    return 0;
}
