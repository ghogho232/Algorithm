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
    int room = 0;

    vector<pair<int, int>>v;
    priority_queue<int, vector<int>, greater<int>>pq;

    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        v.push_back({ from,to });
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for (int i = 1; i < n; i++) {
        if (pq.top() <= v[i].first)
            pq.pop();
       pq.push(v[i].second);
    }
    cout << pq.size();

    return 0;
}