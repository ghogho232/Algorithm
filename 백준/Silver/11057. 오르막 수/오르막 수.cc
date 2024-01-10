#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1001][11];
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%10007;
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += dp[n][i];
    }
    cout << ans%10007;
    return 0;
}