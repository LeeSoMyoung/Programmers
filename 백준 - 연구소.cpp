// 문제 링크 : https://www.acmicpc.net/problem/14502

#include <iostream>
#include <queue>
#include <vector>
#define MAX 8
using namespace std;

typedef pair<int, int> pii;

int n, m;
bool visited[MAX][MAX];
int board[MAX][MAX];
int newBoard[MAX][MAX];
int maxx = -1;

int count_safe_place() {
    int res = 0;
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(newBoard[i][j] == 0){
            	++res;
            }
        }
    }
    
    return res;
}

void bfs(int y, int x) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    queue<pii> q;
    
    q.push(pii(y, x));
    
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        
        for(int i=0;i<4;++i){
            int yy = cur.first+dy[i];
            int xx = cur.second+dx[i];
            
            if(xx<0||yy<0||xx>=m||yy>=n||newBoard[yy][xx]) continue;
            
            q.push(pii(yy,xx));
            
            newBoard[yy][xx] = 2;
        }    
    }
    
    return;
}

void copyBoard() {
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j){
			newBoard[i][j] = board[i][j];	
		}
	}
	
	return;
}

void go(int y, int x, vector<pii> &wall) {
    if(wall.size() == 3){
        copyBoard();
        
        for(int i=0;i<3;++i){
            int yy = wall[i].first;
            int xx = wall[i].second;
            
            newBoard[yy][xx] = 1;
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(newBoard[i][j] == 2){
                    bfs(i, j);
                }
            }
        }
        
        maxx = max(maxx, count_safe_place());
        
        return;
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!board[i][j] && !visited[i][j]){
                visited[i][j] = true;
                
                vector<pii> wallList;
                
                for(int i=0;i<wall.size();++i){
                	wallList.push_back(wall[i]);
                }
                
                wallList.push_back(pii(i,j));
                
                go(i, j, wallList);
                visited[i][j] = false;
            }
        }
    }
    
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin>>board[i][j];
        }
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!board[i][j] && !visited[i][j]){
                visited[i][j] = true;
                vector<pii> walls;
                walls.push_back(pii(i,j));
                go(i, j, walls);
                visited[i][j] = false;
            }
        }
    }
    
    
    cout<<maxx<<'\n';
    
    return 0;
}
