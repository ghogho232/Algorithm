#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	stack<long long> idx;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		while (!idx.empty() && t[idx.top()] < t[i]) {
			ans += i - idx.top() + 1;
			idx.pop();
		}
		if (!idx.empty()) {
			ans += i - idx.top() + 1;
		}
		idx.push(i);
	}

	cout << ans << "\n";
	return 0;
}