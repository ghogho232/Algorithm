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
int dp[41][41] = {0};
string str1, str2;

void print(int i, int j){
    if(i == 0 || j == 0)
        return;
    if(str1[i] == str2[j]){
        print(i-1, j-1);
        cout << str1[i];
    }
    else{
        if(dp[i][j-1] == dp[i][j])
            print(i, j-1);
        else
            print(i-1, j);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A, B;
    cin >> A >> B;
    int n = A.length();
    int m = B.length();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + A[i - 1];
            } else {
                if (dp[i - 1][j].length() > dp[i][j - 1].length()) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}