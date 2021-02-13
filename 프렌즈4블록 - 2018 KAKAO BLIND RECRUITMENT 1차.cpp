

// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17679


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

bool flag;
void deleted(int y, int x, vector<string>&board, vector<pii>&arr) {
	bool chk = true;
	if (board[y][x] == '.') return;
	forn(i, 2) {
        forn(j, 2)
			if (board[y][x] != board[y + i][x + j]) {
				chk = false;
				break;
			}
		if (!chk) break;
	}
	if (chk) {
		flag = true;
		forn(i, 2) forn(j, 2)
			arr.pb(pii(y + i, x + j));
	}
	return;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	do {
		flag = false;
		vector<pii> arr;
		forn(i, m-1) forn(j, n-1)
			deleted(i, j, board, arr);
		sort(all(arr));
		arr.erase(unique(all(arr)), arr.end());
		int len = arr.size();
		answer += len;
		forn(i, len) board[arr[i].first][arr[i].second] = '.';
		forn(i, n) {
			queue<char>q;
			forn(j, m) if (board[j][i] != '.') q.push(board[j][i]);
			forn(j, m - q.size()) board[j][i] = '.';
			rep(j, m-q.size(), m) {
				board[j][i] = q.front();
				q.pop();
			}
		}
	} while (flag);
	return answer;
}
