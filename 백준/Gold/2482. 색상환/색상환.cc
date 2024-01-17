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
#define MOD 1000000003
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    int dp[1001][1001];
    int ans;
    cin >> n >> k;
    for(int i = 0; i < 1001; i++){
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for(int i = 2; i < n; i++){
        for(int j = 2; j <= k; j++){
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }
    ans = (dp[n-3][k-1] + dp[n-1][k]) % MOD;
    cout << ans;
    return 0;
}