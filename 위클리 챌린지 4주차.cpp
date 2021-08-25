
// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/84325

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;


bool search(string target, vector<string>languages) {
	int start = 0, rear = languages.size() - 1, mid;
	while (start <= rear) {
		mid = (start + rear) >> 1;
		if (languages[mid] == target) return true;
		else if (languages[mid] > target) rear = mid - 1;
		else start = mid + 1;
	}
	return false;
}

bool cmp(const pair<string, int>&a, const pair<string, int>&b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	map<string, int> subject;
	int size = languages.size();
	vector<vector<string>> scores(5, vector<string>(5));
	map<string, int> pref;
	map<string, int> ans;
	forn(i, size) {
		pref[languages[i]] = preference[i];
	}
	sort(languages.begin(), languages.end());
	forn(i, 5) {
		int cnt = 0;
		string sub = "";
		bool flag = false;
		int len = table[i].size();
		forn(j, len) {
			if (!flag) {
				if (table[i][j] != ' ') sub += table[i][j];
				else {
					flag = true;
					subject[sub] = i;
					ans[sub] = 0;
				}
				continue;
			}
			string lang = "";
			while (j < len&&table[i][j] != ' ') {
				lang += table[i][j++];
			}
			scores[i][cnt++] = lang;
		}
	}
	for (auto iter = subject.begin(); iter != subject.end(); ++iter) {
		forn(i,5)
			if (search(scores[iter->second][i], languages)) {
				ans[iter->first] += (pref[scores[iter->second][i]] * (5 - i));
			}
	}
	vector<pair<string,int>> ret(ans.begin(), ans.end());
	sort(ret.begin(), ret.end(), cmp);
	return ret[0].first;
}
