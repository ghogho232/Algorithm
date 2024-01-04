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
    ll dp[91] = { 0 };
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 90; i++) {
        dp[i] = dp[i - 2] + dp[i-1];
    }
    cout << dp[n];
    return 0;
}