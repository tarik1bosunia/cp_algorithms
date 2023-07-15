#include <bits/stdc++.h>

using namespace std;
#define lli long long
#define mod 1000000007

lli getHash(string key)
{
    lli value = 0;
    lli p = 31;
    lli p_power = 1;

    for (char ch : key)
    {
        value = (value + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return value;
}

int main()
{

    bool flag = true;

    while (flag)
    {
        string key;
        cout << "enter key\n";
        cin >> key;

        if (key == ".")
        {
            flag = false;
        }
        else
        {
            cout << "key: " << key << " Hash: " << getHash(key) << endl;
        }
    }

    return 0;
}
