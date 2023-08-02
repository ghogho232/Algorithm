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

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char str1[1001], str2[1001];
    int dp[1001][1001] = { 0 };
    cin >> str1 >> str2;
    for (int i = 0; i < strlen(str1); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[strlen(str1)][strlen(str2)];
    return 0;
}