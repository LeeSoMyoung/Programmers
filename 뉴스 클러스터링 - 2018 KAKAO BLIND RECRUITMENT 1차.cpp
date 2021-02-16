

// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17677

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

string convert(string& str){
    int size=str.size();
    string ret="";
    forn(i,size){
        if(str[i]>='A'&&str[i]<='Z') ret+=tolower(str[i]);
        else ret+=str[i];
    }
    return ret;
}
int solution(string str1, string str2) {
    str1=convert(str1);
    str2=convert(str2);
    map<string, int>m1,m2;
    int len1=str1.size(), len2=str2.size();
    vector<string> arr1,arr2,uni,inter;
    forn(i,len1-1){
        string in=str1.substr(i,2);
        bool flag=true;
        forn(j,2)
            if(in[j]<'a'||in[j]>'z'){
                flag=false;
                break;
            }
        if(!flag) continue;
        arr1.pb(in);
        ++m1[in];
    }
    forn(i,len2-1) {
        string in=str2.substr(i,2);
        bool flag=true;
        forn(j,2)
            if(in[j]<'a'||in[j]>'z'){
                flag=false;
                break;
            }
        if(!flag) continue;
        arr2.pb(in);
        ++m2[in];
    }
    uni=arr1;
    len1=arr1.size();
    len2=arr2.size();
    forn(i,len2) uni.pb(arr2[i]);
    sort(all(uni));
    uni.erase(unique(all(uni)),uni.end());
    int size=uni.size();
    int whole=0,intersect=0;
    forn(i,size) whole+=max(m1[uni[i]],m2[uni[i]]);
    forn(i,len1) forn(j,len2)
        if(arr1[i]==arr2[j])
            inter.pb(arr1[i]);
    sort(all(inter));
    inter.erase(unique(all(inter)),inter.end());
    size=inter.size();
    forn(i,size)
        intersect+=min(m1[inter[i]],m2[inter[i]]);
    return !whole?65536:intersect*65536/whole;
}
