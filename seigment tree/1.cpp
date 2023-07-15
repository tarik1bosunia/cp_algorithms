#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int st[1000];
int arr[1000];

void buildTree(int si, int ss, int se){
    if (ss == se){
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    buildTree(2 * si, ss, mid);
    buildTree(2 * si + 1, mid + 1, se);

    st[si] = min(st[2 * si], st[2 * si + 1]);
}
void update(int si, int ss, int se, int qi){
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    if(qi<= mid) update(2 * si, ss, mid, qi );
    else update(2 * si + 1, mid + 1, se, qi );

    st[si] = min(st[2 * si], st[2* si + 1]);
}

int query(int si, int ss, int se, int qs, int qe){
    if(qs > se || qe < ss) // completely outside
    return INF;

    if(ss >= qs && se <= qe) // completely inside
    return st[si];

    int mid = (ss + se) / 2;

    int l = query(2 * si , ss , mid, qs, qe);
    int r = query(2 * si + 1 , mid+1, se, qs, qe);


    return min(l, r);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    
    return 0;
}
