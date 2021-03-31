
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43238

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef long long int ll;

ll check(ll time,int n,vector<int>times){
    int size=times.size();
    ll sum=0;
    forn(i,size) sum+=time/times[i];
    return sum;
}
long long solution(int n, vector<int> times) {
    ll front=0, rear=(ll)1e15,mid;
    while(front<rear){
        mid=(front+rear)>>1;
        if(check(mid,n,times)>=n) rear=mid;
        else front=mid+1;
    }
    return front;
}
