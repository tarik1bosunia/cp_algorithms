#include <bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, q, a;
    string result;
    vector<int> v;
    cin >> t;

    while (t--)
    {
        cin >> q;
        result = "";
        v.clear(); // Clear the vector for each test case

        while (q--)
        {
            cin >> a;
            v.push_back(a);
        }

        int last_max = v[0];
        int first_min= v[0];

        int maxi = v[0];
        int i = 0;
        for (; i < v.size(); i++)
        {
            if (v[i] >= maxi)
                result += "1";
            else{
                result += "1";
                first_min = v[i];
                i++;
                break;
            }

        }


        for (; i < v.size(); i++)
        {
            if (v[i] >= first_min && v[i] <= last_max)
                result += "1";
            else
                result += "0";
        }

        cout << result << endl;
    }
    
    return 0;
}
