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
    int dp[31]={0,};
    dp[0]=1, dp[2] = 3;
    cin >> n;
    if(n%2 == 1){
        cout << 0;
        return 0;
    }
    for(int i = 4; i <= n ; i+=2){
        for(int j = 0; j < i-2; j+=2){
            dp[i] += dp[j]*2;
        }
        dp[i] += dp[i-2] * dp[2];
    }
    cout << dp[n];
    return 0;
}