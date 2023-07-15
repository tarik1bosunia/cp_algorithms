#include<bits/stdc++.h>

using namespace std;

int ar[1001][1001];
bool vis[1001][1001];
int dist[1001][1001];

int N, M;

bool isValid(int x, int y){
    if(x < 1 || x > N || y < 1 || y > M) return false;

    if(vis[x][y]) return false;

    return true;
}

void bfs(int srcX, int srcY){
    queue<pair<int, int >> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = true;
    dist[srcX][srcY] = 0;

    int dx[] = {-1, 1, 0 , 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            
            if(isValid(currX + dx[i], currY + dy[i])){
                int newX = currX + dx[i];
                int newY =  currY + dy[i];
             
                q.push({newX, newY});
                vis[newX][newY] = true;
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }
    
    
}



int main(){

    
    cin >> N >> M;

    bfs(1, 1);
    
    
    return 0;
}
