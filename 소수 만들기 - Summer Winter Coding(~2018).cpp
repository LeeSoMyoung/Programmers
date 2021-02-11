#include <vector>
#include <iostream>
#define MAX ((int)3e3+1)
using namespace std;

bool isNotPrime[MAX];
vector<int>array;
void go(int index,int cnt,int sum,int *answer){
    sum+=array[index];
    if(cnt==3){
        if(!isNotPrime[sum]) ++*answer;
        return;
    }
    for(int i=index+1;i<array.size();++i)
        go(i,cnt+1,sum,answer);
}
int solution(vector<int> nums) {
    int answer = 0, size=nums.size();
    array=nums;
    isNotPrime[1]=true;
    for(int i=2;i<MAX;++i)
        if(!isNotPrime[i])
            for(int j=i*2;j<=MAX;j+=i)
                isNotPrime[j]=true;
    for(int i=0;i<size;++i)
        go(i,1,0,&answer);
    return answer;
}
