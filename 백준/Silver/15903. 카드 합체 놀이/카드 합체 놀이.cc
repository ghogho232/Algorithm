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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll>v(n);
    ll ans = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    while(m--){
        sort(v.begin(),v.end());
        ll tmp = v[0] + v[1];
        v[0] = v[1] = tmp;
    }
    for(int i = 0; i < n; i++){
        ans += v[i];
    }
    cout << ans;
    return 0;
}