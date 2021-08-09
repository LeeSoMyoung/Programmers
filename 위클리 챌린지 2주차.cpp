
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/83201

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int size = scores.size(),maxx,minn,sum,div;
    vector<vector<int>>score(size,vector<int>(size));
    forn(i,size) forn(j,size)
        score[i][j]=scores[j][i];
    forn(i,size){
        map<int,int>m;
        div=size;
        maxx=-1;
        minn=(int)1e9;
        sum=0;
        forn(j,size){
            ++m[score[i][j]];
            maxx=max(maxx,score[i][j]);
            minn=min(minn,score[i][j]);
            sum+=score[i][j];
        }
        if(score[i][i]==minn||score[i][i]==maxx)
            if(m[score[i][i]]==1){
                --div;
                sum-=score[i][i];
            }
        sum/=div;
        switch(sum/10){
            case 10: case 9:
                answer+='A';
                break;
            case 8:
                answer+='B';
                break;
            case 7:
                answer+='C';
                break;
            case 6: case 5:
                answer+='D';
                break;
                
            default:
                answer+='F';
                break;
        }
    }
    return answer;
}
