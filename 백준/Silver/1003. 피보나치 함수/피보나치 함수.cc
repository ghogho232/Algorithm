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
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        vector<int> dp(a + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= a; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int zcnt = (a == 0) ? 1 : dp[a - 1]; 
        int ocnt = dp[a];

        cout << zcnt << " " << ocnt << "\n";
    }

    return 0;
}