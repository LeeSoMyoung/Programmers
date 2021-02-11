#include <string>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;

int square(int x){ return x*x; }
int triple(int x){ return x*square(x); }
int minuss(int x){return -x;}
int solution(string dartResult) {
    int answer = 0,len=dartResult.size(), index=0, val=0, prev;
    string tmp;
    while(index<len){
        tmp="";
        while(dartResult[index]>='0'&&dartResult[index]<='9'){
            tmp+=dartResult[index++];
        }
        if(tmp!=""){
            prev=val;
            val=stoi(tmp);
        }else{
            switch(dartResult[index]){
                case 'S':
                    answer+=val;
                    break;

                case 'D':
                    val=square(val);
                    answer+=val;
                    break;

                case 'T':
                    val=triple(val);
                    answer+=val;
                    break;

                case '#':
                    answer-=2*val;
                    val=minuss(val);
                    break;

                case '*':
                    answer+=prev+val;
                    val*=2;
                    break;

                default:
                    break;
            }
            ++index;
        }
    }

    return answer;
}
