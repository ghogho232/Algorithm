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
const int MOD = 1000000007;

ll solve(ll b, ll ex){
    if(ex == 1) return b;
    if(ex % 2 == 1) return (b * solve(b,ex-1))%MOD;
    ll tmp = solve(b, ex/2);
    return (tmp * tmp) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    ll ans = 0;
    while(m--){
        int n, s;
        cin >> n >> s;
        ll tmp = (s * solve(n, MOD-2))%MOD;
        ans += (tmp%MOD);
    }
    cout << ans % MOD;
    return 0;
}