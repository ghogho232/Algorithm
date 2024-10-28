#include <iostream>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int dp[20001];

int solution(vector<string> strs, string t)
{
    int answer = -1;
    int idx = 0;
    bool flag = true;
    for(int i = 1; i <= t.size(); i++){
        dp[i] = INF;
    }    
    
    for(int i = 1; i <= t.size(); i++){
        for(int j = 0; j < strs.size(); j++){
            idx = i - strs[j].length();
            if(idx < 0) continue;
            flag = true;
            for(int k = 0; k < strs[j].size(); k++){
                if(t[idx+k] != strs[j][k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                dp[i] = min(dp[i], dp[idx]+1);
            }
        }
    }
    answer = dp[t.size()];
    if(answer == INF) answer = -1;
    return answer;
}