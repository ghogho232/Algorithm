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
    int dp[1001];
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    for(int i = 4; i <= n; i++){
        dp[i] = min(dp[i-1],dp[i-3])+1;
    }
    if(dp[n]%2==0)
        cout << "CY";
    else
        cout << "SK";
    return 0;
}