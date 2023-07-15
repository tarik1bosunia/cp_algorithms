#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> stk;
    queue<int> q1;


    for(int i = 0; i < k; i++){
        stk.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        q1.push(q.front());
        q.pop();
    }

    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }

    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
    }

    return q;
}
