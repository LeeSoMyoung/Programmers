#include <string>
#include <vector>
#include <map>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb push_back
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int size=record.size();
    vector<pair<string,string>>cmd;
    map<string,string>m;
    forn(i,size){
        int len=record[i].size(), index=0;
        string command,name1,name2;
        command=name1=name2="";
        while(record[i][index]!=' '){
            command+=record[i][index++];
        }
        ++index;
        while(index<len&&record[i][index]!=' '){
            name1+=record[i][index++];
        }
        ++index;
        rep(j,index,len){
            name2+=record[i][j];
        }
        if(command=="Change") m[name1]=name2;
        else if(command=="Leave") cmd.eb({command,name1});
        else{
            cmd.eb({command,name1});
            if(!m.count(name1)) m.insert({name1,name2});
            else if(m[name1]!=name2) m[name1]=name2;
        }
    }
    size=cmd.size();
    forn(i,size) answer.eb(m[cmd[i].second]+(cmd[i].first=="Enter"?"님이 들어왔습니다.":"님이 나갔습니다."));
    return answer;
}
