
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60057

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

int solution(string s) {
    int answer=s.size(), size=answer,chk=(size>>1)+1,cnt;
    rep(i,1,chk){
        string tmp="",check=s.substr(0,i);
        int index=i;
        cnt=1;
        for(int j=i;j<size;j+=i){
            if(check==s.substr(j,i)) ++cnt;
            else{
                if(cnt>1) tmp+=to_string(cnt);
                tmp+=check;
                check=s.substr(j,i);
                cnt=1;
            }
        }
        if(cnt>1) tmp+=to_string(cnt);
        tmp+=check;
        int compare=tmp.size();
        answer=min(answer,compare);
    }
    return answer;
}
