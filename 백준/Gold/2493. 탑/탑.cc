#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<pair<int,int>> stk;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;

		while (!stk.empty()) {
			if (stk.top().second > h) {
				cout << stk.top().first << " ";
				break;
			}
			stk.pop();
		}

		if (stk.empty())
			cout << 0 << " ";
		stk.push({i,h});
	}
	return 0;
}
