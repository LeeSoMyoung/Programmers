

// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17680

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(!cacheSize) return 5*cities.size();
    int answer = 0, size=cities.size(), cnt=0;
    map<string,int>m;
    forn(i,size){
        int len=cities[i].size();
        forn(j,len) cities[i][j]=tolower(cities[i][j]);
        if(m.count(cities[i])>0){
            m.erase(m.find(cities[i]));
            m.insert({cities[i],cnt++});
            ++answer;
        }else{
            if(m.size()==cacheSize){
                string chk="";
                int min=(int)1e9;
                for(auto iter=m.begin();iter!=m.end();++iter)
                    if(min>iter->second){
                        min=iter->second;
                        chk=iter->first;
                    }
                m.erase(m.find(chk));
            }
            m.insert({cities[i],cnt++});
            answer+=5;
        }
    }
    return answer;
}
