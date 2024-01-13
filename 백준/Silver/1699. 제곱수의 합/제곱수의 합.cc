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
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int dp[100001];
    for(int i = 0; i <= 100000; i++){
        dp[i] = i;
    }
    cin >> n;
    for(int i = 4; i <= n; i++){
        for(int j = 2; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[n];
    return 0;
}