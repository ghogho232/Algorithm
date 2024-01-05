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
    cin >> n;
    vector<pair<int, int>> arr(n+2);
    vector<int>dp(n+2);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].first + i > n)
            dp[i] = dp[i + 1];
        else {
            dp[i] = max(dp[i + 1], dp[i + arr[i].first] + arr[i].second);
        }
    }

    cout << dp[0];
    return 0;
}