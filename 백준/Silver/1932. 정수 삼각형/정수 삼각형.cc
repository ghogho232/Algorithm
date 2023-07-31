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
    int dp[501][501];
    int n,ans=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) 
            cin >> dp[i][j];
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(dp[n][i], ans);
    cout << ans;
    return 0;
}