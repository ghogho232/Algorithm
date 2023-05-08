#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, x;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> x;
	sort(v.begin(), v.end());
	int left = 0;
	int right = n - 1;
	int cnt = 0;
	while (1) {
		if (left >= right)
			break;
		int sum = v[left] + v[right];
		if (sum == x) {
			cnt++;
			left++;
			right--;
		}
		else if (sum < x) {
			left++;
		}
		else
			right--;
	}
	cout << cnt;
	return 0;
}

