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
#include <sstream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp1[101];
    int arr[101];
    vector<pair<int,int>>v;
    int n, ans = 0;;
    cin >> n;
    for(int i = 0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());
    fill(dp1, dp1 + 101, 1);

    for (int i = 1; i < v.size()+1; i++) {
        arr[i] = v[i - 1].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
        ans = max(ans, dp1[i]);
    }
    cout << n-ans;

    return 0;
}
