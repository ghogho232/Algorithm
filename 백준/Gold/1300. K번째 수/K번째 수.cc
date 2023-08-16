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
    int n, k, ans;
    cin >> n >> k;
    int left = 1;
    int right = k;
    while (left <= right) {
        long long cnt = 0;
        int mid = (left + right) / 2;
        for (int i = 1; i <= n; i++)
            cnt += min(mid / i, n);
        if (cnt < k)
            left = mid + 1;
        else {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}