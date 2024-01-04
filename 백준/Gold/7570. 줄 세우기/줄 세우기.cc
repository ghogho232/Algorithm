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
    int dp[1000001] = { 0 };
    int n;
    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dp[a] = dp[a - 1] + 1;
        ans = max(ans, dp[a]);
    }
    cout << n-ans;

    return 0;
}