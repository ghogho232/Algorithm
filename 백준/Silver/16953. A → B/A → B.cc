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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll a, b;
    queue<pair<ll, int>> q;
	cin >> a >> b;

	q.push({ a, 0 });
	while (!q.empty()) {
		pair<ll, int> cur = q.front(); q.pop();
		if (cur.first == b) {
			cout << cur.second + 1 << '\n';
			return 0;
		}
		if (cur.first * 2 <= b){
			q.push({ cur.first * 2, cur.second + 1 });
		}
		if (cur.first * 10 + 1 <= b) {
			q.push({ cur.first * 10 + 1, cur.second + 1 });
		}
	}
	cout << -1;
	return 0;
}