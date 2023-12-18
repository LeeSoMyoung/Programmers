// 문제 링크: https://www.acmicpc.net/problem/3190

#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

typedef pair<int, int> pii;

int g[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int n, k,m,y,x,ans=0,dir=0,now;
	int dx[4] = { 1,0,-1,0 }, dy[4] = {0,1,0,-1};
	char next;
	queue<pii>q;
	cin >> n >> k;

    while (k--) {
		cin >> y >> x;
		g[y][x] = 1;
	}
	cin >> m >> now;
    
	y = 1, x = 1;
	q.push(pii(1, 1));
	g[1][1] = 2;
    
	while (1) {
		++ans;
		x += dx[dir], y += dy[dir];
		if (x <= 0 || y <= 0 || x > n || y > n||g[y][x]==2) return cout << ans << '\n', 0;
		if (!g[y][x]) {
			int yy = q.front().first, xx = q.front().second;
			q.pop();
			g[yy][xx] = 0;
		}
		g[y][x] = 2;
		q.push(pii(y, x));
		if (ans == now) {
			cin >> next;
			if (--m) cin >> now;
			if (next == 'L') dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
		}
	}
}
