#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

vector<int> solution(string s) {
    vector<int> answer,arr;
    int size=s.size();
    priority_queue<pair<int,int>>pq;
    map<int,int>m;
    string tmp="";
    forn(i,size){
        if(s[i]=='{'||s[i]=='}'||s[i]==','){
            if(tmp!=""){
                arr.eb(stoi(tmp));
                tmp="";
            }
            continue;
        }
        tmp+=s[i];
    }
    if(tmp!="") arr.eb(stoi(tmp));
    sort(all(arr));
    size=arr.size();
    forn(i,size){
        if(!m.count(arr[i])) m.insert({arr[i],1});
        else ++m[arr[i]];
    }
    for(auto it=m.begin();it!=m.end();++it)
        pq.push({it->second,it->first});
    while(!pq.empty()){
        answer.eb(pq.top().second);
        pq.pop();
    }
    return answer;
}
