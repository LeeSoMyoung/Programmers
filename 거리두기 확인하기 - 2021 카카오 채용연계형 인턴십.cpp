
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/81302

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define SIZE 5
using namespace std;

bool chk(int y, int x) {
	return x >= 0 && y >= 0 && x < SIZE&&y < SIZE;
}
int ab(int x) {
	return x > 0 ? x : -x;
}
int dist(int x1, int y1, int x2, int y2) {
	return ab(x1 - x2) + ab(y1 - y2);
}
vector<int> solution(vector<vector<string>> places) {
	int dx[12] = { -2,-1,-1,-1,0,0,0,0,1,1,1,2 }, dy[12] = { 0,-1,0,1,1,-1,2,-2,1,0,-1,0 };
	vector<int> answer(SIZE);
	forn(i, SIZE) {
		int flag = 1;
		forn(j, SIZE) {
			forn(k, SIZE) {
				if (places[i][j][k] != 'P') continue;
					forn(l, 12) {
					int nexty = j + dy[l], nextx = k + dx[l];
					if (!chk(nexty,nextx)||places[i][nexty][nextx]!='P') continue;
					if (dist(nexty, nextx, j, k) == 1) {
						flag = 0;
						break;
					}
					if (nexty == j) {
						if (nextx > k) {
							if (chk(j,k+1)&&places[i][j][k + 1] == 'O') {
								flag = 0;
								break;
							}
						}
						else {
							if (chk(j,k-1)&&places[i][j][k - 1] == 'O') {
								flag = 0;
								break;
							}
						}
					}
					else if (nextx == k) {
						if (nexty > j) {
							if (chk(j+1,k)&&places[i][j+1][k] == 'O') {
								flag = 0;
								break;
							}
						}
						else {
							if (chk(j-1,k)&&places[i][j-1][k] == 'O') {
								flag = 0;
								break;
							}
						}
					}
					else {
						if (places[i][j][nextx] == 'O' || places[i][nexty][k] == 'O') flag = 0;
					}
					if (!flag) break;
				}
				if (!flag) break;
			}
			if (!flag) break;
		}
		answer[i] = flag;
	}
	return answer;
}
