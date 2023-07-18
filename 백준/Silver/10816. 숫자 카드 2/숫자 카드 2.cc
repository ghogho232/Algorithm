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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        int count = 0;
        if (binary_search(v.begin(), v.end(), query)) {
            auto lower = lower_bound(v.begin(), v.end(), query);
            auto upper = upper_bound(v.begin(), v.end(), query);
            count = upper - lower;
        }
        cout << count << " ";
    }

    return 0;
}