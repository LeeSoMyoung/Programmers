#include <string>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

string solution(string new_id) {
	string answer = "", tmp = "";
	int len = new_id.size();
	forn(i, len) {
		if (new_id[i] >= 'A'&&new_id[i] <= 'Z')
			tmp += new_id[i] - 'A' + 'a';
		else if ((new_id[i] >= '0'&&new_id[i] <= '9') || (new_id[i] >= 'a'&&new_id[i] <= 'z') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') tmp += new_id[i];
	}
	string chk = tmp;
	len = tmp.size();
	int index = 0, cnt = 0;
	while (index < len) {
		if (chk[index] == '.') {
			++cnt;
		}
		else {
			if (cnt) answer += '.';
			cnt = 0;
			answer += chk[index];
		}
		++index;
	}
	if (answer[0] == '.') answer = answer.substr(1, answer.size() - 1);
	if (answer[answer.size() - 1] == '.') answer = answer.substr(answer.size() - 1);
	if (answer == "") answer = "a";
	if (answer.size() >= 16) {
		answer = answer.substr(0,15);
		if (answer[14] == '.') answer = answer.substr(0,14);
	}
	if (answer.size() <= 2) {
		char add = answer[answer.size() - 1];
		while (answer.size() < 3) {
			answer += add;
		}
	}
	return answer;
}
