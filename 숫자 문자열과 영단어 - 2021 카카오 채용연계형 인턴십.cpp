
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/81301

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

int solution(string s) {
	map<string, string> num;
	num["zero"] = "0";
	num["one"] = "1";
	num["two"] = "2";
	num["three"] = "3";
	num["four"] = "4";
	num["five"] = "5";
	num["six"] = "6";
	num["seven"] = "7";
	num["eight"] = "8";
	num["nine"] = "9";
	string convert = "", tmp;
	int len = s.size(), index = 0;
	while (index < len) {
		if (s[index] >= '0'&&s[index] <= '9') {
			if (tmp != "") convert += num[tmp];
			convert += s[index++];
			tmp = "";
		}
		else {
			if (num.count(tmp)) {
				convert += num[tmp];
				tmp = "";
			}
			else tmp += s[index++];
		}
	}
	if (num.count(tmp)) convert += num[tmp];
	return stoi(convert);
}
