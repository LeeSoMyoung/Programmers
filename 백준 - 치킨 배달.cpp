// 문제 링크 : https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <math.h>
#define MAX 50
#define MAX_CHICKEN 13
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool visited[MAX_CHICKEN];
int ans = (int)1e9;

int get_distance(pii p1, pii p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

int total_distance(vpii& house, vpii chicken){
    int res = 0;
    int house_size = house.size();
    int chicken_size = chicken.size();
    
    for(int i=0;i<house_size;++i){
        int minn = (int)1e9;
        
        for(int j=0;j<chicken_size;++j){
            minn = min(minn, get_distance(house[i], chicken[j]));
        }
        
        res+=minn;
    }
    
    return res;
}

vpii get_included(vpii& chicken){
    vpii res;
    int size = chicken.size();
    
    for(int i=0;i<size;++i){
        if(visited[i]){
            res.push_back(chicken[i]);
        }
    }
    
    return res;
}

void go(int target, int index, int cnt, vpii& house, vpii& chicken) {
    if(target == cnt){
        ans = min(total_distance(house, get_included(chicken)), ans);
        return;
    }
    
    int size = chicken.size();
    
    for(int i=index+1;i<size;++i){
        if(!visited[i]){
            visited[i] = true;
            go(target, i, cnt+1, house, chicken);
            visited[i] = false;
        }
    }
    
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    int info;
    vpii house;
    vpii chicken;
    
    cin>>n>>m;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>info;
            
            if(info == 1) {
                house.push_back(pii(i, j));
            }
            else if(info == 2){
                chicken.push_back(pii(i, j));
            }
        }
    }
    
    for(int i=1;i<=m;++i){
        go(i, -1, 0, house, chicken);
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
