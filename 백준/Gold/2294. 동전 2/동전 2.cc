#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
#define MAX INT_MAX
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[101];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int dp[10001];
    fill(dp, dp + 10001, 987654321);
    dp[0] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] <= i && dp[i - arr[j]] + 1 < dp[i]) {
                dp[i] = dp[i - arr[j]] + 1;
            }
        }
    }
    if (dp[k] == 987654321) {
        cout << -1;
    } else {
        cout << dp[k];
    }

    return 0;
}