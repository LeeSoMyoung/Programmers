
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/86971

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vvi g;
vi cnt;
vb visited;
int dfs(int cur){
    int size = g[cur].size();
    forn(i,size){
        int next = g[cur][i];
        if(visited[next]) continue;
        visited[next]=true;
        cnt[cur]+=dfs(next);
    }
    return cnt[cur];
}
int solution(int n, vector<vector<int>> wires) {
    int size = wires.size();
    cnt.resize(n+1);
    visited.resize(n+1);
    g.resize(n+1);
    forn(i,n+1){
        cnt[i]=1;
        visited[i]=false;
    }
    forn(i,size){
        g[wires[i][0]].eb(wires[i][1]);
        g[wires[i][1]].eb(wires[i][0]);
    }
    visited[1]=true;
    dfs(1);
    int ans = (int)1e9;
    rep(i,1,n+1){
        int cur = cnt[i];
        ans = min(ans, max(n-cur,cur)-min(n-cur,cur));
    }
    return ans;
}
