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

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp1[1001];
    int dp2[1001];
    int arr[1001];
    int n, ans = 0;;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    fill(dp1, dp1 + 1001, 1);
    fill(dp2, dp2 + 1001, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            if(arr[i]>arr[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << ans;

    return 0;
}