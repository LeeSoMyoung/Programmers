#include <string>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define eb emplace_back
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    int size=arr1.size();
    vector<string> answer(size);
    vector<int> arr(size);
    string tmp;
    forn(i,size) arr[i]=arr1[i]|arr2[i];
    forn(i,size){
        tmp="";
        forn(j,n)
            tmp+=(arr[i]&1<<(n-1-j))?"#":" ";
        answer[i]=tmp;
    }
    return answer;
}
