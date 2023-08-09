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
    int n, cnt = 0;
    cin >> n;
    vector<pair<int, int>>v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> b >> a;
        v[i] = { a,b };
    }
    sort(v.begin(), v.end());
    int end = v[0].first;
    for (int i = 1; i < n; i++) {
        if (end <= v[i].second) { 
            cnt++;
            end = v[i].first;
        }
    }

    cout << cnt+1;

    return 0;
}