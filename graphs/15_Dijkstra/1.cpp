#include<bits/stdc++.h>
#define INF 1e9

using namespace std;

vector<pair<int,int>> ar[1001];

void diskstra(int n){
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    
    vector<int> dist(n+1, INF);

    pq.push({0, 1});
    dist[1] = 0;
    cout << "wr" << endl;
    
    while (!pq.empty())
    {
        int src_dist = pq.top().first;
        int src_node = pq.top().second;
        pq.pop();

        for(pair<int, int> edge : ar[src_node]){
            if(src_dist + edge.second < dist[edge.first]){
                dist[edge.first] = src_dist + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n, m , a, b, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> w;
        ar[a].push_back({b, w}), ar[b].push_back({a, w});
    }
    
    diskstra(n);
    
    return 0;
}
