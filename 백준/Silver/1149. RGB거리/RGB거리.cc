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
    int dp[1000][3];
    int arr[3];
    int n;
    cin >> n;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[2];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}