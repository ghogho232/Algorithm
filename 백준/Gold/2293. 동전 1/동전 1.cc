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

    int n, k;
    int dp[10001] = { 0 };
    int arr[101];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    cout << dp[k];
    return 0;
}