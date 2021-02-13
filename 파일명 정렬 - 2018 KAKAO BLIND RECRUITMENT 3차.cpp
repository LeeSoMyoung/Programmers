#include <string>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) rep(i,0,n)
#define all(x) x.begin(),x.end()
using namespace std;

typedef struct s{
   string head, tail;
    int num,index;
    string name;
    bool operator<(const s& cmp) const{
        if(head==cmp.head){
            if(num==cmp.num) return index<cmp.index;
            return num<cmp.num;
        }
        return head<cmp.head;
    }
}s;
vector<string> solution(vector<string> files) {
    int size=files.size();
    vector<string> answer(size);
    vector<s> arr(size);
    forn(i,size){
        string head="",tail="",tmp="";
        int num,index=0,len=files[i].size();
        while(index<len&&(files[i][index]<'0'||files[i][index]>'9')){
            head+=tolower(files[i][index++]);
        }
        while(index<len&&(files[i][index]>='0'&&files[i][index]<='9')){
            tmp+=files[i][index++];
        }
        num=stoi(tmp);
        while(index<len){
            tail+=tolower(files[i][index++]);
        }
        arr[i].head=head; arr[i].tail=tail;
        arr[i].num=num; arr[i].name=files[i];
        arr[i].index=i;
    }
    sort(all(arr));
    forn(i,size) answer[i]=arr[i].name;
    return answer;
}
