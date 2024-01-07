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
    while (n--) {
        ll dp[1000001];
        int a;
        cin >> a;
        dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 7;
        for (int i = 5; i <= a; i++) {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%1000000009;
        }
        cout << dp[a] % 1000000009 <<"\n";
    }
    return 0;
}