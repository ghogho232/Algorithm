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

const int INF = 1e9;
int dp[501][501];
int arr[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            arr[i] = arr[i - 1] + a;
        }

        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k - i; j++)
            {
                dp[j][i + j] = INF;
                for (int k = j; k < i + j; k++)
                {
                    dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[i + j] - arr[j - 1]);
                }
            }
        }
        cout << dp[1][k] << "\n";
    }

    return 0;
}