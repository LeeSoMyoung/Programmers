
// 문제 URL: https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <queue>
#define forn(i,n) for(int i=0;i<n;++i)
#define MAX 32
using namespace std;

bool chk(int lost, int reserve) {
	int diff = lost - reserve;
	return diff >= -1 && diff <= 1;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	int size1 = lost.size();
	int size2 = reserve.size();
	int cnt = 0;
	int sum = 0;

	priority_queue<int, vector<int>, greater<int>>pq;
	priority_queue<int, vector<int>, greater<int>>pq2;

	bool check[MAX];

	fill(check, check + MAX, false);

	forn(i,size1) forn(j,size2)
		if (lost[i] == reserve[j]) {
			check[lost[i]] = true;
			++sum;
		}

	forn(i, size1) {
		if (!check[lost[i]]) {
			pq.push(lost[i]);
		}
	}

	forn(i, size2) {
		if (!check[reserve[i]]) {
			pq2.push(reserve[i]);
		}
	}

	while (!pq.empty()&&!pq2.empty()) {
		int cur = pq.top();
		int res = pq2.top();

		if (chk(cur, res)) {
			++cnt;
			pq.pop();
			pq2.pop();
		}
		else {
			if (cur < res) {
				pq.pop();
			}
			else {
				pq2.pop();
			}
		}
	}
	return n - size1+sum + cnt;
}
