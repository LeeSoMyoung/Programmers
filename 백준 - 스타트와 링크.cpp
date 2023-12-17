// 문제 링크 : https://www.acmicpc.net/problem/14889

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#define MAX 21
using namespace std;

int n;
int minn = (int)1e9;
bool visited[MAX];
int scores[MAX][MAX];
int teamA[MAX/2];
int teamB[MAX/2];

int getDiff(int n) {
    int sumA = 0;
    int sumB = 0;

    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j){
            if(i == j) continue;
            sumA+=scores[teamA[i]][teamA[j]];
            sumB+=scores[teamB[i]][teamB[j]];
        }
    }
    
    return abs(sumA - sumB);
}

void go(int n, int length, int index) {
    if(length == n/2) {
        int idx = 0;
        for(int i=0;i<n;++i){
           if(!visited[i]){
               teamB[idx++] = i;
           } 
        }
        
        minn = min(minn, getDiff(n/2));
        
        return;
    }
    
    for(int i=index;i<n;++i) {
        if(!visited[i]) {
            visited[i] = true;
            teamA[length] = i;
            go(n, length+1, i+1);
            visited[i] = false;
        }
    }
    
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j){
            cin>>scores[i][j];
        }
    }
    
    for(int i=0;i<n;++i) {
        visited[i] = true;
        teamA[0] = i;
        go(n, 1, i);
        visited[i] = false;
    }
    
    cout<<minn<<'\n';
    
    return 0;
}
