
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define inf (int)1e9
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int size=fares.size(),ret;
    vector<vector<int>>dist(n,vector<int>(n,inf));
    forn(i,n) dist[i][i]=0;
    forn(i,size) 
        dist[fares[i][0]-1][fares[i][1]-1]=dist[fares[i][1]-1][fares[i][0]-1]=fares[i][2];
    forn(k,n) forn(i,n) forn(j,n)
        if(dist[i][j]>dist[i][k]+dist[k][j])
            dist[i][j]=dist[i][k]+dist[k][j];
    ret=dist[s-1][a-1]+dist[s-1][b-1];
    if(ret==dist[a-1][b-1]) return ret;
    forn(i,n){
        if(dist[s-1][i]==inf||dist[i][a-1]==inf||dist[i][b-1]==inf) continue;
        ret=min(ret,dist[s-1][i]+dist[i][a-1]+dist[i][b-1]);
    }
    return ret;
}
