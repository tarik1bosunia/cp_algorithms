#include<bits/stdc++.h>

using namespace std;

int LCA(int a, int b){
    if(level[b] < level[a]) swap(a, b);

    int d = level[b] - level[a];

    while (d > 0)
    {
        b = par[b];
        d--;
    }
    while (a != b)
    {
        a = par[a];
        b = par[b];
    }
    return par[a];
    
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
