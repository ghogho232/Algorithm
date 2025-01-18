#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
#define INF 987654321

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cin >> m;
    
    sort(v.begin(), v.end());

    int left = 0, right = v[n - 1];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long tmp = 0;

        for (int i = 0; i < n; i++) {
            tmp += min(v[i], mid);  
        }

        if (tmp > m) {
            right = mid - 1;  
        } else {
            ans = mid;        
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}