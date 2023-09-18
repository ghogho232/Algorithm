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
    int n;
    int dp[1001];
    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 3;
    cin >> n;
    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i - 2]) % 10007;
    }
    cout << dp[n];

    
}