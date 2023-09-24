#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int ans = 999999;
        int n;
        cin >> n;
        vector<string> str(n);
        
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }

        if (n > 32) {
            cout << 0 << "\n";
        } 
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        int cnt = 0;
                        if (i == j || j == k || i == k) {
                            continue;
                        }
                        for (int x = 0; x < 4; x++) {
                            if (str[i][x] != str[j][x]) cnt++;
                            if (str[j][x] != str[k][x]) cnt++;
                            if (str[i][x] != str[k][x]) cnt++;
                        }
                        ans = min(cnt, ans);
                    }
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}