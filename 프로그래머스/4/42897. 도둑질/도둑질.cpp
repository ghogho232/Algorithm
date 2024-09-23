#include <string>
#include <vector>

using namespace std;

int dp1[1000001];
int dp2[1000001];

int solution(vector<int> money) {
    int answer = 0;
    dp1[0] = money[0];
    dp1[1] = dp1[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2; i < money.size()-1; i++){
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    for(int i = 2; i < money.size(); i++){
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    answer = max(dp1[money.size()-2], dp2[money.size()-1]);

    return answer;
}