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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int>q;
    int t;
    cin >> t;
    while (t--) {
        queue<pair<int, int>>q;
        vector<int>v;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
            if (i == m) {
                q.push({ a,1 });
            }
            else
                q.push({ a,0 });
        }
        sort(v.begin(), v.end());

        int cnt = 0;
        while (true) {
            if (v.back() == q.front().first) {
                if (q.front().second == 1) {
                    cnt++;
                    break;
                }
                else {
                    v.pop_back();
                    q.pop();
                    cnt++;
                }
            }
            else {
                q.push({ q.front().first,q.front().second });
                q.pop();
            }
        }
        cout << cnt<<"\n";
    }
    return 0;
}