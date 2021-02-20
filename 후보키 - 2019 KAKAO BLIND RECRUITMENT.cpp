

// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42890

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;

bool chk(vector<int>&arr,int cur){
    int size=arr.size();
    forn(i,size)
        if((arr[i]&cur)==arr[i]) return false;
    return true;
}
int solution(vector<vector<string>> relation) {
    int size=relation.size(),n=relation[0].size();
    vector<int>arr;
    rep(i,1,1<<n){
        map<string,int>m;
        forn(j,size){
            string tmp="";
            forn(k,n) if(i&(1<<k)) tmp+=relation[j][k];
            ++m[tmp];
        }
        if(m.size()==size&&chk(arr,i)) arr.eb(i);
    }
    return arr.size();
}
