

// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60058

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

bool chk(string& str){
    int len=str.size();
    stack<char>st;
    forn(i,len){
        if(str[i]=='(') st.push('(');
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    return true;
}
string getAnswer(string str){
    if(str=="") return "";
    int left=0, right=0, len=str.size();
    string lft,rht;
    forn(i,len){
        if(str[i]=='(') ++left;
        else ++right;
        if(left==right){
            lft=str.substr(0,i+1);
            rht=str.substr(i+1);
            break;
        }
    }
    if(chk(lft)) return lft+getAnswer(rht);
    else{
        string tmp="(";
        tmp+=getAnswer(rht)+")";
        lft=lft.substr(1,lft.size()-2);
        len=lft.size();
        forn(i,len) tmp+=(lft[i]=='('?')':'(');
        return tmp;
    }
}
string solution(string p) {
    return chk(p)?p:getAnswer(p);
}
