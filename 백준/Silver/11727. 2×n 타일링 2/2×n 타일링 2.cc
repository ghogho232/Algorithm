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
    int dp[10001] = {0};
    dp[1] = 1, dp[2] = 3;
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }
    cout << dp[n];
    return 0;
}