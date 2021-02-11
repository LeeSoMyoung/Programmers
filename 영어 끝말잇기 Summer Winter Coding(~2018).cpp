#include <string>
#include <vector>
#include <iostream>
#include <map>
#define eb emplace_back
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int size=words.size();
    map<string,int>m;
    m.insert({words[0],1});
    for(int i=1;i<size;++i){
        if(words[i-1][words[i-1].size()-1]!=words[i][0]){
            answer.eb(i%n+1);
            answer.eb(i/n+1);
            return answer;
        }
        if(m.find(words[i])!=m.end()){
            answer.eb(i%n+1);
            answer.eb(i/n+1);
            return answer;
        }
        m.insert({words[i],1});
    }
    return vector<int>(2,0);
}
