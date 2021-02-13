
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17687

#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

string str(int n, int k) {
	if (!n) return "0";
	string ret = "";
	while (n) {
		int x = n % k;
		if (x < 10) ret += x + '0';
		else ret += x - 10 + 'A';
		n /= k;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string solution(int n, int t, int m, int p) {
	string answer = "", tmp = "";
	int cnt = 0, index = p - 1, plus = 0;
	while (cnt < t) {
		while (tmp.size() <= index) {
			tmp += str(plus++, n);
		}
		answer += tmp[index];
		index += m;
		++cnt;
	}
	return answer;
}
