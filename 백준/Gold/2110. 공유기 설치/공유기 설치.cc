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

int arr[200001];
int dist[200001];
int ans = 0;

bool is_possible(int n, int c, int mid) {
    int cnt = 1;
    int p = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - p >= mid) { 
            cnt++;
            p = arr[i];
        }
    }

    return cnt >= c; 
}

void binary_search(int n, int c) {
    int left = 1, right = arr[n - 1] - arr[0];

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(n, c, mid)) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    binary_search(n, c);
    return 0;
}