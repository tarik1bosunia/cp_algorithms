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

vector<int> ar[10001];
int vis[10001], dist[10001];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int child : ar[curr]){
            if(vis[child] == 0){
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }

        }
 
    }
    
}

void solve(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i =1; i <= n; i++) ar[i].clear(), vis[i] = 0;

    while (m--) cin >> a >> b, ar[a].pb(b), ar[b].pb(a);

    bfs(1);
    
    cout << dist[n] << endl;
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







