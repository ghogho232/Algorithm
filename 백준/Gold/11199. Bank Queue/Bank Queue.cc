#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	vector<int> time[48];
	priority_queue<int> customer;
	int N, T, c, t;
	int ans = 0;
	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >> c >> t;
		time[t].push_back(c);
	}


	for (int i = T - 1; i >= 0; i--) {
		for (int j = 0; j < time[i].size(); j++) {
			customer.push(time[i][j]);
		}
		if (!customer.empty()) {
			ans += customer.top();
			customer.pop();
		}
	}
	cout << ans << "\n";
}
