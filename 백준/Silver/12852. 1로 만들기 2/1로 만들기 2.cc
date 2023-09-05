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

const int MAXN = 1000001;
int dp[MAXN];
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;

    fill(dp, dp + x + 1, 1e9);
    dp[1] = 0;

    for (int i = 1; i <= x; i++) {
        if (i + 1 <= x && dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
            arr[i + 1] = i;
        }
        if (2 * i <= x && dp[2 * i] > dp[i] + 1) {
            dp[2 * i] = dp[i] + 1;
            arr[2 * i] = i;
        }
        if (3 * i <= x && dp[3 * i] > dp[i] + 1) {
            dp[3 * i] = dp[i] + 1;
            arr[3 * i] = i;
        }
    }

    cout << dp[x] << "\n";

    int idx = x;
    while (idx > 0) {
        cout << idx << " ";
        idx = arr[idx];
    }

    return 0;
}