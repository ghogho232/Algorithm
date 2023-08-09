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
    int n, k, cnt = 0;
    vector<int>v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (k == 0)
            break;
        else{
            cnt += (k / v[i]);
            k %= v[i];
        }
    }
    cout << cnt;
    return 0;
}