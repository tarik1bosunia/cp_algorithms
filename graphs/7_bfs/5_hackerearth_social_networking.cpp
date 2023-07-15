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

vector<int> ar[1000001];
int level[1000001], vis[1000001];
int dist[1000001];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 0;
    dist[src] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child : ar[curr]){
            if(vis[child] == 0){
                vis[child] = 1;
                q.push(child);
                dist[child]  = dist[curr] + 1;
                vis[child] = 1; 
                level[dist[child]] ++;
            }
        }
    }
}


void solve(){
    int n, m, a, b, src, d , q;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    cin >> q;
    while (q--)
    {
        cin >> src >> d;
        for(int i=0; i< n; i++){
            level[i] = 0; vis[i] = 0;
        }
        bfs(src);
        cout << level[d] << endl;
    }
    
}
    
int main(){
    freopen("input.txt", "r", stdin);
   
    solve();
    
    return 0;
}

