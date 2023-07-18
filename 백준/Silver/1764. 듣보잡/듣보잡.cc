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

    int n,m;
    int cnt = 0;
    cin >> n>>m;
    vector<string> v(n);
    vector<string>ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        if (binary_search(v.begin(), v.end(), a)) {
            cnt++;
            ans.push_back(a);
        }
    }
    cout << cnt << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}