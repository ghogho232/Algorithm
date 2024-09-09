#include <string>
#include <vector>
#define ll long long
#define MOD 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int dp[100001];
    dp[0] = 1;
    for(int i = 0; i < money.size(); i++){
        for(int j = money[i]; j <= n; j++){
            dp[j] = dp[j] + dp[j-money[i]];
            dp[j] %= MOD;
        }
    }
    answer = dp[n] % MOD;
    return answer;
}