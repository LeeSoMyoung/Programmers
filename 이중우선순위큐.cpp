
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42628

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

vector<int> solution(vector<string> operations) {
	int size = operations.size(), len, val;
	string tmp;
	priority_queue<int>pq;
	priority_queue<int, vector<int>, greater<int>>minn;
	forn(i, size) {
		switch (operations[i][0]) {
		case 'I':
			tmp = "";
			len = operations[i].size();
			rep(j, 2, len) tmp += operations[i][j];
			val = stoi(tmp);
			pq.push(val);
			minn.push(val);
			break;
		default:
			if (operations[i][2] == '-'&&minn.size()) {
				queue<int>q;
				val = minn.top();
				minn.pop();
				while (pq.top() != val) {
					q.push(pq.top());
					pq.pop();
				}
				pq.pop();
				while (!q.empty()) {
					pq.push(q.front());
					q.pop();
				}
			}
			else if (operations[i][2] == '1'&&pq.size()) {
				queue<int>q;
				val = pq.top();
				pq.pop();
				while (minn.top() != val) {
					q.push(minn.top());
					minn.pop();
				}
				minn.pop();
				while (!q.empty()) {
					minn.push(q.front());
					q.pop();
				}
			}
			break;
		}
	}
	if (pq.empty()) return { 0,0 };
	else return { pq.top(),minn.top() };
}
