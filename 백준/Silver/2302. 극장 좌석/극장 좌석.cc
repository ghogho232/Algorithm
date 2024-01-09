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

int dp[41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n, m;
    int ans = 1;
    int cur = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;
        ans *= dp[(v - cur) - 1];
        cur = v;
    }
    if (cur < n) {
        ans *= dp[n - cur];
    }
    cout << ans;

    return 0;
}