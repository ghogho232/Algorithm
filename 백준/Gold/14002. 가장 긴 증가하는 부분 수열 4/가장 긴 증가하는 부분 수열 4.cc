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

    int n;
    int arr[1001];
    int dp[1001];
    int idx[1001];
    int max_idx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp + 1001, 1);
    int ans = 0;
    vector<int>res;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
            max_idx = i;
        }
    }
    for (int i = max_idx; i > 0; i--) {
        if (ans == dp[i]) {
            res.push_back(arr[i]);
            ans--;
        }
    }
    cout << res.size() << "\n";

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    return 0;
}