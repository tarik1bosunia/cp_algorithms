#include<bits/stdc++.h>

using namespace std;

struct edge{
    int a, b, w;
};
edge ar[1000000];
int par[10001];

bool comp(edge &x, edge &y){
  return x.w < y.w;
}

int find(int a){
    if (par[a] == -1) return a;
    
    return par[a] = find(par[a]);
}

void merge(int a , int b){
    par[a] = b;
}



int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    
    int n, m, a, b, w;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) par[i] = -1;

    for(int i = 0; i <m; i++)
    {
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
        
    }

    sort(ar, ar+m, comp);


    int sum = 0;

    for(int i = 0; i < m; i++){
        a = find(ar[i].a);
        b = find(ar[i].b);

        if(a != b){
            sum += ar[i].w;
            merge(a, b);
        }
    }
    cout << sum << endl;
    
    
    return 0;
}
