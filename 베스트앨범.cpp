

//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42579

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
#define all(x) x.begin(),x.end()
using namespace std;

bool cmp(pair<string,int>a, pair<string,int>b){
    return a.second>b.second;
}
bool comp(pair<pair<string,int>,int>a, pair<pair<string,int>,int>b){
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size=plays.size();
    map<string,int>chk;
    map<pair<string,int>,int>m;
    forn(i,size){
        m[{genres[i],i}]=plays[i];
        chk[genres[i]]+=plays[i];
    }
    vector<pair<string,int>>check(all(chk));
    vector<pair<pair<string,int>,int>>arr(all(m));
    size=chk.size();
    sort(all(check),cmp);
    sort(all(arr),comp);
    forn(i,size){
        int len=arr.size(),cnt=0;
        forn(j,len) if(arr[j].first.first==check[i].first){
            answer.eb(arr[j].first.second);
            if(cnt||check[i].second==1) break;
            ++cnt;
        }
    }
    return answer;
}
