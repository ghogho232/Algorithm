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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque<int>d;
    int n, m, cnt=0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        d.push_back(i);
    }

    while (m--) {
        int a;
        cin >> a;
        int idx = 0;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] == a) {
                idx = i;
                break;
            }
        }
        if (idx <= d.size() / 2) {
            for (int i = 0; i < idx; i++) {
                d.push_back(d.front());
                d.pop_front();
                cnt++;
            }
            d.pop_front();
        }
        else {
            for (int i = 0; i < d.size()-idx; i++) {
                d.push_front(d.back());
                d.pop_back();
                cnt++;
            }
            d.pop_front();
        }
    }
    cout << cnt;
    return 0;
}