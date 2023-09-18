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
#include <iomanip>
#define ll long long

using namespace std;

int n, r, c, ans = 0;

void solve(int y, int x, int size){
    if(y == r && x == c){
        cout << ans;
        return;
    }
    if(r < y + size && r >= y && c < x + size && c >= x){
        solve(y, x, size / 2);
        solve(y , x + size/2, size / 2);
        solve(y + size / 2, x, size / 2);
        solve(y + size / 2, x + size / 2, size / 2);
    }
    else{
        ans += size * size;
    }       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> c;
    solve(0, 0, (1 << n));
    return 0;
}