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
int vis[1000001], cc[1000001];
int cn = 0;

void bfs(int src){
    queue<int> q;
    q.push(src);
    cc[src] = cn;
    vis[src] = 1;

    while (!q.empty())
    {
        for(int child : ar[src]){
            if(vis[child] == 0){
                vis[child] = 1;
                cc[child] = cn;
                q.push(child);
            }
        }
    }
    
}


void solve(){
    vector<pair<int, int>> edgeList;
    int n, k , a, b;
    string op;
    cn = 0;
    cin >> n >> k;
    for(int i = 0; i<=n;i++){
        ar[i].clear();
        vis[i] = 0;
    }
    for(int i = 1; i<= k ; i++){
        cin >> a >> op >> b;
        if (op == "="){
            ar[a].push_back(b), ar[b].push_back(a);
        }else{
            edgeList.push_back({a, b});
        }
    }

    for(int i = 1; i <=n ; i++){
        if(vis[i] == 0){
            cn++;
            bfs(i);
        }
    }

    bool flag;
    for(int i=0; i < edgeList.size(); i++){
        a = edgeList[i].first;
        b = edgeList[i].second;

        if(cc[a] == cc[b]){
          flag = false;
          break;  
        }
    }
    if(flag) cout << "Feasible" << endl;
    else cout << "Not Feasible" << endl;
    
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

