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

typedef long long ll;

ll n, b, x;
ll A[7][7]; ll arr[7][7];

void squared(ll a[][7], ll b[][7]) {
    ll temp[7][7];
    memset(temp, 0, sizeof(temp));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] = temp[i][j] % 1000;
            }
        }
    }
    memcpy(arr, temp, sizeof(arr));
}

void solve(ll x) {
    if (x == 1) {
        return;
    }
    if (x % 2 == 1) { 
        solve(x / 2);
        squared(arr, arr);
        squared(arr, A);
    }
    else { 
        solve(x / 2);
        squared(arr, arr);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> x;
            A[i][j] = x % 1000;
            arr[i][j] = A[i][j];
        }
    }
    solve(b);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}