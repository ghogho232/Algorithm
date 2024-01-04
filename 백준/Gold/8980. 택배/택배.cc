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

struct box {
    int from, dest, num;
};

bool cmp(box a, box b) {
    return a.dest < b.dest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c, m;
    int ans = 0;
    cin >> n >> c >> m;    

    vector<box>v; 
    vector<int>capacity(n + 1, c);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        box B;
        B.from = a, B.dest = b, B.num = c;
        v.push_back(B);
    }
    sort(v.begin(), v.end(), cmp);

    for (auto b : v) {
        int min = capacity[b.from];
        for (int i = b.from + 1; i<b.dest; i++) {
            if (min > capacity[i])
                min = capacity[i];
        }
        int num = b.num;
        if (min < num)
            num = min;
        ans += num;
        for (int i = b.from; i < b.dest; i++) {
            capacity[i] -= num;
        }
    }
    cout << ans;

    return 0;
}