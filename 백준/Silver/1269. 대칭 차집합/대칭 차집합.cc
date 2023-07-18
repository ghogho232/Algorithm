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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> vv(m);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vv[i];
    }
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    for (int i = 0; i < v.size(); i++) {
        if (binary_search(vv.begin(), vv.end(), v[i])) {
            cnt1++;
        }
    }
    for (int i = 0; i < vv.size(); i++) {
        if (binary_search(v.begin(), v.end(), vv[i])) {
            cnt2++;
        }
    }
    cout << vv.size() + v.size()-cnt1-cnt2;
    return 0;
}
