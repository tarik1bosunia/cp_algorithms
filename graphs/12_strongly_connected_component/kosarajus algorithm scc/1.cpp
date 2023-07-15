#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

vi ar[1001];
vi tr[1001];
vi order;
vi SCC;
int vis[1001];

void dfs(int src){
    vis[src] = 1;
    for(int child : ar[src]){
        if(vis[child] == 0) dfs(child);
    }
    order.push_back(src);

}
void dfs1(int src){
    vis[src] = 1;
    for(int child : tr[src]){
        if(vis[child] == 0) dfs(child);
    }
    SCC.push_back(src);
}

void solve(){
   int n, m, a, b;
   cin >> n >> m;

   for(int i=1; i <= n; i++) ar[i].clear(), tr[i].clear(),vis[i] = 0;
   order.clear();

   while (m--)
   {
     cin >> a >> b;
     ar[a].push_back(b), tr[b].push_back(a);
   }

   for(int i = 1; i <= n; i++){
    if(vis[i] == 0){
        dfs(i);
    }
   }

   for(int i=1; i <= n; i++) vis[i] = 0;

   for(int i=1; i <= n; i++)
   if(vis[order[n-i]] == 0){
        SCC.clear();
        dfs1(order[n-i]);
        cout << "dfs1 called from " << order[n-1] << "and printing scc" << endl;
        for(int node : SCC) cout << node << " ";
        cout << endl;
   }
   
}
    
int main(){
    freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    return 0;
}

