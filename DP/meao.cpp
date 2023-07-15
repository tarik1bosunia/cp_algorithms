#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

struct Edge {
    int u, v, w;
};

class Broadcusting {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxV = INT_MIN;
        int minV = INT_MAX;

        for(int num : nums){
            if(num > maxV)  maxV = num;
            if(num < minV) minV = num;
        }
        
        
        for(int num : nums){
            if(num != maxV && num != minV) return num;
        }

        return -1;
    }
};

int main(){

    int n, m, k;
    int a, b, w;

    vector<pair<int, int>> vertices(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vertices[i] = {a, b};
    }

    vector<Edge> edges;

    while (m--)
    {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    vector<pair<int, int>> residents;

    while (k--)
    {
        cin >> a >> b;
        residents.push_back({a, b});
    }
    
    

    


    
    
    return 0;
}