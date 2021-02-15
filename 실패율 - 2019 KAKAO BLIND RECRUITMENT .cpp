
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42889

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define pb push_back
using namespace std;
typedef pair<int,double> pdi;

bool cmp(pdi a, pdi b){
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int>ret;
    int size=stages.size();
    sort(all(stages));
    vector<pdi>arr;
    map<int,int>m;
    forn(i,size){
        if(!m.count(stages[i])) m.insert({stages[i],1});
        else ++m[stages[i]];
    }
    rep(i,1,N+1){
        arr.pb(!size||!m[i]?pdi(i,0.0):pdi(i,(double)m[i]/size));
        size-=m[i];
    }
    sort(all(arr),cmp);
    for(pdi chk:arr) ret.pb(chk.first);
    return ret;
}
