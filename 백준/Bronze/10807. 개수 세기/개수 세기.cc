#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, v;
	vector<int>nums;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
	cin >> v;
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == v) {
			cnt++;
		}
	}
	cout << cnt;
}
