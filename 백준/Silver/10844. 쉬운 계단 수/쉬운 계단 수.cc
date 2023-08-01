#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[101][10];
    int n;
    cin >> n;
    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }  
    }
    long long cnt = 0;
    for (int i = 0; i < 10; i++) {
        cnt += dp[n][i];
        cnt %= 1000000000;
    }
    cout << cnt;
}