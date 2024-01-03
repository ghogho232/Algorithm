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
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int from = a * 100 + b;
        int to = c * 100 + d;
        v.push_back({ from, to });
    }
    sort(v.begin(), v.end());

    int deadline = 301;
    if (v[0].first > 301) {
        cout << 0;
        return 0;
    }

    int idx = 0;
    int tmp = 0;

    while (deadline <= 1130) {
        bool updated = false;

        // idx부터 시작하여 deadline 이하의 값 중 가장 큰 v[i].second를 찾음
        while (idx < n && v[idx].first <= deadline) {
            if (v[idx].second > tmp) {
                tmp = v[idx].second;
                updated = true;
            }
            idx++;
        }

        if (!updated)
            break;

        deadline = tmp;
        ans++;
    }

    if (deadline > 1130)
        cout << ans;
    else
        cout << 0;

    return 0;
}