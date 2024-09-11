#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001][2];

vector<int> solution(int target) {
    vector<int> answer;
    
    for(int i = 1; i <= target; i++){
        if(i <= 20 || i == 50){  // 1~20점 또는 50점인 경우
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else if(i <= 60 && i % 3 == 0){  // 60 이하의 3배수
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        else if(i <= 40 && i % 2 == 0){  // 40 이하의 2배수
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        else if(i > 50 && i <= 70){  // 50보다 크고 70 이하
            dp[i][0] = 2;
            dp[i][1] = 2;
        }
        else if(i < 70){  // 70보다 작은 경우
            if(i < 40){
                dp[i][0] = 2;
                dp[i][1] = 2;
            } else {
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
        }
        else {  // 그 외의 경우
            if(i >= 60 && dp[i-60][0] == dp[i-50][0]){
                dp[i][0] = dp[i-50][0] + 1;
                dp[i][1] = max(dp[i-60][1], dp[i-50][1] + 1);
            }
            else if(i >= 60 && dp[i-60][0] < dp[i-50][0]){
                dp[i][0] = dp[i-60][0] + 1;
                dp[i][1] = dp[i-60][1];
            }
            else {
                dp[i][0] = dp[i-50][0] + 1;
                dp[i][1] = dp[i-50][1] + 1;
            }
        }
    }
    
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);
    return answer;
}
