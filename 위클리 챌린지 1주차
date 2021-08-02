
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/82612

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef long long int ll;

ll solution(int price, int money, int count){
    ll myPrice = 1LL*price;
    ll myMoney = 1LL*money;
    ll cnt = 1LL*count;
    ll toPay = cnt*(cnt+1)/2*myPrice;
    ll res = toPay-myMoney;
    return res>=0?res:0;
}
