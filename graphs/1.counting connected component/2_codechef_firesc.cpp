#include<bits/stdc++.h>
#define MOD int(1e9+7)
#define lli long long int

using namespace std;

vector<int> ar[100001];
bool vis[100001];
lli way_to_choose_leader;
lli member_in_one_group;

void dfs(int s){
    vis[s] = true;
    member_in_one_group++;

    for(int child : ar[s]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    
    int t, n, m, a, b;
    cin >> t;
    while (t--)
    {
       cin >> n >> m;
       for(int i = 1; i <= n; i++){
            ar[i].clear();
            vis[i] = false;
       }
       while (m--)
       {
         cin >> a >> b;
         ar[a].push_back(b), ar[b].push_back(a);
       }

       lli cc = 0;
       way_to_choose_leader = 1;

       for(int i = 1; i <=n; i++){
            if(!vis[i]){
                member_in_one_group = 0;
                cc++;
                dfs(i);

                way_to_choose_leader = (member_in_one_group * way_to_choose_leader)%MOD;

            }
       }

       cout << cc << " " << way_to_choose_leader << endl;
       
    }
    
    
    
    return 0;
}
