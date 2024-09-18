#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321

int max_dp[201][201];
int min_dp[201][201];

int solution(vector<string> arr)
{
    int answer = -1;
    int nums[201];
    string op[201];
    
    int num_idx = 0, op_idx = 0;
    for (int i = 0; i < arr.size(); i++){
        if (i % 2 == 0) {  
            nums[num_idx++] = stoi(arr[i]);
        } else {  
            op[op_idx++] = arr[i];
        }
    }
    
    int num = arr.size()/2 + 1;     
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            max_dp[i][j] = -INF;
            min_dp[i][j] = INF;
        }
    }
    

    for(int i = 0; i < num; i++){
        max_dp[i][i] = min_dp[i][i] = nums[i];
    }
    
    for(int cnt = 0; cnt < num; cnt++){
        for(int i = 0; i < num-cnt; i++){
            int j = i + cnt;
            for(int k = i; k < j; k++){
                if(op[k] == "+"){
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k]+max_dp[k+1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k]+min_dp[k+1][j]);
                }
                else{
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k]-min_dp[k+1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k]-max_dp[k+1][j]);
                }
            }
        }
    }
    answer = max_dp[0][num-1];
    return answer;
}