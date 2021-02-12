#include <string>
#include <vector>
#include <stack>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, size=board.size(),len=moves.size(), doll;
    stack<int>st;
    forn(i,len){
        int cur=moves[i]-1;
        forn(j,size){
            if(!board[j][cur]) continue;
            doll=board[j][cur];
            board[j][cur]=0;
            bool flag=true;
            while(!st.empty()&&st.top()==doll){
                if(flag){
                    flag=false;
                    answer++;
                }
                st.pop();
                ++answer;
            }
            if(flag) st.push(doll);
            break;
        }
    }
    return answer;
}
