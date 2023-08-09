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

    int oil[100001], dist[100001];
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) 
        cin >> dist[i];
    for (int i = 1; i <= n; i++)
        cin >> oil[i];

    long long cur_min = oil[1];
    long long ans = 0;

    for (int i = 1; i < n; i++) {
        if (oil[i] < cur_min) {
            cur_min = oil[i];
        }
        ans += cur_min * dist[i - 1]; 
    }

    cout << ans;
    return 0;
}