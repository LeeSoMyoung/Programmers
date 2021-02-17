
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17684

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;

vector<int> solution(string msg) {
    map<string, int>m;
    vector<int> answer;
    int size = msg.size(), index = 0, cnt = 27;
    string chk="", next;
    forn(i, 26) {
        string str = "";
        str += ('A' + i);
        m[str] = i + 1;
    }
    while (index < size) {
        chk="";
        for(int i=size-index;!m.count(chk);--i){
            chk=msg.substr(index,i);
        }
        answer.eb(m[chk]);
        next=chk+msg[index+chk.size()];
        if(!m.count(next)) m.insert({next,cnt++});
        index += chk.size();
    }
    return answer;
}
