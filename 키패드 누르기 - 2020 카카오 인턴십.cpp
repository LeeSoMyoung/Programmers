
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/67256

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;
typedef pair<int,int> pii;

int dist(pii a, pii b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
pii dot(char x){
    switch(x){
        case '*':
            return pii(0,0);
            
        case '#':
            return pii(2,0);
            
        case '0':
            return pii(1,0);
            
        default:
            int chk=x-'0';
            switch(chk%3){
                case 1:
                    return pii(0,3-chk/3);
                    
                case 2:
                    return pii(1,3-chk/3);
                    
                default:
                    return pii(2,4-chk/3);
            }
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    char left='*', right='#';
    int len=numbers.size();
    forn(i,len){
        switch(numbers[i]%3){
            case 0:
                if(numbers[i]){
                right=numbers[i]+'0';
                answer+='R';
                break;}
            
            case 1:
                if(numbers[i]){
                answer+='L';
                left=numbers[i]+'0';
                break;
                }
                
            default:
                pii l=dot(left), r=dot(right), cur=dot(numbers[i]+'0');
                int distLeft=dist(l,cur), distRight=dist(r,cur);
                if(distLeft>distRight){
                    answer+='R';
                    right=(numbers[i]+'0');
                }
                else if(distLeft<distRight){
                    answer+='L';
                    left=(numbers[i]+'0');
                }
                else{
                    if(hand=="right"){
                        answer+='R';
                        right=(numbers[i]+'0');
                    }else{
                        answer+='L';
                        left=(numbers[i]+'0');
                    }
                }
                break;
        }
    }
    return answer;
}
