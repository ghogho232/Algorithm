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

int dp[100001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a = 1;
    while (true) {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        }
        dp[0][0] = 987654321;
        dp[0][2] += dp[0][1];
        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][0];
            dp[i][1] = min(min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]),dp[i][0]) + dp[i][1];
            dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]),dp[i][1]) + dp[i][2];
        }
        cout << a << ". " << dp[n - 1][1] << "\n";
        a++;
    }
    
    return 0;
}