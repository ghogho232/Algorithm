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
    long long a, b, c, ans;
long long recur(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;
    ans = recur(b / 2) % c;
    if (b % 2 == 0) {
        return ans * ans % c;
    }
    else
        return ans * ans % c * a % c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    cout << recur(b);
    return 0;
}