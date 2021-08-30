
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/84512

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

string arr[5];
void go(string cur, int *cnt, int *answer, string target) {
	if (target == cur) {
		*answer = *cnt;
		return;
	}
	else if (cur.length() == 5) return;
	forn(i, 5) {
		++*cnt;
		go(cur + arr[i], cnt, answer, target);
	}
	return;
}
int solution(string word) {
	int answer = 0, cnt = 0;
	arr[0] = "A";
	arr[1] = "E";
	arr[2] = "I";
	arr[3] = "O";
	arr[4] = "U";
	forn(i, 5) {
		if (!answer){
            ++cnt;
			go(arr[i], &cnt, &answer, word);
        }
		else
			return answer;
	}
	return answer;
}
